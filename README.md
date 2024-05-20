# ZombieComing

## Compiling
1. Install raylib from [raylib.com](https://www.raylib.com/). After installing go to `C:/raylib/w64devkit`open the `w64devkit.exe` . 
2. change directory using `cd %file location%/src` 
3. compiling using `gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c -lraylib -lgdi32 -lwinmm`
