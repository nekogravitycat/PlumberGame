/************************************
File: Color.h
Author:
Create Date: 2023/04/19
Editor: Ayr
Update Date: 2023/04/19
Description:
************************************/
#include<windows.h>

using namespace std;

void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}