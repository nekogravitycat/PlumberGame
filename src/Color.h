/***********************************************************************
 * File: Color.h
 * Author: Ayr
 * Create Date: 2023/04/19
 * Editor: Ayr, Gravity cat
 * Update Date: 2024/5/1
 * Description: Header for color class
***********************************************************************/
#pragma once

#include<windows.h>

// Intent: To set the color of the console text
// Pre: inputColor must be an integer representing a valid console color code
// Post: Sets the color of the console text to inputColor, defaulting to color code 7 (white)
void SetColor(int inputColor = 7);