# MyRadar — technical reference

## Architecture

```
MyRadar/
├── src/                       # Main source files
│   ├── my_radar.c            # Main application loop
│   ├── init.c                # Game/window initialization
│   ├── plane.c               # Aircraft data parsing & creation
│   ├── tower.c               # Tower data parsing & creation
│   ├── graphics.c            # Rendering pipeline
│   ├── background.c          # Background sprite management
│   ├── help.c                # Help menu & usage info
│   └── cleanup.c             # Resource deallocation
├── include/
│   └── my.h                  # Main header with data structures
├── extras/
│   ├── my_printf/            # Custom printf implementation
│   └── other_functions/      # String utilities
├── content/                  # Game assets
│   ├── background.jpg        # Radar display background
│   ├── plane.png              # Aircraft sprite
│   ├── tower.png              # Tower sprite
│   ├── music.mp3               # Background music
│   └── font.ttf               # Text font
└── Makefile
```

### Core data types

- **aircraft_t** — aircraft with departure/arrival points, speed, delay, position tracking, and collision state
- **tower_t** — radar tower with position and detection radius
- **game_t** — global game state (window, clock, aircraft list, tower list, rendering data)
- **vector2f_t** — 2D floating-point position/velocity vectors
- **aircraft_data_t** — parsed aircraft configuration from file
- **tower_data_t** — parsed tower configuration from file

## Configuration file format

Aircraft specification:
```
A <x1> <y1> <x2> <y2> <speed> <delay>
```
- `x1, y1` — departure coordinates (pixels)
- `x2, y2` — arrival coordinates (pixels)
- `speed` — movement speed (pixels per unit time)
- `delay` — frames before aircraft becomes active

Tower specification:
```
T <x> <y> <radius>
```
- `x, y` — tower center position (pixels)
- `radius` — detection zone radius (pixels)

Example configuration:
```
A 100 100 800 600 5 10
A 200 50 900 400 3 5
T 400 300 100
T 600 500 150
```

## Running

```bash
./my_radar <config_file>
./my_radar -h          # Display help information
```

Runtime controls:
- Close window — exit the application
- Visual debug — press keys to toggle sprite/hitbox display (implementation dependent)

## How it works

1. Configuration loading — parse aircraft and tower definitions from file
2. Sprite creation — load and position aircraft and tower graphics
3. Simulation loop — update aircraft positions each frame
4. Collision check — test if any aircraft position overlaps tower zones
5. Rendering — draw background, towers, aircraft, and timer
6. Output — display destroyed aircraft markers and elapsed time

## Notes

- The application uses a global `game_t` pointer for state management
- Aircraft movement is linear interpolation between waypoints
- Tower coverage is circular with configurable radius
- Configuration files must follow strict format (A/T prefixes)
- The timer displays total elapsed simulation time
