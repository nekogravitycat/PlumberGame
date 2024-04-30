/***********************************************************************
 * File: Color.cpp
 * Author: ayr, Gravity cat
 * Create Date: 2024/5/1
 * Editor: Gravity cat
 * Update Date: 2024/5/1
 * Description: SetColor function
***********************************************************************/
#include "Color.h"

void SetColor(int inputColor) {
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, inputColor);
}
