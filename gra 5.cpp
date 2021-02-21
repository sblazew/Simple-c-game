// Very simple game written to pracitce classes. 
// Move @ between obstacles to get points.

#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Game.h"



int main() {

	srand(time(NULL));
	
	Game start;
	start.menu();
	
	while (start.startGame) {

		start.runGame();
		
		start.playAgain();
	}
}