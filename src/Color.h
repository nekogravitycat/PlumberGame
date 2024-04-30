/************************************
File: Color.h
Author:Ayr
Create Date: 2023/04/19
Editor: Ayr
Update Date: 2023/04/30
Description:
************************************/
#include<windows.h>

using namespace std;

void SetColor(int inputColor = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,inputColor);
}