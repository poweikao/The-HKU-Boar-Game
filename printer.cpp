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
    printf("=============================================\n");
    printf("||   Welcome to Let's Visit Hong Kong U!   ||\n");
    printf("=============================================\n\n");
    printf("Explore the campus, solve puzzles, and collect rewards!\n\n");
    printf("Please choose an option:\n");
    printf("1. New Game\n");
    printf("2. Leaderboard\n");
    printf("3. Quit\n\n");
    printf("=============================================\n");
    printf("||             About the Game              ||\n");
    printf("=============================================\n\n");
    printf("Wild boars are occupying the way from your Hall to the HKU campus! \n");
    printf("Can you arrive at the school safely? \n\n");
    printf("\n_____________________________________________\n");
}

void plot(int stage) // use this function to print out all the dialog / plots
{
    switch (stage)
    {
    case 1:
        // this is what happen in the very beginning

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 1/3: Minesweeping        ||\n");
        printf("=============================================\n\n");
        printf("Legend has that there were once many wild boars in the HKU campus\n");

        break;
    case 2:
        // this is what happen when you passed chanllenge 1 and awaits for chanllenge 2

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 2/3: Cross Roads         ||\n");
        printf("=============================================\n\n");
        printf("Congratulations, Chanllenger! We have now cleared the mines, and are movinig into the second chanllenge\n");
        printf("We need to cross the crowded Pokfulam Road\n");

        break;
    case 3:
        // this is what happen when you passed chanllenge 2 and awaits for chanllenge 3

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 3/3: Snake               ||\n");
        printf("=============================================\n\n");
        printf("We may have crossed the road now... But the chanllenge is not yet\n");
        printf("Awaits us is the Wild Boar Prince!\n");

        break;
    case 4:
        // this is what happen when you passed all chanllenges in the end

        system(CLEAR_COMMAND); // clear the console screen
        printf("We have successfully passed through all the chanllenges\n");

        break;
    case -1:
        // this is what happen when you fail either one of the chanllenge

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||                GAME OVER                ||\n");
        printf("=============================================\n\n");
        printf("Oops. Failed.\n");

        break;
    }

    // the following code somehow performs the "Press any key to continue function"
    printf("\n_____________________________________________\n");
    std::puts("Press any key to continue...");
    std::getchar();
}

int main()
{
    // executable main function code, for testing purposes
    print_menu();
    std::puts("TESTING IN PROGRESS: Press any key to continue...");
    std::getchar();
    for (int element : {1, 2, 3, 4, -1})
    {
        plot(element);
    }
}