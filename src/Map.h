/***********************************************************************
 * File: Map.h
 * Author: Ayr
 * Create Date: 2024/5/1
 * Editor: Ayr, MENG-HAN CHEN, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Map class
***********************************************************************/
#pragma once

#include <iostream>
#include<time.h>
#include <vector>
#include <cmath>
#include "Pipe.h"
#include "Position.h"
#include "Color.h"

using namespace std;

class Map {
private:
	vector<vector<Pipe>> data;
	vector<Position> route;
	Position start, end;
	Position selection;
	vector<Position> node;
	int col, row;
	int numsOfCross;
	int maxCross;

	// Intent: To check if a given position is on the route
	// Pre: rows and columns must be within the dimensions of the game board
	// Post: Returns true if the position is on the route, false otherwise
	bool isItOnRoute(int rows, int columns);

	// Intent: To generate a random route on the map
	// Pre: None
	// Post: Generates a random route on the map
	void randRoute(void);

	// Intent: To generate a random map configuration
	// Pre: None
	// Post: Generates a random map configuration
	void randMap(void);

public:
	// Intent: Default constructor for the Map class
	// Pre: None
	// Post: Initializes col, row, numsOfCross, and maxCross to 0
	Map(void);

	// Intent: Parameterized constructor for the Map class
	// Pre: inputCol and inputRow must be non-negative integers
	// Post: Initializes col and row to the specified values, and initializes numsOfCross and maxCross to 0
	Map(int inputCol, int inputRow);

	// Intent: To start the operations on the map
	// Pre: None
	// Post: Starts the operations on the map
	void startOperate(void);

	// Intent: To get the number of columns in the map
	// Pre: None
	// Post: Returns the number of columns in the map
	int getColumn(void);

	// Intent: To get the number of rows in the map
	// Pre: None
	// Post: Returns the number of rows in the map
	int getRow(void);

	// Intent: To set a selected position as water
	// Pre: rows and columns must be within the dimensions of the game board
	// Post: Sets the selected position as water
	void setSelectedWater(int rows, int columns);

	// Intent: To reset all pipes to water
	// Pre: None
	// Post: Resets all pipes to water
	void resetPipeWater(void);

	// Intent: To get the pipe data at a given position
	// Pre: inputX and inputY must be within the dimensions of the game board
	// Post: Returns the pipe data at the specified position
	Pipe getPipeData(int inputX, int inputY);

	// Intent: To set the size of the map
	// Pre: inputRow and inputCol must be non-negative integers
	// Post: Sets the size of the map to the specified dimensions
	void setSize(int inputRow, int inputCol);

	// Intent: To set the start position of the map
	// Pre: None
	// Post: Sets the start position of the map to a random position
	void setStart();

	// Intent: To set the start position of the map
	// Pre: inputX and inputY must be within the dimensions of the game board
	// Post: Sets the start position of the map to the specified position
	void setStart(int inputX, int inputY);

	// Intent: To set the end position of the map
	// Pre: inputX and inputY must be within the dimensions of the game board
	// Post: Sets the end position of the map to the specified position
	void setEnd(int inputX, int inputY);

	// Intent: To rotate the selected pipe
	// Pre: None
	// Post: Rotates the selected pipe
	void Rotate(void);

	// Intent: To print the map data
	// Pre: None
	// Post: Prints the map data
	void printData(void);

	// Intent: To set the map configuration based on input pipe data
	// Pre: forInput must be a valid 2D array of Pipe objects
	// Post: Sets the map configuration based on the input pipe data
	void setMapByInput(Pipe** forInput);

	// Intent: To get the selection position
	// Pre: None
	// Post: Returns the selection position
	Position& getSelection(void);

	// Intent: To set the selection position
	// Pre: inputY and inputX must be within the dimensions of the game board
	// Post: Sets the selection position to the specified position
	void setSelection(int inputY, int inputX);

	// Intent: To get the size of the route
	// Pre: None
	// Post: Returns the size of the route
	int getRouteSize(void);

	// Intent: To get the start position of the map
	// Pre: None
	// Post: Returns the start position of the map
	Position getstart();

	// Intent: To get the end position of the map
	// Pre: None
	// Post: Returns the end position of the map
	Position getend();

	// Intent: To get the pipe at a given position
	// Pre: rows and columns must be within the dimensions of the game board
	// Post: Returns the pipe at the specified position
	Pipe& getPipe(int rows, int columns);
};
