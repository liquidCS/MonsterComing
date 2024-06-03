# ZombieComing
![DemoGIF](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/DemoGIF.gif)
## Game Theme
You must use the special skills and powers of your chosen characters to navigate through swarms of zombies, whether it be the Warrior's powerful physical attacks, the Witch's ethereal ranged attacks, or the Ninja's quick-accurate blows.
## Meet the Characters
![warrror](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/warrior.gif)![ninja](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/ninja.gif)![witch](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/witch.gif)![Zombie1](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/zombie1.gif)![zombie2](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/zombie2.gif)![slime](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/slime.gif)![bat](https://raw.githubusercontent.com/liquidCS/MonsterComing/main/Resources/bat.gif)
### Warrior
- Role: Frontline fighter with powerful melee attacks.
- Normal Attack: Executes swift, lethal strikes against zombies within range.
- Special Attack: Unleashes a devastating blow that can decimate multiple zombies at once.
### Witch
- Role: Mystical spellcaster with long-range magical attacks.
- Normal Attack: Casts potent spells to eliminate zombies from a distance.
- Special Attack: Conjures a powerful spell that causes massive damage over a wide area.
### Ninja
- Role: Stealthy and agile assassin.
- Normal Attack: Quick, precise strikes that incapacitate zombies swiftly.
- Special Attack: Performs a series of rapid attacks, dealing heavy damage to any nearby zombies.

## Controlling
 - Navigate Menu: `using mouse to navigate and click`
 - Player Movement: `press '↑', '↓', '←', '→' `
 - In Game Menu: `press 'M'`
 - Attack
 	- Normal Attack: `press '_SPACE_'`
 	- Special Attack: `press '_LEFT_SHIFT_'`
 - Debugging
	 - spawn zombie: `press 'S' `

## Work Division
| Members | Github ID | Work |
|--------|-----------|------|
| 412410083 | liquidCS | Most of the structers and codes |
| 412410018 | alien4321 | All the Arts |
| 412410036 | Sheeesh77 | Zombie Attacks |
| 412410039 | carolll39 | Works on witch.c |
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
3. compiling using `gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainGameGUI.c inGameMenu.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c coins.c saveHandler.c gameMath.c zombieWaves.c -lraylib -lgdi32 -lwinmm`
4. run using `./ZombieComing` to start the game.


