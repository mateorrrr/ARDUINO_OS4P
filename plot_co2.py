"""
plot_co2.py - plot CO2 (ppm) against time (s) from DATA.CSV.

The log can hold one or several recordings: every time the clock jumps back
(e.g. from 340 s to 10 s) a new recording starts. With several recordings,
only the longest one is plotted; with one recording, all of it is plotted.

Usage:  python plot_co2.py [DATA.CSV]      (needs: pip install pandas matplotlib)
"""
import sys
import pandas as pd
import matplotlib.pyplot as plt

path = sys.argv[1] if len(sys.argv) > 1 else "DATA.CSV"

# 1. Read the data
df = pd.read_csv(path)
df.columns = ["time_s", "co2_ppm"]
if df.empty:
    sys.exit(f"No data rows in {path}")

# 2. Split into recordings: new recording whenever time goes backwards
#    (a file with one recording simply gets recording number 1 everywhere)
df["recording"] = (df["time_s"].diff() < 0).cumsum() + 1
n_recordings = df["recording"].nunique()

# 3. Keep only the longest recording (the one with the most data points)
if n_recordings == 1:
    longest = 1
    rec = df
    print("File contains 1 recording")
else:
    longest = df["recording"].value_counts().idxmax()
    rec = df[df["recording"] == longest]
    print(f"File contains {n_recordings} recordings, using the longest")

print(f"Recording #{longest}: {len(rec)} points, "
      f"{rec.time_s.min()}-{rec.time_s.max()} s")
print(f"CO2: min {rec.co2_ppm.min()}  mean {rec.co2_ppm.mean():.1f}  "
      f"max {rec.co2_ppm.max()} ppm")

# 4. Plot
fig, ax = plt.subplots(figsize=(10, 5))
fig.patch.set_facecolor("#fcfcfb")
ax.set_facecolor("#fcfcfb")

ax.plot(rec["time_s"], rec["co2_ppm"], color="#2a78d6", lw=2)

# mark the highest reading after the start-up period
after_start = rec[rec["co2_ppm"] != 500]
if after_start.empty:            # recording contains only start-up values
    after_start = rec
peak = after_start.loc[after_start["co2_ppm"].idxmax()]
ax.plot(peak.time_s, peak.co2_ppm, "o", color="#2a78d6", ms=7, mec="#fcfcfb", mew=2)
ax.annotate(f"{peak.co2_ppm:.0f} ppm at {peak.time_s:.0f} s", (peak.time_s, peak.co2_ppm),
            xytext=(-10, 8), textcoords="offset points", ha="right",
            fontsize=9, color="#0b0b0b")

title = "CO2 concentration over time"
if n_recordings > 1:
    title += " (longest recording)"
ax.set_title(title, loc="left",
             fontsize=13, color="#0b0b0b")
ax.set_xlabel("Time (s)", color="#52514e")
ax.set_ylabel("CO2 (ppm)", color="#52514e")
ax.grid(axis="y", color="#e4e3df", lw=0.8)
for side in ("top", "right"):
    ax.spines[side].set_visible(False)
for side in ("left", "bottom"):
    ax.spines[side].set_color("#c3c2b7")
ax.tick_params(colors="#52514e")
ax.set_xlim(left=0)
fig.tight_layout()

fig.savefig("co2_plot.png", dpi=150)
print("saved co2_plot.png")
plt.show()
