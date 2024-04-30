/***********************************************************************
 * File: Pipe.cpp
 * Author: Ayr
 * Create Date: 2024/5/1
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Pipe class
***********************************************************************/
#include "Pipe.h"

char Pipe::GetShape() {
	return shape;
}

int Pipe::GetRotation() {
	return rotation;
}

int Pipe::GetColor() {
	return color;
}

void Pipe::setWater(int input) {
	water = input;
}

int Pipe::getWater(void) {
	return water;
}

void Pipe::SetShape(pShape _shape) {
	shape = _shape;
}

void Pipe::SetRotation(int _rotation) {
	rotation = _rotation;
}

void Pipe::setcolor(int _color) {
	color = _color;
}

void Pipe::Rotate() {
	rotation = (rotation + 1) % 4;
}

void Pipe::randomRotate(void) {
	rotation = rand() % 4;
}