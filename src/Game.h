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
            extendGraphic.create();
            system("CLS");
            extendGraphic.print();
            printInfo();
            // finish setup
            // Game loop
            
            while(true)
            {
                keyBoard = _getch();
                updateState();
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

        void updateState(void)
        {         
            if(keyBoard == 'a') // choose left one
            {
                if(pipeGame.getSelection() != 0)
                {
                    pipeGame.setSelection(pipeGame.getSelection() - 1);
                }
            }
            else if(keyBoard == 'd')
            {
                if(pipeGame.getSelection() != pipeGame.getRouteSize() - 1)
                {
                    pipeGame.setSelection(pipeGame.getSelection() + 1);
                }
            }
            else if(keyBoard == 's')
            {
                cout << "Turn it! Have not right it" << endl;
            }
            else
            {
                cout << "Invalid input!" << endl;
            }

            system("CLS");
            extendGraphic.input(pipeGame);
            extendGraphic.update();
            extendGraphic.print();
            printInfo();
        }
};