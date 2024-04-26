/************************************
File: Navigate.cpp
Author:
Create Date: 2023/04/20
Editor: Ayr
Update Date: 2023/04/21
Description:
************************************/
#include <vector>
#include "Map.h"

using namespace std;

class Navigate
{
    private:
        Map originalMap;
        Map* mapReference;
        vector<vector<int>> control;
        Position current_location;
        int example[4][3][3] = {{{0, 1, 0},
                                 {1, 1, 1},
                                 {0, 1, 0}},

                                {{0, 1, 0},
                                 {0, 1, 0},
                                 {0, 1, 0}},

                                {{0, 1, 0},
                                 {1, 1, 1},
                                 {0, 0, 0}},

                                {{0, 1, 0},
                                 {0, 1, 1},
                                 {0, 0, 0}}};

        int Calculate_direction(Position input_pos)
        {
            Position Displacement;

            for (int i = 0; i < 4; i++)     // 0:right, 1:up, 2:left, 3:down
            {
                switch(i)
                {
                    case 0:
                        Displacement.posX = -1;
                        Displacement.posY = 0;
                        break;
                    case 1:
                        Displacement.posX = 0;
                        Displacement.posY = -1;
                        break;
                    case 2:
                        Displacement.posX = 1;
                        Displacement.posY = 0;
                        break;
                    case 3:
                        Displacement.posX = 0;
                        Displacement.posY = 1;
                        break;
                }

                Calculate_distance(input_pos, Displacement);
            }
        }

        int Calculate_distance(Position input_pos, Position Displacement)
        {
            Position Operation = input_pos + Displacement;

            if (Operation.posX < 0 || Operation.posX >= originalMap.getColumn() * 3)
            {
                return 0;
            }
            else if (Operation.posY < 0 || Operation.posY >= originalMap.getRow() * 3)
            {
                return 0;
            }
            else if (control[Operation.posY][Operation.posX] != 1)
            {
                return 0;
            }
            else
            {
                mapReference->setSelectedWater(Operation.posY / 3, Operation.posX / 3);
                control[Operation.posY][Operation.posX] = 2;
                return Calculate_direction(Operation);
            }
        }

    public:
        void setReference(Map* input)
        {
            mapReference = input;
            //cout << mapReference->getend().posY << endl;
        }

        void input(Map input_map)
        {
            originalMap = input_map;
        }

        void update()
        {
            control.clear();
            create();
            mapReference->resetPipeWater();
        }

        void create()
        {
            for (int i = 0; i < originalMap.getRow() * 3; i++)
            {
                vector<int> temp;

                for (int j = 0; j < originalMap.getColumn() * 3; j++)
                {
                    temp.push_back(0);
                }

                control.push_back(temp);
            }

            for(int i = 0; i < originalMap.getRow(); i++)
            {
                for (int j = 0; j < originalMap.getColumn(); j++)
                {
                    for (int u = 0; u < 3; u++)
                    {
                        for (int v = 0; v < 3; v++)
                        {
                            Pipe target = originalMap.getPipeData(j, i);
                            int indexCol = 0, indexRow = 0;    //col:x, row:y
                            switch(target.GetRotation())
                            {
                                case 0:
                                    indexCol = v;
                                    indexRow = u;
                                    break;
                                case 1:
                                    indexCol = u;
                                    indexRow = 2 - v;
                                    break;
                                case 2:
                                    indexCol = 2 - v;
                                    indexRow = 2 - u;
                                    break;
                                case 3:
                                    indexCol = 2 - u;
                                    indexRow = v;
                                    break;
                            }
                            
                            control[i * 3 + u][j * 3 + v] = example[target.GetShape()][indexRow][indexCol];
                            //cout <<  control[i * 3 + u][j * 3 + v] << "  " << endl;
                        }
                    }
                }
            }
        }

        void Calculate_path()
        {
            current_location = originalMap.getstart() * 3;
            current_location = current_location + 1;
            control[current_location.posY][current_location.posX] = 2;
            //cout << originalMap.getstart().posX << " " << originalMap.getstart().posY << endl;
            Calculate_direction(current_location);
        }

        void print()
        {
            for (int i = 0; i < originalMap.getRow() * 3; i++)
            {
                for (int j = 0; j < originalMap.getColumn() * 3; j++)
                {
                    SetColor(originalMap.getPipeData(j / 3, i / 3).GetColor());

                    if(control[i][j] == 1 && originalMap.getPipeData(j / 3, i / 3).GetColor() != 7)
                    {
                        SetColor(127);
                    }
                    else if(control[i][j] == 2)
                    {
                        SetColor(185);
                    }

                    cout << control[i][j];
                }

                SetColor(7);
                cout << endl;
            }
        }
};