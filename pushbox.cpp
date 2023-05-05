#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "pushbox.h"
#include "snake.h"

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"
#include <ncurses.h>
#endif

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 8

using namespace std;

#include <chrono>
#include <thread>

// Main function

int pushbox()
{
#ifdef __linux__
    initscr();  // Initialize ncurses
    timeout(0); // Set input to non-blocking mode
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
#endif
    Game game;
    game.play();
#ifdef __linux__
    endwin(); // Clean up the terminal
#endif
    return 0;
}

//////////////

Game::Game()
{
    // Define the map
    const int mapWidth = BOARD_WIDTH;
    const int mapHeight = BOARD_HEIGHT;
    map.resize(mapHeight);
    for (int i = 0; i < mapHeight; i++)
    {
        map[i].resize(mapWidth, '.');

        if (i == 0 || i == mapHeight - 1)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                map[i][j] = '#';
            }
        }
        else
        {
            map[i][0] = '#';
            map[i][mapWidth - 1] = '#';
        }
    }

    // Seed the random number generator with the current time
    srand(time(0));

    // Generate random positions for the player, box, and goal
    do
    {
        do
        {
            playerX = rand() % (mapWidth - 2) + 1;
            playerY = rand() % (mapHeight - 2) + 1;
            boxX = rand() % (mapWidth - 2) + 1;
            boxY = rand() % (mapHeight - 2) + 1;
            goalX = rand() % (mapWidth - 2) + 1;
            goalY = rand() % (mapHeight - 2) + 1;

            // Check if the box is not beside a wall
        } while (!(map[boxY][boxX] == '.' && map[boxY - 1][boxX] == '.' && map[boxY + 1][boxX] == '.' && map[boxY][boxX - 1] == '.' && map[boxY][boxX + 1] == '.'));
    } while ((playerX == boxX && playerY == boxY) || (playerX == goalX && playerY == goalY) || (boxX == goalX && boxY == goalY));
}

void Game::play()
{
    printMap();
    WinningCondition winCondition = WinningCondition::NOT_YET;
    while (winCondition == WinningCondition::NOT_YET)
    {
        Direction direction = Direction::NONE;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update_direction(direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update_direction(direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update_direction(direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update_direction(direction);

        int dx = 0;
        int dy = 0;

        switch (direction)
        {
        case Direction::UP:
            dy = -1;
            break;
        case Direction::DOWN:
            dy = 1;
            break;
        case Direction::LEFT:
            dx = -1;
            break;
        case Direction::RIGHT:
            dx = 1;
            break;
        case Direction::NONE:
            break;
        }

        if (movePlayer(dx, dy))
        {
            if (playerX + dx == boxX && playerY + dy == boxY)
            {
                // Check if the box can be moved and update winCondition accordingly
                if (movePlayerBox(dx, dy))
                {
                    playerX += dx;
                    playerY += dy;
                }
                else
                {
                    winCondition = WinningCondition::LOSS;
                }
            }
            else
            {
                playerX += dx;
                playerY += dy;
            }
        }

        printMap();
        // Update winCondition based on the result of checkWin
        winCondition = checkWin();
    }

#ifdef _WIN32
    // Print the appropriate message based on the WinningCondition
    if (winCondition == WinningCondition::WIN)
    {
        std::cout << "\nCongratulation HKUer, you win!\n"
                  << std::endl;
    }
    else if (winCondition == WinningCondition::LOSS)
    {
        std::cout << "\nSorry, you lost. Try again!\n"
                  << std::endl;
    }
#else
    if (winCondition == WinningCondition::WIN)
    {
        printw("\nCongratulation HKUer, you win!\n\n");
    }
    else if (winCondition == WinningCondition::LOSS)
    {
        printw("\nSorry, you lost. Try again!\n\n");
    }
#endif
}

#ifdef _WIN32
void Game::printMap()
{
    std::system(CLEAR_COMMAND);

    map[playerY][playerX] = 'P';
    map[boxY][boxX] = 'B';
    map[goalY][goalX] = 'X';

    cout << endl
         << "Push The Box Chanllenge" << endl
         << "Please use arrow keys to push the box (B) to the treasure chamber (X)." << endl
         << endl;

    for (const auto &row : map)
    {
        std::cout << ' ' << row << std::endl;
    }

    cout << endl
         << "You automatically loses if the box is pushed to the corner.";

    map[playerY][playerX] = '.';
    map[boxY][boxX] = '.';
    map[goalY][goalX] = '.';
}
#else
void Game::printMap()
{
    std::system(CLEAR_COMMAND);

    map[playerY][playerX] = 'P';
    map[boxY][boxX] = 'B';
    map[goalY][goalX] = 'X';

    clear(); // Clear the screen in ncurses

    printw("\nPush The Box Challenge\n");
    printw("Please use arrow keys to push the box (B) to the treasure chamber (X).\n\n");

    for (const auto &row : map)
    {
        printw(" %s\n", row.c_str());
    }

    printw("\nYou automatically lose if the box is pushed to the corner.\n");

    refresh(); // Refresh the screen in ncurses

    map[playerY][playerX] = '.';
    map[boxY][boxX] = '.';
    map[goalY][goalX] = '.';
}
#endif

bool Game::movePlayer(int dx, int dy)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (map[newY][newX] == '#')
    {
        return false;
    }

    if (newX == boxX && newY == boxY)
    {
        int newBoxX = boxX + dx;
        int newBoxY = boxY + dy;

        if (map[newBoxY][newBoxX] == '#')
        {
            return false;
        }
    }

    return true;
}

WinningCondition Game::checkWin()
{
    WinningCondition winCondition = WinningCondition::NOT_YET;

    // Check if box is at a corner and cannot be moved
    if ((boxX == 1 && boxY == 1) || (boxX == 1 && boxY == 6) || (boxX == 8 && boxY == 1) || (boxX == 8 && boxY == 6))
    {
        winCondition = WinningCondition::LOSS;
    }
    // Check if box has reached the goal
    else if (boxX == goalX && boxY == goalY)
    {
        winCondition = WinningCondition::WIN;
    }

    return winCondition;
}

bool Game::movePlayerBox(int dx, int dy)
{
    if (map[boxY + dy][boxX + dx] == '#')
    {
        return false;
    }

    boxX += dx;
    boxY += dy;

    return true;
}

// Direction-getting related utilities
void Game::update_direction(Direction &direction)
{ // this piece of code is delicate. Don't change it.
// Detect operating system
#ifdef _WIN32
  // Windows
    if (_kbhit())
    {
        switch (_getch())
        {
        case 72: // Arrow up
            direction = Direction::UP;
            break;
        case 80: // Arrow down
            direction = Direction::DOWN;
            break;
        case 75: // Arrow left
            direction = Direction::LEFT;
            break;
        case 77: // Arrow right
            direction = Direction::RIGHT;
            break;
        }
    }
#else
// Linux
#include <ncurses.h>
    int ch = getch();
    if (ch != ERR)
    {
        switch (ch)
        {
        case KEY_UP: // Arrow up
            direction = Direction::UP;
            break;
        case KEY_DOWN: // Arrow down
            direction = Direction::DOWN;
            break;
        case KEY_LEFT: // Arrow left
            direction = Direction::LEFT;
            break;
        case KEY_RIGHT: // Arrow right
            direction = Direction::RIGHT;
            break;
        }
    }
#endif
}
