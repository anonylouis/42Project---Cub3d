# 42Project---Cub3d

## Description

The [ray-casting](https://en.wikipedia.org/wiki/Ray_casting) is one of the first technique used in videogames to render 3D scenes to 2D images.
Ray casting use the link between the distance to a wall and how high this wall has to be drawn on the screen.  
- **shortest is the distance to the wall, the higher it will be drawn**

The cub3D project is a simple 3D videogame realised with the used of raycasting.

## Utilisation

The program just takes one argument, the path to the map :
``` ./cub3D [path/to/map.cub]``` or ```./cub3D_bonus [path/to/map.cub]```

A valid map must have the *.cub* extension and must contain some informations :
- The 4 paths of the 4 sides of a wall
- The colors to use to draw the ceiling and the floor, in RGB values.
- The map in itself, with some rules
  - "1" represents a wall
  - "0" represents an empty space
  - N/S/E/W represents the player's starting position and orientation (**N**orth/**S**outh/**E**ast/**W**est)
  - " " spaces are available but **the map must be close/surrounded by walls**  

Example of a valid map :  
![valid_map.png](https://github.com/anonylouis/42Project---Cub3d/blob/master/images/valid_map.png)  

## Commands

In game commands :
- W/A/S/D to move
- Left and right arrow to move the camera
- Esc (or red cross) to close the windows`

## Bonus

The bonus executable add some features :
- "D" represents a door in the mapfile (open/close it in game with E)
- "B" represents a boost in the mapfile (you can take it with R)
- There is a minimap
- The mouse can change the camera orientation

## Images

Here are some screenshots from my game :  
![cub3D.png](https://github.com/anonylouis/42Project---Cub3d/blob/master/images/Cub3D.png)

