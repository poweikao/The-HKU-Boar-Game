// Include system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

// Include custom header files
#include "plot.h"
#include "minesweeper.h"
#include "snake.h"
#include "pushbox.h"

// Define clear screen command based on the operating system
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Function prototypes
int new_game();

// Main function
int main()
{
    char user_choice;
    do
    {
        // Print the main menu
        print_menu();

        // Read user input
        cout << "Enter your choice: ";
        cin >> user_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear cin stream

        // Handle user input
        switch (toupper(user_choice))
        {
        case 'N':
            cout << "Starting new game..." << endl;
            new_game();
            break;
        case 'Q':
            cout << "\nExiting game...\n\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        // Pause for user to read the screen
        cout << "\n_____________________________________________\n";
        cout << "\nPress enter to continue...";
        cin.get();

    } while (toupper(user_choice) != 'Q');
    return 0;
}

/**
 * Starts a new game by sequentially playing Minesweeper, Snake, and Pushbox.
 *
 * Return: int  - The total score across all games (for debug purposes, not displayed the to players).
 * Returns -1 if any game results in game over.
 */

int new_game()
{
    plot(1);
    int minesweeper_score = minesweeper();
    if (minesweeper_score < 0)
    {
        plot(-1);
        return -1;
    }

    plot(2);
    int snake_score = snake();
    if (snake_score < 0)
    {
        plot(-1);
        return -1;
    }

    plot(3);
    int pushbox_score = pushbox();
    if (pushbox_score < 0)
    {
        plot(-1);
        return -1;
    }

    plot(4);
    return (minesweeper_score + snake_score + pushbox_score);
}