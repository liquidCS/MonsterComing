 #!/bin/bash
cd src
gcc -o ZombieComing.exe ZombieComing.c mainGame.c menu.c menuPages.c mainPlayer.c zombies.c inputHandler.c warrior.c ninja.c witch.c coins.c -lraylib -lgdi32 -lwinmm 
./ZombieComing