/***********************************************************************
 * File: Position.h
 * Author: Ayr
 * Create Date: 2023/04/19
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Position calss
***********************************************************************/
#pragma once

class Position {
public:
	int posX = 0;
	int posY = 0;

	// Intent: To add two Position objects
	// Pre: input must be a valid Position object
	// Post: Returns a new Position object representing the sum of the two positions
	const Position operator+(const Position& input);

	// Intent: To add an integer to a Position object
	// Pre: input must be an integer
	// Post: Returns a new Position object with added integer to both coordinates
	const Position operator+(const int& input);

	// Intent: To subtract two Position objects
	// Pre: input must be a valid Position object
	// Post: Returns a new Position object representing the difference between the two positions
	const Position operator-(const Position& input);

	// Intent: To multiply a Position object by an integer
	// Pre: input must be an integer
	// Post: Returns a new Position object with coordinates multiplied by the integer
	const Position operator*(const int& input);

	// Intent: To compare two Position objects for equality
	// Pre: input must be a valid Position object
	// Post: Returns true if the coordinates of the two Position objects are equal, false otherwise
	bool operator==(const Position& input);
};