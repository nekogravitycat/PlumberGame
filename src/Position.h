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
        int pos_x = 0;
        int pos_y = 0;
        const Position operator+(const Position& input)
        {
            Position output;
            output.pos_x = pos_x + input.pos_x;
            output.pos_y = pos_y + input.pos_y;
            return output;
        }
        const Position operator-(const Position& input)
        {
            Position output;
            output.pos_x = pos_x - input.pos_x;
            output.pos_y = pos_y - input.pos_y;
            return output;
        }
        bool operator==(const Position& input)
        {
            bool output = false;
            if(pos_x == input.pos_x && pos_y == input.pos_y)
            {
                output = true;
            }
            return output;
        }
};