/***********************************************************************
 * File: Pipe.h
 * Author: Ayr
 * Create Date: 2023/04/18
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Pipe class
***********************************************************************/
#pragma once

#include <cstdlib>

enum pShape {
	CROSS = 0,
	STRA = 1,
	TEE = 2,
	ELBOW = 3
};

class Pipe {
private:
	pShape shape;
	int rotation = 0; // See the note above (0 ~ 3)
	int color = 7;
	int water = 0; // 0 means does not exist 1 means exist

public:
	// Intent: To get the shape of the pipe
	// Pre: None
	// Post: Returns the shape of the pipe
	char GetShape();

	// Intent: To get the rotation of the pipe
	// Pre: None
	// Post: Returns the rotation of the pipe
	int GetRotation();

	// Intent: To get the color of the pipe
	// Pre: None
	// Post: Returns the color of the pipe
	int GetColor();

	// Intent: To set the water status of the pipe
	// Pre: input must be either 0 or 1
	// Post: Sets the water status of the pipe
	void setWater(int input);

	// Intent: To get the water status of the pipe
	// Pre: None
	// Post: Returns the water status of the pipe
	int getWater(void);

	// Intent: To set the shape of the pipe
	// Pre: _shape must be a valid pShape object
	// Post: Sets the shape of the pipe
	void SetShape(pShape _shape);

	// Intent: To set the rotation of the pipe
	// Pre: _rotation must be an integer between 0 and 3
	// Post: Sets the rotation of the pipe
	void SetRotation(int _rotation);

	// Intent: To set the color of the pipe
	// Pre: _color must be an integer representing a valid console color code
	// Post: Sets the color of the pipe
	void setcolor(int _color);

	// Intent: To rotate the pipe by 90 degrees clockwise
	// Pre: None
	// Post: Rotates the pipe by 90 degrees clockwise
	void Rotate();

	// Intent: To rotate the pipe randomly
	// Pre: None
	// Post: Rotates the pipe randomly
	void randomRotate(void);
};