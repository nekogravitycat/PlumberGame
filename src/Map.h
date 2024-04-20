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
#include<time.h>
#include <vector>
#include <cmath>
#include "Pipe.h"
#include "Position.h"
#include "Color.h"

using namespace std;

class Map
{
    private:
        vector<vector<Pipe>> data;
        vector<Position> route;
        Position start, end;
        int col, row;
        int direction;

    public:
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

        void setSize(int inputCol, int inputRow)
        {
            col = inputCol;
            row = inputRow;
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
        int getcol()
        {
            return col;
        }
        int getrow()
        {
            return row;
        }
        Pipe getdata(int input_x, int input_y)
        {
            return data[input_x][input_y];
        }
        void randMap()
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

        void randroute()
        {
            Position current = start;
            if(start.posY < end.posY)
            {
                direction = 1;
            }
            else
            {
                direction = -1;
            }
            route.push_back(start);
            for (int i = 0;;i++)
            {
                int rand_num = rand() % 2;
                switch(rand_num)
                {
                    case 0:
                        if(current.posX != end.posX)
                        {
                            current.posX = current.posX + 1;
                        }
                        else
                        {
                            current.posY = current.posY + direction;
                        }
                        break;
                    case 1:
                        if(current.posY != end.posY)
                        {
                            current.posY = current.posY + direction;
                        }
                        else
                        {
                            current.posY = current.posY + 1;
                        }
                        break;
                    default:
                        break;
                }
                route.push_back(current);
                //cout << current.pos_x << "  " << end.pos_x << "  " << current.pos_y << "  " << end.pos_y << endl;
                if (current == end)
                {
                    break;
                }
            }
            /*for (int i = 0; i < route.size(); i++)
            {
                data[route[i].pos_y][route[i].pos_x].setcolor(176);
            }*/
            int forward = 0;
            for (int i = 2; i < route.size(); i++)
            {
                int mid = (forward + i) / 2;
                //cout << forward << " " << i << " " << mid << endl;
                Position judge = route[forward] - route[i];
                forward = forward + 1;
                pShape psh;
                int color = 0;
                int rnad_num = rand() % 3;
                if (judge.posX == 0 || judge.posY == 0)
                {
                    switch(rnad_num)
                    {
                        case 0:
                            psh = CROSS;
                            color = 176;
                            break;
                        case 1:
                            psh = STRA;
                            color = 225;
                            break;
                        case 2:
                            psh = TEE;
                            color = 144;
                            break;
                    }
                }
                else
                {
                    switch(rnad_num)
                    {
                        case 0:
                            psh = CROSS;
                            color = 176;
                            break;
                        case 1:
                            psh = TEE;
                            color = 144;
                            break;
                        case 2:
                            psh = ELBOW;
                            color = 127;
                            break;
                    }
                }
                data[route[mid].posY][route[mid].posX].SetShape(psh);
                data[route[mid].posY][route[mid].posX].setcolor(color);
            }
        }

        void printdata() //test
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
};