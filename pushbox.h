#ifndef PUSHBOX_H
#define PUSHBOX_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "snake.h"

enum class WinningCondition
{
    WIN,
    LOSS,
    NOT_YET
};

class Game
{
public:
    Game();
    void play();

private:
    std::vector<std::string> map;
    int playerX, playerY;
    int boxX, boxY;
    int goalX, goalY;

    void printMap();
    bool movePlayer(int dx, int dy);
    bool moveBox(int dx, int dy);
    void update_direction(Direction &direction);
    bool movePlayerBox(int dx, int dy);
    WinningCondition checkWin();
};

int pushbox(); // Function name changed to match implementation

#endif
