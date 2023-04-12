// system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

void print_menu()
{
    system(CLEAR_COMMAND); // clear the console screen
    printf("===========================================\n");
    printf("||  Welcome to Let's Visit Hong Kong U!  ||\n");
    printf("===========================================\n\n");
    printf("Explore the campus, solve puzzles, and collect rewards!\n\n");
    printf("Please choose an option:\n");
    printf("1. New Game\n");
    printf("2. Leaderboard\n");
    printf("3. Quit\n\n");
    printf("===========================================\n");
    printf("||            About the Game             ||\n");
    printf("===========================================\n\n");
    printf("Let's Visit Hong Kong U is an adventure game where you explore the campus and solve puzzles to unlock rewards. \n");
    printf("Can you arrive at the school safely? \n\n");
}

void plot(int stage) // use this function to print out all the dialog / plots
{
    switch (stage)
    {
    case 1:
        // this is what happen in the very beginning
        break;
    case 2:
        // this is what happen when you passed chanllenge 1 and awaits for chanllenge 2
        break;
    case 3:
        // this is what happen when you passed chanllenge 2 and awaits for chanllenge 3
        break;
    case 4:
        // this is what happen when you passed all chanllenges in the end
        break;
    case -1:
        // this is what happen when you fail either one of the chanllenge
        break;
    }
}