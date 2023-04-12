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

using namespace std;

enum CurrentLevel
{
    BOAR1,
    BOAR2,
    BOAR3
};

void print_menu()
{
    system(CLEAR_COMMAND); // clear the console screen
    printf("===========================================\n");
    printf("||  Welcome to Let's Visit Hong Kong U!  ||\n");
    printf("===========================================\n\n");
    printf("Explore the campus, solve puzzles, and collect rewards!\n\n");
    printf("Please choose an option:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Leaderboard\n");
    printf("4. Quit\n\n");
    printf("===========================================\n");
    printf("||            About the Game             ||\n");
    printf("===========================================\n\n");
    printf("Let's Visit Hong Kong U is an adventure game where you explore the campus and solve puzzles to unlock rewards. \n");
    printf("Can you arrive at the school safely? \n\n");
}

void welcome_screen()
{
    int user_choice;
    do
    {
        print_menu();

        // Read user input
        printf("Enter your choice: ");
        std::cin >> user_choice;

        // Handle user input
        switch (user_choice)
        {
        case 1:
            printf("Starting new game...\n");
            break;
        case 2:
            printf("Loading game...\n");
            break;
        case 3:
            printf("Showing leaderboard...\n");
            break;
        case 4:
            printf("Exiting game...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        // Pause for user to read the screen
        printf("\nPress enter to continue...");
        std::cin.ignore();
        std::cin.get();
    } while (user_choice != 4);
}

main()
{
    welcome_screen();
}