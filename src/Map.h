/************************************
File: map.h
Author: Ayr
Create Date: 2023/04/18
Editor: Ayr, MENG-HAN CHEN
Update Date: 2023/04/30
Description:
************************************/
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
public:
	// just execute this function it will setup Map and Route for you
	void startOperate(void) {
		randMap();
		randRoute();
		// set default pipe you select
		data[selection.posY][selection.posX].setcolor(174);
		// finish setting
	}

	// default constructor, it will set up random seed, and ohter data set to zero
	Map(void) {
		srand(time(NULL));
		col = 0;
		row = 0;
		start.posX = 0;
		start.posY = 0;
		selection.posX = 0;
		selection.posY = 0;
		numsOfCross = 0;
		maxCross = 0;
	}

	// setting constructor, with input columns and rows, set up random seed also
	// setup starting position
	Map(int inputCol, int inputRow) {
		srand(time(0));
		col = inputCol;
		row = inputRow;
		start.posX = 0;
		start.posY = rand() % row;
		selection.posX = 0;
		selection.posY = 0;
		numsOfCross = 0;
		maxCross = 0;
	}

	// get column
	int getColumn(void) {
		return col;
	}

	// get row
	int getRow(void) {
		return row;
	}

	void setSelectedWater(int rows, int columns) {
		data[rows][columns].setWater(1);
	}

	void resetPipeWater(void) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				data[i][j].setWater(0);
			}
		}
	}

	// return single pipe data, with inputX and inputY to choose which x and y
	Pipe getPipeData(int inputX, int inputY) {
		return data[inputY][inputX];
	}

	// if we do not setup col and row when we create Map object, we setup here
	// it also setup starting position
	void setSize(int inputRow, int inputCol) {
		srand(time(0));
		row = inputRow;   //Y
		col = inputCol;   //X
		start.posX = 0;
		start.posY = rand() % row;

		/*while(abs(start.posY - end.posY) < col / 2)
		{
				start.posY = rand() % row;
				end.posY = rand() % row;
		}*/
	}

	// set startPosition with random
	void setStart() {
		start.posX = 0;
		start.posY = rand() % row;
	}

	// set startPosition with inputX and inputY, no random here
	void setStart(int inputX, int inputY) {
		start.posX = inputX;
		start.posY = inputY;
	}

	void setEnd(int inputX, int inputY) {
		end.posX = inputX;
		end.posY = inputY;
	}

	void Rotate(void) {
		data[selection.posY][selection.posX].Rotate();
	}

	// for test
	void printData(void) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				SetColor(data[i][j].GetColor());

				switch (data[i][j].GetShape()) {
				case CROSS:
					cout << "C";
					break;
				case STRA:
					cout << "S";
					break;
				case TEE:
					cout << "T";
					break;
				case ELBOW:
					cout << "E";
					break;
				default:
					break;
				}
			}

			SetColor(7); // reset color for endl
			cout << endl;
		}
	}

	void setMapByInput(Pipe** forInput) {
		for (int i = 0; i < row; i++) {
			vector<Pipe> temp;
			for (int j = 0; j < col; j++) {
				Pipe x;
				pShape psh = CROSS;

				switch (forInput[i][j].GetShape()) {
				case 0: // +
					psh = CROSS;
					break;
				case 1: // |
					psh = STRA;
					break;
				case 2: // T
					psh = TEE;
					break;
				case 3: // L
					psh = ELBOW;
					break;
				default:
					break;
				}

				x.SetShape(psh);
				x.SetRotation(forInput[i][j].GetRotation());
				temp.push_back(x);
			}

			data.push_back(temp);
		}
	}

	Position& getSelection(void) {
		return selection;
	}

	void setSelection(int inputY, int inputX) {
		if (isItOnRoute(selection.posY, selection.posX)) {
			data[selection.posY][selection.posX].setcolor(64);
		}
		else {
			data[selection.posY][selection.posX].setcolor(7);
		}

		data[start.posY][start.posX].setcolor(207); // start position
		//data[route[route.size() - 1].posY][route[route.size() - 1].posX].setcolor(207); // end position
		selection.posX = inputX;
		selection.posY = inputY;
		data[selection.posY][selection.posX].setcolor(237);
	}

	int getRouteSize(void) {
		return route.size();
	}

	Position getstart() {
		return start;
	}

	Position getend() {
		return end;
	}

	Pipe& getPipe(int rows, int columns) {
		return data[rows][columns];
	}

private:
	vector<vector<Pipe>> data;  //Record map information
	vector<Position> route;     //Record the correct route Position
	Position start, end;        // Record start and end position
	Position selection;          // index of route
	vector<Position> node;      // Record node position for generate correct route
	int col, row;               // map size
	int numsOfCross;
	int maxCross;

	bool isItOnRoute(int rows, int columns) {
		for (int i = 0; i < route.size(); i++) {
			if (route[i].posY == rows && route[i].posX == columns) {
				return true;
			}
		}

		return false;
	}

	// it random route by setting random nodes between start and end
	void randRoute(void) {
		int nodeQuantity = col / 3; // setup how many nodes
		node.push_back(start); // first node is starting position
		route.push_back(start);
		Position temp; // for temp store position data

		// i start with one, because we have already set start for our first node
		for (int i = 1; i < nodeQuantity; i++) {
			while (true) {
				temp.posX = i * 3;
				temp.posY = rand() % row; // random choose y for node

				// make sure it have enough deltaY between two node
				if (abs(node[i - 1].posY - temp.posY) >= 1) {
					node.push_back(temp);
					break;
				}
			}
		}
		cout << "o" << endl;
		if (col / 3 != 0) {
			temp.posX = col - 1;
			temp.posY = rand() % row;
			node.push_back(temp);
		}
		end = node[node.size() - 1];

		int direction = 1;    //1:down  -1:up

		// loop with node to setup route between two node
		for (int i = 0; i < node.size() - 1; i++) {
			// to consider up or down
			if (node[i].posY < node[i + 1].posY) {
				direction = 1;
			}
			else {
				direction = -1;
			}

			Position choosen, current = node[i];
			Position delta = node[i + 1] - node[i];
			delta.posY = abs(delta.posY);
			vector<Position> move;

			// setup how many columns we need to move
			for (int i = 0; i < delta.posX; i++) {
				choosen.posX = 1;
				choosen.posY = 0;
				move.push_back(choosen);
			}

			// setup how many rows we need to move
			for (int i = 0; i < delta.posY; i++) {
				choosen.posX = 0;
				choosen.posY = 1 * direction;
				move.push_back(choosen);
			}

			// shuffle the move's order
			for (int i = 1; i < move.size(); i++) {
				int randNum = rand() % (move.size() - 1) + 1;
				swap(move[i], move[randNum]);
			}

			// start moving
			for (int i = 0; i < move.size(); i++) {
				current = current + move[i];
				route.push_back(current);
			}
		}

		int forward = -1;

		// check if the route can successfully reach the end, setup color of map
		for (int i = 1; i < route.size() + 1; i++) {
			int color = 64;
			int mid = 0;
			Position judge;

			if (forward == -1) {
				mid = 0;
				judge.posX = -1;
				judge.posX = route[0].posY;
				color = 207;
			}
			else if (i == route.size()) {
				mid = (forward + i) / 2;
				judge.posX = route[forward].posX - (route[route.size() - 1].posX + 1);
				judge.posX = route[forward].posY - (route[route.size() - 1].posY);
				color = 207;
			}
			else {
				mid = (forward + i) / 2;
				judge = route[forward] - route[i];
			}

			forward = forward + 1;
			pShape psh;
			int randNum = rand() % 3;

			if (judge.posX == 0 || judge.posY == 0) {
				switch (randNum) {
				case 0:
					psh = CROSS; // +
					break;
				case 1:
					psh = STRA; // |
					break;
				case 2:
					psh = TEE; // T
					break;
				}
			}
			else {
				switch (randNum) {
				case 0:
					psh = CROSS; // |
					break;
				case 1:
					psh = TEE; // T
					break;
				case 2:
					psh = ELBOW; // L
					break;
				}
			}

			// cout << route[mid].posY << " " << route[mid].posX << endl; (For testing!)
			// set shape and color to it
			data[route[mid].posY][route[mid].posX].SetShape(psh);
			data[route[mid].posY][route[mid].posX].setcolor(color);
		}

		for (int i = 0; i < route.size(); i++) {
			data[route[i].posY][route[i].posX].randomRotate();
		}
	}

	void randMap(void) {
		maxCross = row / 2;

		for (int i = 0; i < row; i++) {
			vector<Pipe> temp;

			for (int j = 0; j < col; j++) {
				Pipe x;
				pShape psh = CROSS;
				int randNum = rand() % 4;

				if (randNum == 0) {
					if (maxCross == numsOfCross) {
						while (randNum == 0) {
							randNum = rand() % 4;
						}
					}
					else {
						numsOfCross++;
					}
				}

				switch (randNum) {
				case 0: // +
					psh = CROSS;
					break;
				case 1: // |
					psh = STRA;
					break;
				case 2: // T
					psh = TEE;
					break;
				case 3: // L
					psh = ELBOW;
					break;
				default:
					break;
				}

				x.SetShape(psh);
				x.SetRotation(rand() % 4);
				temp.push_back(x);
			}

			data.push_back(temp);
		}
	}
};