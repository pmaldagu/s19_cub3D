# cub3d

19 Coding School project

>This project is inspired by the world-famous eponymous 90’s game, which
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.

## Status

Succes: 103%

## How to

Install required dependencies for minilibx (debian based linux distro):
```
sudo apt update
sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```
Compile the project:
```
make
```
Compile with bonus
```
make bonus
```
Delete all objects:
```
make clean
```
Delete all objects and the binary:
```
make fclean
```
Run the project:
```
./cub3d [MAP FILE PATH]
```


## Ressources

- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Event Types](https://tronche.com/gui/x/xlib/events/types.html)
