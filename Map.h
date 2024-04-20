/************************************
File: map.h
Author: Ayr
Create Date: 2023/04/18
Editor: Ayr, MENG-HAN CHEN
Update Date: 2023/04/19
Description:
************************************/

#pragma once

#include <iostream>
#include<random>
#include<time.h>
#include <vector>
#include <cmath>
#include "Pipe.h"
#include "Position.h"
#include "Color.h"

using namespace std;

class Map
{
    public:
        // just execute this function it will setup Map and Route for you
        void startOperate(void)
        {
            randMap();
            randRoute();
        }

        // default constructor
        Map(void)
        {
            srand(time(NULL));
            col = 0;
            row = 0;
            start.posX = 0;
            start.posY = 0;
            end.posX = 0;
            end.posY = 0;
            direction = -1; //-1:up, 1:down
        }

        // setting constructor
        Map(int inputCol, int inputRow)
        {
            srand(time(0));
            col = inputCol;
            row = inputRow;
            start.posX = 0;
            start.posY = rand() % row;
            end.posX = col - 1;
            end.posY = rand() % row;

            while(abs(start.posY - end.posY) < col / 2)
            {
                start.posY = rand() % row;
                end.posY = rand() % row;
            }

            direction = -1; //-1:up, 1:down
        }

        int getColumn(void)
        {
            return col;
        }

        int getRow(void)
        {
            return row;
        }

        Pipe getPipeData(int inputX, int inputY)
        {
            return data[inputX][inputY];
        }

        void setSize(int inputCol, int inputRow)
        {
            srand(time(0));
            col = inputCol;
            row = inputRow;
            start.posX = 0;
            start.posY = rand() % row;
            end.posX = col - 1;
            end.posY = rand() % row;

            while(abs(start.posY - end.posY) < col / 2)
            {
                start.posY = rand() % row;
                end.posY = rand() % row;
            }

            direction = -1; //-1:up, 1:down
        }

        void setStart()
        {
            start.posX = 0;
            start.posY = rand() % row;
        }

        void setStart(int inputX, int inputY)
        {
            start.posX = inputX;
            start.posY = inputY;
        }
        
        void setEnd()
        {
            end.posX = col - 1;
            end.posY = rand() % row;
        }
        
        void setEnd(int inputX, int inputY)
        {
            end.posX = inputX;
            end.posY = inputY;
        }

        // for test
        void printdata()
        {
            for (int i = 0; i < row;i++)
            {
                for (int j = 0; j < col;j++)
                {
                    SetColor(data[i][j].GetColor());

                    switch (data[i][j].GetShape())
                    {
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

                SetColor(7);
                cout << endl;
            }

            SetColor(7);
        }

    private:
        vector<vector<Pipe>> data;
        vector<Position> route;
        Position start, end;
        int col, row;
        int direction;

        void randRoute(void)
        {
            int deltaX = 0, deltaY = 0, randNum = 0, moveSize = 0;
            deltaX = end.posX - start.posX;
            deltaY = end.posY - start.posY;
            vector<Position> move;
            Position choosen, current;

            if(deltaY > 0) // go down
            {
                // means move rights
                choosen.posX = 1;
                choosen.posY = 0;
                // end

                // deltaX times move right
                for(int i = 0; i < deltaX; i++)
                {
                    move.push_back(choosen);
                }
                // end

                // means move down
                choosen.posX = 0;
                choosen.posY = 1;
                // end

                // deltaY times move down
                for(int i = 0; i < deltaY; i++)
                {
                    move.push_back(choosen);
                }
                // end
            }
            else if(deltaY == 0)
            {
                // means move rights
                choosen.posX = 1;
                choosen.posY = 0;
                // end

                // deltaX times move right
                for(int i = 0; i < deltaX; i++)
                {
                    move.push_back(choosen);
                }
                // end
            }
            else // go up
            {
                // means move rights
                choosen.posX = 1;
                choosen.posY = 0;
                // end

                // deltaX times move right
                for(int i = 0; i < deltaX; i++)
                {
                    move.push_back(choosen);
                }
                // end

                // means move down
                choosen.posX = 0;
                choosen.posY = -1;
                // end

                // deltaY times move down
                for(int i = 0; i < (0 - deltaY); i++)
                {
                    move.push_back(choosen);
                }
                // end
            }
                    
            // suffle the order
            for(int i = 0; i < move.size(); i++)
            {
                randNum = rand() % move.size();
                swap(move[i], move[randNum]);
            }
                    
            current.posY = start.posY;
            current.posX = start.posX;

            // push data back to route
            for(int i = 0; i < move.size(); i++)
            {
                data[current.posY][current.posX].setcolor(195);
                current.posY = current.posY + move[i].posY;
                current.posX = current.posX + move[i].posX;
            }

            data[current.posY][current.posX].setcolor(195);

            for (int i = 0; i < route.size(); i++)
            {
                data[route[i].posY][route[i].posX].setcolor(176);
            }

            for (int i = 2; i < route.size() / 2; i++)
            {
                int forward = 0; // !
                int mid = (forward + i) / 2;
                Position judge = route[forward] - route[i];
                pShape psh;
                int rnad_num = rand() % 3;

                if (judge.posX == 0 || judge.posY == 0)
                {
                    switch(rnad_num)
                    {
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
                else
                {
                    switch(rnad_num)
                    {
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

                data[route[mid].posY][route[mid].posX].SetShape(psh);
            }
        }


        void randMap(void)
        {
            for (int i = 0; i < col; i++)
            {
                vector<Pipe> temp;

                for (int j = 0; j < row; j++)
                {
                    Pipe x;
                    pShape psh = CROSS;
                    int randNum = rand() % 4;

                    switch(randNum)
                    {
                        case 0: // +
                            psh = CROSS;
                            break;
                        case 1: // |
                            psh = STRA;
                            break;
                        case 2: // T
                            psh= TEE;
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