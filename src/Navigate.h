/************************************
File: Navigate.cpp
Author:
Create Date: 2023/04/20
Editor: Ayr
Update Date: 2023/04/20
Description:
************************************/
#include <vector>
#include "Map.h"

using namespace std;

class Navigate
{
    private:
        Map original_map;
        vector<vector<int>> control;
        int example[4][3][3] = {{{0, 1, 0},
                                {1, 1, 1},
                                {0, 1, 0}},

                               {{0, 0, 0},
                                {1, 1, 1},
                                {0, 0, 0}},

                               {{0, 1, 0},
                                {1, 1, 1},
                                {0, 0, 0}},

                               {{0, 1, 0},
                                {0, 1, 1},
                                {0, 0, 0}}};

    public:
        void input(Map input_map)
        {
            original_map = input_map;
        }
        void create()
        {
            for (int i = 0; i < original_map.getcol() * 3; i++)
            {
                vector<int> temp;
                for (int j = 0; j < original_map.getrow() * 3; j++)
                {
                    temp.push_back(0);
                }
                control.push_back(temp);
            }
            for(int i = 0; i < original_map.getcol(); i++)
            {
                for (int j = 0; j < original_map.getrow(); j++)
                {
                    for (int u = 0; u < 3; u++)
                    {
                        for (int v = 0; v < 3; v++)
                        {
                            Pipe target = original_map.getdata(i, j);
                            control[i * 3 + u][j * 3 + v] = example[target.GetShape()][u][v];
                            //cout <<  control[i * 3 + u][j * 3 + v] << "  " << endl;
                        }
                    }
                }
            }
        }
        void Rotate()
        {

        }
        void Calculate_path()
        {

        }
        void print()
        {
            for (int i = 0; i < original_map.getcol() * 3; i++)
            {
                for (int j = 0; j < original_map.getrow() * 3; j++)
                {
                    SetColor(original_map.getdata(i / 3, j / 3).GetColor());
                    cout << control[i][j];
                }
                cout << endl;
            }
        }
};