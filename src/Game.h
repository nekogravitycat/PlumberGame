#include"Map.h"
#include"Navigate.h"
#include<iostream>

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
            //pipeGame.printdata();
            extendGraphic.input(pipeGame);
            extendGraphic.create();
            //system("CLS");
            extendGraphic.print();
            // finish setup

            // Start Game
            //printInfo();
            // Game end
        }

        // default constructor
        Game(void)
        {
            inputColumns = 0;
            inputRows = 0;
        }

    private:
        int inputColumns, inputRows;
        Map pipeGame;
        Navigate extendGraphic;

        enum VALID_INPUT
        {
            W = 0,
            A = 1,
            S = 2,
            D = 3,
            ENTER = 4,
            INVALID,
        };

        void printInfo(void)
        {
            cout << "W, A, S, D to change which Pipe you want to select" << endl;
            cout << "Enter to turn Pipe" << endl;
        }
};