#ifndef PUSHBOX_H
#define PUSHBOX_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int pushbox(); // Do not change name. This function is used in main.cpp

class Game {
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
    bool checkWin();
};

#endif
