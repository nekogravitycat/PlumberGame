#include"Map.h"
#include"Navigate.h"
#include<fstream>
#include<iostream>
#include <conio.h> // for _getch()

using namespace std;

class Game {
public:
	void startGame(void) {
		// setUp Map and extenGraphic
		cout << "Please input how many columns: ";
		cin >> inputColumns;
		cout << "Please input how many Rows: ";
		cin >> inputRows;
		pipeGame.setSize(inputColumns, inputRows);
		pipeGame.startOperate();
		extendGraphic.input(pipeGame);
		extendGraphic.setReference(&pipeGame);
		extendGraphic.create();
		extendGraphic.Calculate_path();
		extendGraphic.print();
		printInfo();
		// finish setup

		// Game loop
		while (true) {
			keyBoard = _getch();

			if (updateState()) {
				break;
			}
		}
		// Game loop end
	}

	bool isItGameOver(void) {
		if (pipeGame.getPipe(pipeGame.getend().posY, pipeGame.getend().posX).getWater() == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	// default constructor
	Game(void) {
		inputColumns = 0;
		inputRows = 0;
	}

	Game(int row, int col) {
		inputRows = row;
		inputColumns = col;
	}

	void startGameCore(int row, int col) {
		pipeGame.setSize(row, col);
		pipeGame.startOperate();
		extendGraphic.input(pipeGame);
		extendGraphic.setReference(&pipeGame);
		extendGraphic.create();
		extendGraphic.Calculate_path();
	}

	void fileStartGameCore(void)
	{
		openFile("store.txt");
		extendGraphic.input(pipeGame);
		extendGraphic.setReference(&pipeGame);
		extendGraphic.create();
		extendGraphic.Calculate_path();
	}

	int GetRows() {
		return inputRows;
	}

	int GetColumns() {
		return inputColumns;
	}

	bool IsStart(int row, int col) {
		Position pos = pipeGame.getstart();
		return row == pos.posY && col == pos.posX;
	}

	bool IsEnd(int row, int col) {
		Position pos = pipeGame.getend();
		return row == pos.posY && col == pos.posX;
	}

	int GetPipeInfo(int row, int col) {
		Pipe pipe = pipeGame.getPipeData(col, row);
		int shape = pipe.GetShape();
		int rotation = pipe.GetRotation();
		int water = pipe.getWater();
		int info = shape * 100 + rotation * 10 + water;
		return info;
	}

	void Click(int row, int col) {
		pipeGame.setSelection(row, col);
		pipeGame.Rotate();
		extendGraphic.input(pipeGame);
		extendGraphic.update();
		extendGraphic.Calculate_path();
		//system("CLS");
		extendGraphic.print();
		//printInfo();
	}

private:
	int inputColumns, inputRows;
	char keyBoard;
	Map pipeGame;
	Navigate extendGraphic;
	ifstream fileStream;

	void printInfo(void) {
		cout << "(W) (A) (S) (D) to change which Pipe you want to select" << endl;
		cout << "(SPACE) to turn Pipe" << endl;
	}

	bool isPositionValid(int rows, int columns) {
		if (columns < 0 || columns >= inputColumns) {
			return false;
		}

		if (rows < 0 || rows >= inputRows) {
			return false;
		}

		return true;
	}

	int whatIsIt(char compare[3][3])
	{
		int count = 0, row = 0, col = 0, condition = 0;

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(compare[i][j] == '#')
				{
					count++;
				}
			}
		}

		if(count == 6)
		{
			if(compare[1][0] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
			{
				return 1;
			}

			if(compare[0][1] == 'P' && compare[1][1] == 'P' && compare[2][1] == 'P')
			{
				return 1;
			}

			return 3;
		}
		else if(count == 5)
		{
			return 2;
		}
		else if(count == 4)
		{
			return 0;
		}

		return 4;
	}

	int whatIsItRotation(char compare[3][3])
	{
		switch(whatIsIt(compare))
		{
			case 0:
				return 0;
				break;
			case 1:
				if(compare[1][0] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 1;
				}

				if(compare[0][1] == 'P' && compare[1][1] == 'P' && compare[2][1] == 'P')
				{
					return 0;
				}

				break;
			case 2:
				if(compare[0][1] == 'P' && compare[1][0] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 0;
				}

				if(compare[0][1] == 'P' && compare[2][1] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 1;
				}

				if(compare[2][1] == 'P' && compare[1][0] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 2;
				}

				if(compare[0][1] == 'P' && compare[1][0] == 'P' && compare[1][1] == 'P' && compare[2][1] == 'P')
				{
					return 3;
				}

				break;
			case 3:
				if(compare[0][1] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 0;
				}

				if(compare[2][1] == 'P' && compare[1][1] == 'P' && compare[1][2] == 'P')
				{
					return 1;
				}

				if(compare[1][0] == 'P' && compare[1][1] == 'P' && compare[2][1] == 'P')
				{
					return 2;
				}

				if(compare[0][1] == 'P' && compare[1][1] == 'P' && compare[1][0] == 'P')
				{
					return 3;
				}

				break;
			default:
				break;
		}

		return 0;
	}

	void openFile(string fileName) // pls with .txt
	{
		fileStream.open(fileName);
		fileStream >> inputRows;
		fileStream >> inputColumns;
		pipeGame.setSize(inputColumns, inputRows);
		pipeGame.setStart(0, 0);
		pipeGame.setEnd(inputColumns - 1, inputRows - 1);

		char** temp = new char*[inputRows * 3];

		for(int i = 0; i < inputRows * 3; i++)
		{
			temp[i] = new char[inputColumns * 3];
		}

		for(int i = 0; i < inputRows * 3; i++)
		{
			for(int j = 0; j < inputColumns * 3; j++)
			{
				fileStream >> temp[i][j];
			}
		}

		char compare[3][3];
		Pipe** forInput = new Pipe*[inputRows];
		pShape shape = CROSS;

		for(int i = 0; i < inputRows; i++)
		{
			forInput[i] = new Pipe[inputColumns];
		}

		for(int i = 0; i < inputRows * 3; i = i + 3)
		{
			for(int j = 0; j < inputColumns * 3; j = j + 3)
			{
				for(int k = 0; k < 3; k++)
				{
					for(int l = 0; l < 3; l++)
					{
						compare[k][l] = temp[i + k][j + l];
					}
				}

				switch(whatIsIt(compare))
				{
					case 0:
						shape = CROSS;
						break;
					case 1:
						shape = STRA;
						break;
					case 2:
						shape = TEE;
						break;
					case 3:
						shape = ELBOW;
						break;
					default:
						break;
				}

				forInput[i / 3][j / 3].SetShape(shape);
				forInput[i / 3][j / 3].SetRotation(whatIsItRotation(compare));
			}
		}

		pipeGame.setMapByInput(forInput);
	}

	bool updateState(void) {
		if (keyBoard == 'w') {
			if (isPositionValid(pipeGame.getSelection().posY - 1, pipeGame.getSelection().posX)) {
				pipeGame.setSelection(pipeGame.getSelection().posY - 1, pipeGame.getSelection().posX);
			}
		}
		else if (keyBoard == 'a') {
			if (isPositionValid(pipeGame.getSelection().posY, pipeGame.getSelection().posX - 1)) {
				pipeGame.setSelection(pipeGame.getSelection().posY, pipeGame.getSelection().posX - 1);
			}
		}
		else if (keyBoard == 's') {
			if (isPositionValid(pipeGame.getSelection().posY + 1, pipeGame.getSelection().posX)) {
				pipeGame.setSelection(pipeGame.getSelection().posY + 1, pipeGame.getSelection().posX);
			}
		}
		else if (keyBoard == 'd') {
			if (isPositionValid(pipeGame.getSelection().posY, pipeGame.getSelection().posX + 1)) {
				pipeGame.setSelection(pipeGame.getSelection().posY, pipeGame.getSelection().posX + 1);
			}
		}
		else if (keyBoard == ' ') // space to turn pipe
		{
			pipeGame.Rotate();
		}

		extendGraphic.input(pipeGame);
		extendGraphic.update();
		extendGraphic.Calculate_path();
		system("CLS");

		if (!isItGameOver()) {
			extendGraphic.print();
			printInfo();
			return false;
		}
		else {
			extendGraphic.print();
			cout << "GAME OVER!!" << endl;
			return true; // true means game over
		}
	}
};