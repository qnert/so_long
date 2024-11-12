# so_long

## Project Overview

The `so_long` project is a simple 2D game created in C using MiniLibX. In this game, the player’s goal is to collect all collectibles on a custom map and then reach the exit. You can create a theme of your choice for the characters and environment.

---

## Key Requirements

- **Programming Language**: The project is written in C and must follow Norm standards.
- **Memory Management**: All dynamically allocated memory must be properly freed, and no memory leaks are tolerated.
- **Makefile**: The project must include a Makefile with at least the rules: `all`, `clean`, `fclean`, and `re`. It should use the `-Wall -Wextra -Werror` flags and should not relink.
- **Forbidden Elements**: Global variables and external libraries (other than MiniLibX and, if allowed, `libft`) are not permitted.

---

## Game Requirements

- **Goal**: The player’s objective is to collect all collectibles and reach the exit on a 2D map.
- **Movement**: The player moves using W, A, S, D keys (or ZQSD/arrows), with each move displayed in the terminal.
- **Boundaries**: The player cannot move through walls and must remain within the map’s boundaries.
- **Graphics**: The game must be displayed in a MiniLibX window, supporting smooth window management (e.g., resizing, minimizing).
- **Exit on Command**: The game must close cleanly when the ESC key is pressed or the window’s close button is clicked.

---

## Map Specifications

- **Format**: The map should be provided in a `.ber` file format and follow a specific structure.
- **Elements**:
  - `0`: Empty space
  - `1`: Wall
  - `C`: Collectible
  - `E`: Exit
  - `P`: Starting position of the player
- **Rules**:
  - The map must be rectangular, fully enclosed by walls, and contain at least one `E`, `C`, and `P`.
  - Each map must have only one starting position (`P`) and one exit (`E`).
  - Any misconfiguration (e.g., duplicate `E` or `P`, missing walls) should result in a clean program exit with an error message.

### Example Map

```plaintext
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

###Usage
```bash
make
```
```bash
./so_long path/to/map.ber
```
