#include "Game.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

void Game::menu() {
	system("cls");
	std::cout << "-----------------------------------------------\n";
	std::cout << "Avoid obstacles\n";
	std::cout << "Press 'a' to move left, press 'd' to move right" << std::endl <<"Avoid obstacles\n";
	std::cout << "-----------------------------------------------\n";
	std::cout << "Press s to start\n";
	std::cout << "Press any key to quit\n";
	
	char key;
	key = _getch();
		switch (key) {
		case 's':
			Game::startGame = true;
			break;
		default:
			Game::startGame = false;
			break;
		}
}

void Game::show(char tab[][11]) {										//function drawing a map
	std::cout << "Points: " << points << std::endl;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++)
			std::cout << tab[i][j];
		std::cout << std::endl;
	}
}

void Game::countPoints() {
	points++;
}

int Game::mapAnimate(char tab[][11], int size, int bank) {				//function generating a map
	//to avoid generating blocked canyon
	for (int y = size - 1; y > 0; y--) {

		if (y == 1) {													//generating banks at the top of the screen
			int leftBank = rand() % 6;
			while ((leftBank - bank) > 1 || (leftBank - bank) < -1) {	//gaps between banks cant be bigger than one char or player will go out of the map
				leftBank = rand() % 6;
			}

			bank = leftBank;

			for (int i = 0; i < 10; i++) {
				tab[0][i] = ' ';
			}
			tab[0][leftBank] = '|';
			tab[0][leftBank + 4] = '|';
		}									//moving rows down
		for (int x = 0; x < 10; x++) {
			tab[y][x] = tab[y - 1][x];
		}
	}
	if (tab[10][x] == ' ')
		tab[10][x] = '@';					//player
	else {									//if wall hits player - Game over
		tab[10][x] = 'X';
		Game::play = false;
	}
	return bank;
}

int Game::moveLeft(char map[][11]) {		//logic for moving left
	int x2 = x - 1;
	if (map[y][x2] == ' ') {
		map[y][x] = ' ';
		map[y][x2] = '@';
		x = x2;
		return x;
	}
	else {							//if collision
		map[y][x2] = 'X';
		map[y][x] = ' ';
		system("cls");
		Game::show(map);
		std::cout << "GAME OVER\n" << std::endl;
		Game::play = false;
	}
}

int Game::moveRight(char map[][11]) {				//logic for moving right
	int x2 = x + 1;
	if (map[y][x2] == ' ') {
		map[y][x] = ' ';
		map[y][x2] = '@';
		x = x2;
		return x;
	}
	else {							//if collision
		map[y][x2] = 'X';
		map[y][x] = ' ';
		system("cls");
		Game::show(map);
		std::cout << "GAME OVER\n" << std::endl;
		Game::play = false;
	}
}

void Game::playAgain() {
	std::cout << "\nPlay again (y / n)?\n";
	char answer = _getch();
	switch (answer) {
	case 'y':
		startGame = true;
		Game::clearMemory();
		break;
	case 'n':
		system("cls");
		std::cout << "Have a nice day!\n";
		std::cout << "\nGame closed.\n";
		Game::startGame = false;
		break;
	default:
		system("cls");
		break;
	}
}

void Game::clearMemory(){				//sets default values before running the game
	system("cls");
	x = 4;
	y = 10;
	points = 0;
	previousBank = 1;
	char tempMap[11][11] = {
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    ",
		" |   |    "
	};
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			map[i][j] = tempMap[i][j];
	play = true;
}

void Game::steering() {
	
	if (_kbhit())
		switch (_getch()) {
		case'd': {
			Game::moveRight(Game::map);
			break;
		}
		case'a': {
			Game::moveLeft(Game::map);
			break;
		}
	}
}

void Game::runGame() {			//main function to play the game
	
	while (play) {
		system("cls");
		previousBank = Game::mapAnimate(Game::map, 11, previousBank);
		Game::show(Game::map);
		Game::steering();
		Sleep(250);							//game speed
		Game::countPoints();
	}
}