 #!/bin/bash
rm src/ZombieComing.exe 
cd src
gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainGameGUI.c inGameMenu.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c coins.c -lraylib -lgdi32 -lwinmm 
./ZombieComing