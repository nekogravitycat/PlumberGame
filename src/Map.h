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
	bool isItOnRoute(int rows, int columns);
	void randRoute(void);
	void randMap(void);
public:
	void startOperate(void);
	Map(void);
	Map(int inputCol, int inputRow);
	int getColumn(void);
	int getRow(void);
	void setSelectedWater(int rows, int columns);
	void resetPipeWater(void);
	Pipe getPipeData(int inputX, int inputY);
	void setSize(int inputRow, int inputCol);
	void setStart();
	void setStart(int inputX, int inputY);
	void setEnd(int inputX, int inputY);
	void Rotate(void);
	void printData(void);
	void setMapByInput(Pipe** forInput);
	Position& getSelection(void);
	void setSelection(int inputY, int inputX);
	int getRouteSize(void);
	Position getstart();
	Position getend();
	Pipe& getPipe(int rows, int columns);
};