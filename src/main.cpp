#include"Map.h"

using namespace std;

int main(void)
{
    Map pipeGame(10, 10);
    pipeGame.randMap();
    pipeGame.randroute();
    pipeGame.printdata();
}