/************************************
File: Position.h
Author:
Create Date: 2023/04/19
Editor: Ayr
Update Date: 2023/04/19
Description:
************************************/

class Position
{
    private:
    public:
        int posX = 0;
        int posY = 0;

        const Position operator+(const Position& input)
        {
            Position output;
            output.posX = posX + input.posX;
            output.posY = posY + input.posY;
            return output;
        }
        const Position operator-(const Position& input)
        {
            Position output;
            output.posX = posX - input.posX;
            output.posY = posY - input.posY;
            return output;
        }
        bool operator==(const Position& input)
        {
            bool output = false;
            if(posX == input.posX && posY == input.posY)
            {
                output = true;
            }
            return output;
        }
};