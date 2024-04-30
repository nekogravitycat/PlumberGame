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
	
	// Intent: To print information about the game
	// Pre: None
	// Post: Prints information about the game
	void printInfo(void);
	
	// Intent: To check if a given position is valid within the game board
	// Pre: rows and columns must be within the dimensions of the game board
	// Post: Returns true if the position is valid, false otherwise
	bool isPositionValid(int rows, int columns);
	
	// Intent: To determine the type of pipe based on its orientation
	// Pre: compare is a 3x3 array representing a pipe configuration
	// Post: Returns an integer representing the type of pipe
	int whatIsIt(char compare[3][3]);
	
	// Intent: To determine the type of pipe based on its orientation after rotation
	// Pre: compare is a 3x3 array representing a pipe configuration
	// Post: Returns an integer representing the type of pipe after rotation
	int whatIsItRotation(char compare[3][3]);
	
	// Intent: To open a file containing game data
	// Pre: fileName is the path to the file to be opened
	// Post: Opens the file
	void openFile(string fileName);

	// Intent: To update the state of the game
	// Pre: None
	// Post: Updates the state of the game based on player input
	// Returns true if the game state was successfully updated, false otherwise
	bool updateState(void);

public:
	// Intent: Default constructor for the Game class
	// Pre: None
	// Post: Initializes inputColumns and inputRows to 0, keyBoard to default value, and initializes pipeGame and extendGraphic
	Game(void);

	// Intent: Parameterized constructor for the Game class
	// Pre: row and col must be non-negative integers
	// Post: Initializes inputColumns and inputRows to the specified values, keyBoard to default value, and initializes pipeGame and extendGraphic
	Game(int row, int col);

	// Intent: To start the game
	// Pre: None
	// Post: Starts the game
	void startGame(void);

	// Intent: To check if the game is over
	// Pre: None
	// Post: Returns true if the game is over, false otherwise
	bool isItGameOver(void);

	// Intent: To start the core game logic
	// Pre: row and col must be non-negative integers
	// Post: Starts the core game logic with the specified dimensions
	void startGameCore(int row, int col);

	// Intent: To start the core game logic with data from a file
	// Pre: None
	// Post: Starts the core game logic with data from a file
	void fileStartGameCore(void);

	// Intent: To get the number of rows in the game board
	// Pre: None
	// Post: Returns the number of rows in the game board
	int GetRows();

	// Intent: To get the number of columns in the game board
	// Pre: None
	// Post: Returns the number of columns in the game board
	int GetColumns();

	// Intent: To check if a given position is the start point of a pipe
	// Pre: row and col must be non-negative integers
	// Post: Returns true if the position is the start point of a pipe, false otherwise
	bool IsStart(int row, int col);

	// Intent: To check if a given position is the end point of a pipe
	// Pre: row and col must be non-negative integers
	// Post: Returns true if the position is the end point of a pipe, false otherwise
	bool IsEnd(int row, int col);

	// Intent: To get the type of pipe at a given position
	// Pre: row and col must be non-negative integers
	// Post: Returns an integer representing the type of pipe at the specified position
	int GetPipeInfo(int row, int col);
	
	// Intent: To handle a player click on a game board position
	// Pre: row and col must be non-negative integers
	// Post: Handles the player click on the specified position
	void Click(int row, int col);
};