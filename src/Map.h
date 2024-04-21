/************************************
File: map.h
Author: Ayr
Create Date: 2023/04/18
Editor: Ayr, MENG-HAN CHEN
Update Date: 2023/04/21
Description:
************************************/

#pragma once

#include <iostream>
//#include<random>
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
        }

        // setting constructor
        Map(int inputCol, int inputRow)
        {
            srand(time(0));
            col = inputCol;
            row = inputRow;
            start.posX = 0;
            start.posY = rand() % row;

            /*while(abs(start.posY - end.posY) < col / 2)
            {
                start.posY = rand() % row;
                end.posY = rand() % row;
            }*/
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
            return data[inputY][inputX];
        }

        void setSize(int inputCol, int inputRow)
        {
            srand(time(0));
            col = inputCol;   //X
            row = inputRow;   //Y
            start.posX = 0;
            start.posY = rand() % row;

            /*while(abs(start.posY - end.posY) < col / 2)
            {
                start.posY = rand() % row;
                end.posY = rand() % row;
            }*/
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
        }

    private:
        vector<vector<Pipe>> data;  //Record map information
        vector<Position> route;     //Record the correct route Position
        Position start;
        vector<Position> node;
        int col, row;

        void randRoute(void)
        {
            int node_quantity = col / 3;

            node.push_back(start);
            route.push_back(start);
            Position temp;
            for (int i = 1; i < node_quantity; i++)
            {
                while(1)
                {
                    temp.posX = i * 3;
                    temp.posY = rand() % row;
                    if (abs(node[i].posY - temp.posY) >= 3)
                    {
                        node.push_back(temp);
                        break;
                    }
                }
            }
            if (col / 3 != 0)
            {
                temp.posX = col - 1;
                temp.posY = rand() % row; //////////////////
                node.push_back(temp);
            }
            int direction = 1;    //1:down  -1:up
            for (int i = 0; i < node.size() - 1; i++)
            {
                if (node[i].posY < node[i + 1].posY)
                {
                    direction = 1;
                }
                else
                {
                    direction = -1;
                }
                Position choosen, current = node[i];
                Position delta = node[i + 1] - node[i];
                delta.posY = abs(delta.posY);
                vector<Position> move;
                for (int i = 0; i < delta.posX; i++)
                {
                    choosen.posX = 1;
                    choosen.posY = 0;
                    move.push_back(choosen);
                }
                for (int i = 0; i < delta.posY; i++)
                {
                    choosen.posX = 0;
                    choosen.posY = 1 * direction;
                    move.push_back(choosen);
                }
                for (int i = 1; i < move.size(); i++)
                {
                    int randNum = rand() % (move.size() - 1) + 1;
                    swap(move[i], move[randNum]);
                }
                for (int i = 0; i < move.size(); i++)
                {
                    current = current + move[i];
                    route.push_back(current);
                }
            }
            int forward = -1;
            cout << start.posX << endl;
            for (int i = 1; i < route.size() + 1; i++)
            {
                int color = 176;
                int mid = 0;
                Position judge;
                if (forward == -1)
                {
                    mid = 0;
                    judge.posX = -1;
                    judge.posX = route[0].posY;
                    color = 207;
                }
                else if (i == route.size())
                {
                    mid = (forward + i) / 2;
                    judge.posX = route[forward].posX - (route[route.size() - 1].posX + 1);
                    judge.posX = route[forward].posY - (route[route.size() - 1].posY);
                    color = 207;
                }
                else
                {
                    mid = (forward + i) / 2;
                    judge = route[forward] - route[i];
                }
                forward = forward + 1;
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
                cout << route[mid].posY << " " << route[mid].posX << endl;
                data[route[mid].posY][route[mid].posX].SetShape(psh);
                data[route[mid].posY][route[mid].posX].setcolor(color);
            }
        }


        void randMap(void)
        {
            for (int i = 0; i < row; i++)
            {
                vector<Pipe> temp;

                for (int j = 0; j < col; j++)
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