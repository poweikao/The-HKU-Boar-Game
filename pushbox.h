#ifndef PUSHBOX_H
#define PUSHBOX_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

int pushbox(); // Function name changed to match implementation

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
    bool moveBox(int dx, int dy);
    bool checkWin();
    bool checkLose();
};

#endif

