#include"Map.h"

using namespace std;

int main(void)
{
    Map pipeGame(5, 10);
    pipeGame.randMap();
    pipeGame.randroute();
    pipeGame.printdata();
    return 0;
}