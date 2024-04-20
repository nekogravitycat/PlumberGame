/************************************
File: Pipe.h
Author:
Create Date: 2023/04/18
Editor: Ayr
Update Date: 2023/04/19
Description:
************************************/
enum pShape
{
    CROSS = 0,
    STRA = 1,
    TEE = 2,
    ELBOW = 3
};

class Pipe
{
    private:
        pShape shape;
        int rotation; // See the note above (0 ~ 3)
        int color = 7;
    public:
        //Pipe Getpipe(char _shape, int _rotation);
        char GetShape()
        {
            return shape;
        }

        int GetRotation()
        {
            return rotation;
        }

        int GetColor()
        {
            return color;
        }

        void SetShape(pShape _shape)
        {
            shape = _shape;
        }

        void SetRotation(int _rotation)
        {
            rotation = _rotation;
        }

        void setcolor(int _color)
        {
            color = _color;
        }
        
        void Rotate()
        {
            rotation = (rotation + 1) % 4;
        }
};