/***********************************************************************
 * File: Navigate.h
 * Author: Ayr
 * Create Date: 2024/5/1
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Navigate class
***********************************************************************/
#pragma once

#include <vector>
#include <fstream>
#include "Map.h"

using namespace std;

class Navigate {
private:
	Map originalMap;
	Map* mapReference = NULL;
	vector<vector<int>> control;
	Position current_location;
	int example[4][3][3] = {
		{
			{0, 1, 0},
			{1, 1, 1},
			{0, 1, 0}
		},
		{
			{0, 1, 0},
			{0, 1, 0},
			{0, 1, 0}
		},
		{
			{0, 1, 0},
			{1, 1, 1},
			{0, 0, 0}
		},
		{
			{0, 1, 0},
			{0, 1, 1},
			{0, 0, 0}
		}
	};

	// Intent: To calculate the direction to move based on the input position
	// Pre: input_pos must be a valid Position object
	// Post: Returns an integer representing the direction to move
	int Calculate_direction(Position input_pos);

	// Intent: To calculate the distance between two positions
	// Pre: input_pos and Displacement must be valid Position objects
	// Post: Returns the distance between the two positions
	int Calculate_distance(Position input_pos, Position Displacement);

public:
	// Intent: To set the reference map for navigation
	// Pre: input must be a valid pointer to a Map object
	// Post: Sets the reference map for navigation
	void setReference(Map* input);

	// Intent: To input the map for navigation
	// Pre: input_map must be a valid Map object
	// Post: Inputs the map for navigation
	void input(Map input_map);

	// Intent: To update the navigation state
	// Pre: None
	// Post: Updates the navigation state
	void update();

	// Intent: To create the navigation control
	// Pre: None
	// Post: Creates the navigation control
	void create();

	// Intent: To calculate the navigation path
	// Pre: None
	// Post: Calculates the navigation path
	void Calculate_path();

	// Intent: To print the navigation control
	// Pre: None
	// Post: Prints the navigation control
	void print();
};