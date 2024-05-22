# ZombieComing

## Compiling and Run
Install raylib from [raylib.com](https://www.raylib.com/) before compiling and running (recommend installing in the default directory `C:/raylib/`).

### Shell Script
1.  go to `C:/raylib/w64devkit`open the `w64devkit.exe` .
2.  change directory using `cd %file location%`.
3.  run `./BuildAndRun.sh` and game should run after finish compiling.
### Manually
1. go to `C:/raylib/w64devkit`open the `w64devkit.exe` . 
2. change directory using `cd %file location%/src` .
3. compiling using `gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c -lraylib -lgdi32 -lwinmm`
4. run using `./ZombieComing` to start the game.
## Controlling
 - Navigate Menu: `using mouse to navigate and  click`
 - Player Movement: `press '↑', '↓', '←', '→' `
 - Normal Attack: `press '_space_'`
 - Debugging
	 - spawn zombie: `press 'S' `

