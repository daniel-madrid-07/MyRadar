# My Radar 2 🛩️

**An air traffic control visualization system with real-time aircraft tracking and tower defense mechanics** — Monitor and manage multiple aircraft routes across a radar display while detecting collisions with defense tower coverage zones.

## Overview

My Radar 2 is a CSFML-based graphical simulation that visualizes aircraft movements across a radar display. The system reads configuration files defining aircraft flight paths and radar towers, then displays animated aircraft moving from departure to arrival points. The application includes real-time collision detection, visual tower coverage zones, and an elapsed time counter.

## Features

🛩️ **Flight Operations:**
- ✈️ **Multiple Aircraft** - Handle dozens of simultaneously active aircraft
- 📍 **Waypoint Navigation** - Aircraft travel from departure to arrival coordinates
- ⏱️ **Delayed Activation** - Aircraft spawn after configurable delay periods
- 🎯 **Speed Control** - Each aircraft has independent speed parameters
- 💥 **Collision Detection** - Detects aircraft hits in tower detection zones

## Tower Defense:**
- 🗼 **Radar Towers** - Defend against aircraft entering coverage zones
- 📡 **Visual Coverage Zones** - Display tower detection radius on screen
- 🎨 **Dynamic Rendering** - Toggle hitbox visualization for debugging

## Visualization:**
- 🖼️ **Animated Background** - Radar-style display background
- ⏲️ **Elapsed Time Display** - Real-time countdown/timer overlay
- 📊 **Hit Status Tracking** - Visual feedback for destroyed aircraft
- 🔊 **Background Music** - Atmospheric audio during simulation

## Architecture

```
MyRadar2/
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
│   ├── plane.png            # Aircraft sprite
│   ├── tower.png            # Tower sprite
│   ├── music.mp3            # Background music
│   └── font.ttf             # Text font
└── Makefile
```

## Data Structures

### Core Types
- **aircraft_t** - Aircraft with departure/arrival points, speed, delay, position tracking, and collision state
- **tower_t** - Radar tower with position and detection radius
- **game_t** - Global game state (window, clock, aircraft list, tower list, rendering data)
- **vector2f_t** - 2D floating-point position/velocity vectors
- **aircraft_data_t** - Parsed aircraft configuration from file
- **tower_data_t** - Parsed tower configuration from file

## Building

```bash
# Build the application
make

# Clean object files
make clean

# Remove all build artifacts
make fclean

# Rebuild from scratch
make re

# Build with debug symbols
make debug

# Run with configuration file
./my_radar path/to/config.txt
```

### Requirements
- **Compiler**: GCC with C99 support
- **Dependencies**:
  - CSFML libraries (graphics, system, window, audio)
  - libm (math library)
  - Standard C libraries

## Configuration File Format

### Aircraft Specification
```
A <x1> <y1> <x2> <y2> <speed> <delay>
```
- `x1, y1` - Departure coordinates (pixels)
- `x2, y2` - Arrival coordinates (pixels)
- `speed` - Movement speed (pixels per unit time)
- `delay` - Frames before aircraft becomes active

### Tower Specification
```
T <x> <y> <radius>
```
- `x, y` - Tower center position (pixels)
- `radius` - Detection zone radius (pixels)

### Example Configuration
```
A 100 100 800 600 5 10
A 200 50 900 400 3 5
T 400 300 100
T 600 500 150
```

## Usage

```bash
./my_radar <config_file>
./my_radar -h          # Display help information
```

### Runtime Controls
- **Close Window** - Exit the application
- **Visual Debug** - Press keys to toggle sprite/hitbox display (implementation dependent)

## How It Works

1. **Configuration Loading** - Parse aircraft and tower definitions from file
2. **Sprite Creation** - Load and position aircraft and tower graphics
3. **Simulation Loop** - Update aircraft positions each frame
4. **Collision Check** - Test if any aircraft position overlaps tower zones
5. **Rendering** - Draw background, towers, aircraft, and timer
6. **Output** - Display destroyed aircraft markers and elapsed time

## Project Stats

- **Lines of Code**: ~536 (core game files)
- **Project Size**: ~9.8MB (includes assets)
- **Language**: C (C99 standard)
- **Graphics Library**: CSFML
- **Build System**: Make
- **Asset Format**: PNG sprites, JPG background, MP3 audio

## Technical Highlights

✨ **Key Features:**
- **Linked List Management** - Efficient aircraft and tower storage
- **Collision Detection** - Distance-based radius checking
- **Delta Time Rendering** - Frame-rate independent movement
- **File Parsing** - Robust configuration file handling
- **Global Game State** - Centralized state management
- **Memory Efficiency** - Proper allocation and cleanup

## Game Flow

1. **Initialization Phase** - Load window, music, assets, and parse config
2. **Aircraft Spawn** - Activate aircraft after delay period
3. **Movement Phase** - Update aircraft positions toward destination
4. **Detection Phase** - Check for tower zone collisions
5. **Rendering Phase** - Draw current game state
6. **Cleanup** - Free all allocated resources on exit

## Features

- Support for multiple simultaneous aircraft routes
- Real-time visual feedback for collisions
- Configurable tower defense zones
- Elapsed time tracking
- Background music and audio
- High-resolution graphics rendering

## Notes

- The application uses a global `game_t` pointer for state management
- Aircraft movement is linear interpolation between waypoints
- Tower coverage is circular with configurable radius
- Configuration files must follow strict format (A/T prefixes)
- The timer displays total elapsed simulation time

## Credits

Epitech Graphical Programming Project (2025)

---

**Project Type**: Simulation / Graphics Programming  
**Difficulty**: Intermediate  
**Key Concepts**: File Parsing, Spatial Simulation, Collision Detection, Real-Time Rendering
