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
	const Position operator+(const Position& input);
	const Position operator+(const int& input);
	const Position operator-(const Position& input);
	const Position operator*(const int& input);
	bool operator==(const Position& input);
};