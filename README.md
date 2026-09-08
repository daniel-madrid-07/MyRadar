<div align="center">

# MyRadar

**An air traffic control visualization with real-time aircraft tracking and collision detection.**

</div>

---

## What it does

MyRadar is a CSFML-based graphical simulation that visualizes aircraft movements across a radar
display. It reads configuration files defining aircraft flight paths and radar towers, then
displays animated aircraft moving from departure to arrival points, with real-time collision
detection against tower coverage zones and an elapsed-time counter.

## Features

- **Flight operations** — dozens of simultaneous aircraft, waypoint navigation, delayed activation, independent speed per aircraft
- **Collision detection** — detects aircraft entering tower detection zones in real time
- **Tower coverage** — radar towers with visualized circular detection radius
- **Visualization** — animated radar-style background, elapsed time overlay, hit status feedback, background music

## Installation / Usage

```bash
make                        # Build
./my_radar <config_file>    # Run with a flight/tower configuration
```

Requires GCC (C99) and the CSFML libraries (graphics, system, window, audio). Configuration file
format, data structures, and full architecture: **[docs/REFERENCE.md](docs/REFERENCE.md)**.

## Tech stack

C (C99), CSFML, Make

## License

School project — see [LICENSE](LICENSE)
