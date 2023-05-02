#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Define constants

// Define enum and struct

// Function prototypes

// Main function
int crossroad()
{
    // Do not change name. This function is used in main.cpp
    return 0;
}

// pushbox.cpp
#include "pushbox.h"

Game::Game() {
    map = {
        "########",
        "#P.....#",
        "#..B...#",
        "#.X....#",
        "########",
    };

    playerX = 1;
    playerY = 1;
    boxX = 3;
    boxY = 2;
    goalX = 2;
    goalY = 3;
}

void Game::play() {
    while (!checkWin()) {
        printMap();
        char input;
        std::cin >> input;

        int dx = 0;
        int dy = 0;

        if (input == 'w') {
            dy = -1;
        } else if (input == 's') {
            dy = 1;
        } else if (input == 'a') {
            dx = -1;
        } else if (input == 'd') {
            dx = 1;
        }

        if (movePlayer(dx, dy)) {
            if (playerX + dx == boxX && playerY + dy == boxY) {
                boxX += dx;
                boxY += dy;
            }

            playerX += dx;
            playerY += dy;
        }
    }

    std::cout << "Congratulation HKUer, you win!" << std::endl;
}

void Game::printMap() {
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].length(); x++) {
            if (x == playerX && y == playerY) {
                std::cout << 'P';
            } else if (x == boxX && y == boxY) {
                std::cout << 'B';
            } else if (x == goalX && y == goalY) {
                std::cout << 'X';
            } else {
                std::cout << map[y][x];
            }
        }
        std::cout << std::endl;
    }
}

bool Game::movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (map[newY][newX] == '#') {
        return false;
    }

    if (newX == boxX && newY == boxY) {
        int newBoxX = boxX + dx;
        int newBoxY = boxY + dy;

        if (map[newBoxY][newBoxX] == '#') {
            return false;
        }
    }

    return true;
}

bool Game::checkWin() {
    return boxX == goalX && boxY == goalY;