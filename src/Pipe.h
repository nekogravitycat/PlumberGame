/***********************************************************************
 * File: Pipe.h
 * Author: Ayr
 * Create Date: 2023/04/18
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for Pipe class
***********************************************************************/
#pragma once

enum pShape {
	CROSS = 0,
	STRA = 1,
	TEE = 2,
	ELBOW = 3
};

class Pipe {
private:
	pShape shape;
	int rotation; // See the note above (0 ~ 3)
	int color = 7;
	int water = 0; // 0 means does not exist 1 means exist 
public:
	char GetShape();
	int GetRotation();
	int GetColor();
	void setWater(int input);
	int getWater(void);
	void SetShape(pShape _shape);
	void SetRotation(int _rotation);
	void setcolor(int _color);
	void Rotate();
	void randomRotate(void);
};