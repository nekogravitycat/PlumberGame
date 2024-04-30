#include"Game.h"

using namespace std;

int main(void)
{
    Game mainGame(7, 6);
    //mainGame.startGame();
    mainGame.startGameCore(7, 6);
    int r, c;
    while (cin >> r >> c) {
        mainGame.Click(r, c);
        if (mainGame.isItGameOver()) {
            return 0;
        }
    }
}