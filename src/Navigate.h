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
	Map* mapReference;
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
	int Calculate_direction(Position input_pos);
	int Calculate_distance(Position input_pos, Position Displacement);
public:
	void setReference(Map* input);
	void input(Map input_map);
	void update();
	void create();
	void Calculate_path();
	void print();
};