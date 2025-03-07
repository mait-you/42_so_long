# 42_so_long

## Overview
`so_long` is a simple 2D game developed as part of the 42 curriculum. The project focuses on creating a small 2D game where a player navigates through a map, collects items, and reaches the exit while avoiding obstacles.

## Game Description
In this game, the player's goal is to collect all collectibles present on the map and then reach the exit to win the game. The player can move in four directions (up, down, left, right) and must strategically navigate through the map.

## Technical Stack
- Language: C
- Graphics Library: MinilibX
- Build System: Make

## Usage
Run the executable with a map file:
```bash
./so_long maps/map1.ber
```

## Map Format
Maps are defined in `.ber` files and must follow these rules:
- `0` for an empty space
- `1` for a wall
- `C` for a collectible
- `E` for an exit
- `P` for the player's starting position

Example:
```
1111111111111
10C10000000C1
1011011111101
1P0001E000001
1111111111111
```

## Project Structure
- `bonus/`: Additional features
- `libft/`: Custom C library
- `mandatory/`: Core game functionalities
- `maps/`: Map files for the game
- `textures/`: Game sprites and textures

## Controls
- `W` or `↑`: Move up
- `A` or `←`: Move left
- `S` or `↓`: Move down
- `D` or `→`: Move right
- `ESC`: Quit the game

## Bonus Features
Additional features included in the bonus part:
- Enemy patrols
- Animated sprites
- Move counter displayed on the screen


## License
This project is part of the 42 curriculum.
