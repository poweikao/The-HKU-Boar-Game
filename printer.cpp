// system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>

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
    printf("Please choose an option:\n\n");
    printf("    <N>: New Game\n");
    printf("    <Q>: Quit\n\n");
    printf("=============================================\n");
    printf("||             About the Game              ||\n");
    printf("=============================================\n\n");
    printf("The time is 2043, the wild boars in Hong Kong has gained intelligence.\n");
    printf("They are occupying the city! The way from your Hall to the HKU campus are all wild boars! \n");
    printf("As a college student yourself, your goal is to arrive at the school safely. \n\n");
    printf("Can you pass all the chanllenges? Start your joruney to the school now! \n");
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
        printf("Legend has that there were once many wild boars in the HKU campus\n\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        break;
    case 2:
        // this is what happen when you passed chanllenge 1 and awaits for chanllenge 2

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 2/3: Cross Roads         ||\n");
        printf("=============================================\n\n");
        printf("Congratulations, Chanllenger! We have now cleared the mines.\n\n");
        printf("We are movinig into the second chanllenge.\n\n");
        printf("We need to cross the crowded Pokfulam Road\n\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        break;
    case 3:
        // this is what happen when you passed chanllenge 2 and awaits for chanllenge 3

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 3/3: Snake               ||\n");
        printf("=============================================\n\n");
        printf("We may have crossed the road now... But the chanllenge is not yet completed.\n\n");
        printf("Awaits us is the Wild Boar Prince!\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        break;
    case 4:
        // this is what happen when you passed all chanllenges in the end

        system(CLEAR_COMMAND); // clear the console screen
        printf("We have successfully passed through all the chanllenges\n\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
    case -1:
        // this is what happen when you fail either one of the chanllenge

        system(CLEAR_COMMAND); // clear the console screen
        
        printf("=============================================\n");
        printf("||                GAME OVER                ||\n");
        printf("=============================================\n\n");
        printf("Oops. Failed.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
    }

    // the following code somehow performs the "Press any key to continue function"
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear cin stream
    printf("\n_____________________________________________\n");
    std::puts("Press Enter to continue...");
    std::cin.get();
}

/* int main() // If you directly compile this .cpp file, this function make sure that we have something to run
{
    // Specifically, what this main() does is that it prints all our plots and menus for debugging purposes.

    print_menu();
    std::puts("TESTING IN PROGRESS: Press any key to continue...");
    std::getchar();
    for (int element : {1, 2, 3, 4, -1})
    {
        plot(element);
    }
} */