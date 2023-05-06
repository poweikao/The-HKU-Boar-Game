// Include system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
#include <fstream>
#include <iomanip>

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
int new_game(const string &player_name);
void save_log(const std::string &player_name, const bool &game_won);

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
        string player_name;
        switch (toupper(user_choice))
        {
        case 'N':
            cout << "Enter your name: ";
            getline(cin, player_name);

            cout << "Starting new game for " << player_name << "..." << endl;
            new_game(player_name);
            break;

        case 'V':
            cout << "\n_____________________________________________\n"
                 << "Displaying game log...\n"
                 << endl;
            system("cat game_log.txt");
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
 * This function starts a new game by sequentially playing Minesweeper, Snake, and Pushbox
 *
 * Return: int  - The total score across all games (for debug purposes, not displayed the to players)
 * Returns -1 if any game results in game over
 *
 * It takes the player's name as an input. This function passes the player name over to the file-writing function
 */

int new_game(const string &player_name)
{
    plot(1);
    int minesweeper_score = minesweeper();
    if (minesweeper_score < 0)
    {
        plot(-1);
        save_log(player_name, false);
        return -1;
    }

    plot(2);
    int snake_score = snake();
    if (snake_score < 0)
    {
        plot(-1);
        save_log(player_name, false);
        return -1;
    }

    plot(3);
    int pushbox_score = pushbox();
    if (pushbox_score < 0)
    {
        plot(-1);
        save_log(player_name, false);
        return -1;
    }

    // This is the winning plot
    plot(4);
    save_log(player_name, true);
    return (minesweeper_score + snake_score + pushbox_score);
}

/**
 * This function records the game attempts into a .txt file
 *
 * Return: void. But it will write something onto the file
 * This function takes the player's name and that whther he/she has won or not as the input
 */

void save_log(const std::string &player_name, const bool &game_won)
{
    std::ofstream log_file("./game_log.txt", std::ios::app | std::ios::out);

    if (log_file.is_open())
    {
        // Get the current time
        auto now = time(nullptr);
        auto tm_now = *localtime(&now);

        // Write the log entry
        log_file << std::put_time(&tm_now, "%Y-%m-%d %H:%M") << " ";
        log_file << (game_won ? "GAME_WIN" : "GAME_LOSS") << " ";
        log_file << player_name << endl;

        log_file.close();
    }
    else
    {
        cerr << "Unable to open the log file." << endl;
    }
}
