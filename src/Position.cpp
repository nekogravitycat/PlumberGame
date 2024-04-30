/***********************************************************************
 * File: Position.cpp
 * Author: Ayr
 * Create Date: 2024/5/1
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Position class
***********************************************************************/
#include "Position.h"

const Position Position::operator+(const Position& input) {
	Position output;
	output.posX = posX + input.posX;
	output.posY = posY + input.posY;
	return output;
}
const Position Position::operator+(const int& input) {
	Position output;
	output.posX = posX + input;
	output.posY = posY + input;
	return output;
}
const Position Position::operator-(const Position& input) {
	Position output;
	output.posX = posX - input.posX;
	output.posY = posY - input.posY;
	return output;
}
const Position Position::operator*(const int& input) {
	Position output;
	output.posX = posX * input;
	output.posY = posY * input;
	return output;
}
bool Position::operator==(const Position& input) {
	bool output = false;
	if (posX == input.posX && posY == input.posY) {
		output = true;
	}
	return output;
}