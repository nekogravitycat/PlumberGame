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
        vector<vector<int>> control;
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

    public:
        void input(Map input_map)
        {
            originalMap = input_map;
        }

        void update()
        {
            control.clear();
            create();
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
                        cout << control[i][j];
                    }
                    else
                    {
                        cout << control[i][j];
                    }
                }

                SetColor(7);
                cout << endl;
            }
        }
};