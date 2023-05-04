// system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

// our own header files
#include "printer.h"
#include "minesweeper.h"
#include "snake.h"
#include "pushbox.h"

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Function prototypes
int new_game();
void add_to_leaderboard(int game_score, string time);

int main()
{
    char user_choice;
    do
    {        
        print_menu();

        // Read user input
        printf("Enter your choice: ");
        std::cin >> user_choice;

        

        // Handle user input
        switch (user_choice)
        {
        case 'N':
            printf("Starting new game...\n");
            new_game();
            break;
        case 'Q':
            // this one works pretty well already ~Paul 4/12/2023
            printf("\nExiting game...\n\n");
            exit(0);
            break;
        default:
            // this one works pretty well already ~Paul 4/12/2023
            printf("Invalid choice. Please try again.\n");
            break;
        }

        // Pause for user to read the screen
        printf("\n_____________________________________________\n");
        printf("\nPress enter to continue...");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear cin stream
        std::cin.get();

    } while (user_choice != 'Q');
    return 0;
}

int new_game() // this function returns the total score. -1 signifies game over
{
    plot(1); // plots are defined in the printers. Plot 1 is the beginning
    int minesweeper_score = minesweeper();
    if (minesweeper_score < 0)
    {              // a lesser than 0 score means you have failed the mission, and it's game over
        plot(-1);  // plot(-1) is the failure plot
        return -1; // return -1 means game over
    }
    plot(2); // Plot 2 is what happen after you passed the first chanllenge
    int snake_score = snake();
    if (snake_score < 0)
    {
        plot(-1);
        return -1;
    }
    plot(3); // Plot 3 is what happen after you passed the second chanllenge
    int pushbox_score = pushbox();
    if (pushbox_score < 0)
    {
        plot(-1);
        return -1;
    }
    plot(4); // Plot 4 is what happen after you passed the third chanllenge
    return (minesweeper_score + snake_score + pushbox_score);
}