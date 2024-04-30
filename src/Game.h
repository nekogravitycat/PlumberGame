/***********************************************************************
 * File: Game.h
 * Author: Gravity cat
 * Create Date: 2024/5/1
 * Editor: Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Game class 
***********************************************************************/
#pragma once

#include"Map.h"
#include"Navigate.h"
#include<fstream>
#include<iostream>
#include <conio.h> // for _getch()

class Game {
private:
	int inputColumns, inputRows;
	char keyBoard;
	Map pipeGame;
	Navigate extendGraphic;
	void printInfo(void);
	bool isPositionValid(int rows, int columns);
	int whatIsIt(char compare[3][3]);
	int whatIsItRotation(char compare[3][3]);
	void openFile(string fileName);
	bool updateState(void);
public:
	void startGame(void);
	bool isItGameOver(void);
	Game(void);
	Game(int row, int col);
	void startGameCore(int row, int col);
	void fileStartGameCore(void);
	int GetRows();
	int GetColumns();
	bool IsStart(int row, int col);
	bool IsEnd(int row, int col);
	int GetPipeInfo(int row, int col);
	void Click(int row, int col);
};