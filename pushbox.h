#ifndef PUSHBOX_H
#define PUSHBOX_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "snake.h" // For the Direction enum class

// Enum class representing the possible winning conditions
enum class WinningCondition
{
    WIN,
    LOSS,
    NOT_YET
};

// A class representing the Pushbox game, including the game state,
// player and box positions, and methods to manage the game loop and logic
class Game
{
public:
    // Constructor
    Game();

    // Main method to play the Pushbox game
    void play();

private:
    // Private member variables for the Pushbox game
    std::vector<std::string> map;
    int playerX, playerY;
    int boxX, boxY;
    int goalX, goalY;

    // Private helper methods for managing the Pushbox game
    void printMap();
    void update_direction(Direction &direction);
    bool movePlayer(int dx, int dy);
    bool moveBox(int dx, int dy);
    bool movePlayerBox(int dx, int dy);
    WinningCondition checkWin();
};

// Main function for the Pushbox game
int pushbox();

#endif