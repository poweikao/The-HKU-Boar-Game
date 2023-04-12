// system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// our own header files
#include "printer.h"
#include "minesweeper.h"
#include "snake.h"
#include "solitare.h"

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
    int user_choice;
    do
    {
        print_menu();

        // Read user input
        printf("Enter your choice: ");
        std::cin >> user_choice;

        // Handle user input
        int game_score;
        switch (user_choice)
        {
        case 1:
            printf("Starting new game...\n");

            game_score = new_game();
            add_to_leaderboard(game_score, "the time when the score happened");

            break;
        case 2: 
            // not sure if we need to do this
            printf("Showing leaderboard...\n");
            break;
        case 3: 
            // this one works pretty well already ~Paul 4/12/2023
            printf(\n"Exiting game...\n\n");
            exit(0);
            break;
        default: 
            // this one works pretty well already ~Paul 4/12/2023
            printf("Invalid choice. Please try again.\n");
            break;
        }

        // Pause for user to read the screen
        printf("\nPress enter to continue...");
        std::cin.ignore();
        std::cin.get();

    } while (user_choice != 3);
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
    int solitare_score = solitare();
    if (solitare_score < 0)
    {
        plot(-1);
        return -1;
    }
    plot(4); // Plot 4 is what happen after you passed the third chanllenge
    return (minesweeper_score + snake_score + solitare_score);
}

void add_to_leaderboard(int score, string time) {}