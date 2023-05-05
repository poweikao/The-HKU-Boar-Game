// Include system libraries
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <chrono>
#include <thread>

// Include custom header files
#include "pushbox.h"
#include "snake.h"

// Define clear screen command based on the operating system
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"
#include <ncurses.h>
#endif

// Function Prototypes
void update_direction(Direction &direction);

// Define board size.
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 8

using namespace std;

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

// Game constructor
// Initializes the game by setting up the map, player, box, and goal positions
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

// Main game loop
// Plays the game until a win or loss condition is reached
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

        // Attempt to move the player and update the player and box positions accordingly
        // Check if the player can move and update the winCondition accordingly
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

    // Print the appropriate message based on the WinningCondition
#ifdef _WIN32
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
// Function: printMap
// Inputs: None
// Outputs: None (prints the current state of the game map to the console)
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

    for (const auto &row : map) // <-- Dynamic memory management is used here
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
// Function: printMap
// Inputs: None
// Outputs: None (prints the current state of the game map to the console)
void Game::printMap()
{
    std::system(CLEAR_COMMAND);

    map[playerY][playerX] = 'P';
    map[boxY][boxX] = 'B';
    map[goalY][goalX] = 'X';

    clear(); // Clear the screen in ncurses

    printw("\nPush The Box Challenge\n");
    printw("Please use arrow keys to push the box (B) to the treasure chamber (X).\n\n");

    for (const auto &row : map) // <-- Dynamic memory management is used here
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

// This function kind of move players
// Inputs: dx (int) - change in x position, dy (int) - change in y position
// Outputs: bool - true if the player can move to the new position, false otherwise
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

// The function checks if you have won
// Inputs: None
// Outputs: WinningCondition - the current status of the game (WIN, LOSS, or NOT_YET)
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

// This function move boxes
// Inputs: dx (int) - change in x position, dy (int) - change in y position
// Outputs: bool - true if the player can move the box to the new position, false otherwise
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

// Updates the snake's direction based on the user's key input.
void update_direction(Direction &direction)
{
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