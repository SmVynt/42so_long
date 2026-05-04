# So Long

A small **2D top-down collect-and-escape** game for **42**, built with **MLX42** (Codam). Read a `.ber` map, collect every pickup, reach the exit, and avoid enemies.

<img src="textures/screen_won.png" alt="You won" width="256" height="128" />

## Requirements

- C compiler (`cc`), `make`, `cmake` (used once to build MLX42)
- Graphics deps for MLX42 on Linux: GLFW, OpenGL (e.g. `libglfw3-dev`, `libgl1-mesa-dev` or equivalent)

## Build

```bash
make
```

## Run

```bash
./so_long maps/map.ber
```

The map must be a rectangle of `1` (wall), `0` (floor), `P` (player), `C` (collectible), `E` (exit), with exactly one `P`, one `E`, at least one `C`, and a valid path to collect all `C` and reach `E`.

## Controls

| Key | Action |
| --- | --- |
| **W A S D** / **Arrow keys** | Move |
| **Esc** | Quit |
| **R** | Restart |

## Credits

MLX42 is [Codam’s MLX42](https://github.com/codam-coding-college/MLX42).
