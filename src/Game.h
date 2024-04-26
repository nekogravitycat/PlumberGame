#include"Map.h"
#include"Navigate.h"
#include<iostream>
#include <conio.h> // for _getch()

using namespace std;

class Game
{
    public:
        void startGame(void)
        {
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
            while(true)
            {
                keyBoard = _getch();

                if(updateState())
                {
                    break;
                }
            }
            // Game loop end
        }

        bool isItGameOver(void)
        {
            if(pipeGame.getPipe(pipeGame.getend().posY, pipeGame.getend().posX).getWater() == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // default constructor
        Game(void)
        {
            inputColumns = 0;
            inputRows = 0;
        }

    private:
        int inputColumns, inputRows;
        char keyBoard;
        Map pipeGame;
        Navigate extendGraphic;

        void printInfo(void)
        {
            cout << "(A) and (D) to change which Pipe you want to select" << endl;
            cout << "(S) to turn Pipe" << endl;
        }

        bool isPositionValid(int rows, int columns)
        {
            if(columns< 0 || columns >= inputColumns)
            {
                return false;
            }

            if(rows < 0 || rows >= inputRows)
            {
                return false;
            }

            return true;
        }

        bool updateState(void)
        {
            if(keyBoard == 'w')
            {
                if(isPositionValid(pipeGame.getSelection().posY - 1, pipeGame.getSelection().posX))
                {
                    pipeGame.setSelection(pipeGame.getSelection().posY - 1, pipeGame.getSelection().posX);
                }
            }
            else if(keyBoard == 'a')
            {
                if(isPositionValid(pipeGame.getSelection().posY, pipeGame.getSelection().posX - 1))
                {
                    pipeGame.setSelection(pipeGame.getSelection().posY, pipeGame.getSelection().posX - 1);
                }
            }
            else if(keyBoard == 's')
            {
                if(isPositionValid(pipeGame.getSelection().posY + 1, pipeGame.getSelection().posX))
                {
                    pipeGame.setSelection(pipeGame.getSelection().posY + 1, pipeGame.getSelection().posX);
                }
            }
            else if(keyBoard == 'd')
            {
                if(isPositionValid(pipeGame.getSelection().posY, pipeGame.getSelection().posX + 1))
                {
                    pipeGame.setSelection(pipeGame.getSelection().posY, pipeGame.getSelection().posX + 1);
                }
            }
            else if(keyBoard == ' ') // space to turn pipe
            {
                pipeGame.Rotate();
            }
            
            extendGraphic.input(pipeGame);
            extendGraphic.update();
            extendGraphic.Calculate_path();
            system("CLS");

            if(!isItGameOver())
            {
                extendGraphic.print();
                printInfo();
                return false;
            }
            else
            {
                extendGraphic.print();
                cout << "GAME OVER!!" << endl;
                return true; // true means game over
            }
        }
};