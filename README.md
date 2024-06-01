# ZombieComing

## Work Division
| Members | Github ID | Work |
|--------|-----------|------|
| 412410083 | liquidCS | Most of the structers and codes |
| 412410018 | alien4321 | All the Arts |
| 412410036 | Sheeesh77 | Zombie Attacks |
| 412140039 | carolll39 | Works on witch.c |
| 411125028 | JFKyiasd | Works on ninja.c |




## Compiling and Run
Install raylib from [raylib.com](https://www.raylib.com/) before compiling and running (recommend installing in the default directory `C:/raylib/`).

### Shell Script
1.  go to `C:/raylib/w64devkit`open the `w64devkit.exe` .
2.  change directory using `cd %file location%`.
3.  run `./BuildAndRun.sh` and game should run after finish compiling.
### Manually
1. go to `C:/raylib/w64devkit`open the `w64devkit.exe` . 
2. change directory using `cd %file location%/src` .
3. compiling using `gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainGameGUI.c inGameMenu.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c coins.c saveHandler.c gameMath.c -lraylib -lgdi32 -lwinmm  `
4. run using `./ZombieComing` to start the game.
## Controlling
 - Navigate Menu: `using mouse to navigate and click`
 - Player Movement: `press '↑', '↓', '←', '→' `
 - In Game Menu: `press 'M'`
 - Normal Attack: `press '_SPACE_'`
 - Special Attack: `press '_LEFT_SHIFT_'`
 - Debugging
	 - spawn zombie: `press 'S' `

