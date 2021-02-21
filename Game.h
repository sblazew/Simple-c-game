#pragma once
#include <iostream>
#ifndef Game_H
#define Game_H

class Game {
	private:
		//int const mapSize = 11;
		
		int x = 4;					//x,y - player position at game launch
		int y = 10;
		int points = 0;
		int previousBank = 1;
		bool firstRun = true;
		bool play = true;
		
		
public:
	char map[11][11] = {
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
	void runGame();
	void clearMemory();
	void countPoints();
	void menu();
	bool game_over = false;
	void show(char map[][11]);
	int mapAnimate(char map[][11], int size, int bank);
	int moveLeft(char map[][11]);
	int moveRight(char map[][11]);
	void playAgain();
	void steering();
	bool startGame;
};

#endif // !Game
