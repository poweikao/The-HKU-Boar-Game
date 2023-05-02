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

#define WRAP_LENGTH 50

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
    printf("%-*s\n\n", WRAP_LENGTH, "The time is 2043, the wild boars in Hong Kong has gained intelligence.\n");
    printf("%-*s\n\n", WRAP_LENGTH, "They are occupying the city! The HKU campus are all wild boars! \n");
    printf("%-*s\n\n", WRAP_LENGTH, "As a college student yourself, your goal is complete 3 little quest given by the boars and discovering the secrets. \n\n");
    printf("%-*s\n\n", WRAP_LENGTH, "Can you pass all the chanllenges? Start your joruney now! \n");
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
        printf("||           Escape the Boargeddon!        ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "In the year 2043, Hong Kong has been taken over by a group of highly intelligent and mischievous wild boars.\n");
        printf("%-*s\n\n", WRAP_LENGTH, "s a new student at HKU, you find yourself trapped on campus with these boars running amok.\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Complete the challenges to uncover clues about the boars' plans and the secret to defeating them!\n");
        printf("%-*s\n\n", WRAP_LENGTH, "But fear not - you have what it takes to save the day!\n\n");

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear cin stream
        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND);
        printf("\n_____________________________________________\n");
        printf("=============================================\n");
        printf("||     Chanllenge 1/3: Minesweeping        ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Welcome to the Minesweeper challenge! The boars have planted mines all over the campus, and it's up to you to sweep them clean. Your task is to uncover all the safe spots on the grid without detonating any of the hidden mines.");
        printf("%-*s\n\n", WRAP_LENGTH, "Each square on the grid contains a hidden number that indicates the number of mines in the adjacent squares. Use this information to deduce the location of the mines and mark them with flags.");
        printf("%-*s\n\n", WRAP_LENGTH, "But be careful - one wrong move and you'll be blown to smithereens!");
        printf("%-*s\n\n", WRAP_LENGTH, "To uncover a square, simply type in its coordinates. If it's safe, you'll see a number pop up indicating how many mines are nearby. If it's a mine, you'll hear an explosion and the game will be over.");
        printf("%-*s\n\n", WRAP_LENGTH, "Use your logical thinking and deduction skills to navigate the minefield and emerge victorious. Good luck, and watch your step!");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
    case 2:
        // this is what happen when you passed chanllenge 1 and awaits for chanllenge 2

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||         Chanllenge 2/3: Snake           ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Congratulations on completing the Minesweeper challenge! You've successfully navigated the minefield and swept it clean of boar-planted mines. But the Wild Boar King isn't giving up that easily. He's issued a new challenge, and it's time to put your skills to the test once again.");
        printf("%-*s\n\n", WRAP_LENGTH, "The challenge is a game of Snake - the classic arcade game where you control a growing snake and try to eat as many apples as possible without running into the walls or your own tail.");
        printf("%-*s\n\n", WRAP_LENGTH, "But this isn't just any game of Snake - the boars have rigged the playing field with all sorts of obstacles and hazards to make it more challenging.");
        printf("%-*s\n\n", WRAP_LENGTH, "The Wild Boar King has promised to reveal information about the boars' plans if you can beat him at Snake. It's a risky move, but you know that you need all the intel you can get if you're going to take down the boars and save Hong Kong.");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        break;
    case 3:
        // this is what happen when you passed chanllenge 2 and awaits for chanllenge 3

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||     Chanllenge 3/3: Push the Box        ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Congratulations on completing the Snake challenge! You've proven your skills to the Wild Boar King himself, and he's come to ask for your help.");
        printf("%-*s\n\n", WRAP_LENGTH, "The boars have had a powerful crystal stolen from them, and they need it back in order to carry out their plans. The crystal is hidden in a chamber deep within the campus, but the entrance is blocked by a maze of boxes.");
        printf("%-*s\n\n", WRAP_LENGTH, "The Wild Boar King knows that you're the only one who can push the boxes and clear a path to the chamber. He promises to reward you with valuable information about the boars' plans if you can succeed.");
        printf("%-*s\n\n", WRAP_LENGTH, "But it's not going to be easy! The boxes are heavy and can only be pushed, not pulled. You'll need to use your logic and strategic thinking to maneuver the boxes around obstacles and create a clear path!");
        std::this_thread::sleep_for(std::chrono::seconds(1));

        break;
    case 4:
        // this is what happen when you passed all chanllenges in the end

        system(CLEAR_COMMAND); // clear the console screen
        printf("\n_____________________________________________\n");
        printf("=============================================\n");
        printf("||           CONNGRATULATIONS!!            ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Congratulations, you and your team have successfully completed all of the challenges and saved Hong Kong from the sinister plans of the Wild Boar King.");
        printf("%-*s\n\n", WRAP_LENGTH, "But your adventure doesn't end there. The Wild Boar King approaches you with a strange request - to help him create a powerful potion to save his prized pig, who has fallen ill with a mysterious disease.");
        printf("%-*s\n\n", WRAP_LENGTH, "With your skills and determination, you gather the necessary ingredients and brew the potion, saving the pig's life and earning the gratitude of the Wild Boar King.");
        printf("%-*s\n\n", WRAP_LENGTH, "As a thank you, the Wild Boar King invites you to a grand feast in his honor, where you enjoy a night of celebration and laughter.");
        printf("%-*s\n\n", WRAP_LENGTH, "In the end, you and your team embark on a new adventure, using your skills to help the Wild Boar King and his pigs live happier, healthier lives. It's not the life you expected, but it's a life filled with laughter, friendship, and the occasional boar race. Congratulations on a job well done!");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
    case -1:
        // this is what happen when you fail either one of the chanllenge

        system(CLEAR_COMMAND); // clear the console screen

        printf("=============================================\n");
        printf("||                GAME OVER                ||\n");
        printf("=============================================\n\n");
        printf("%-*s\n\n", WRAP_LENGTH, "Unfortunately, you were not able to complete one of the challenges and the Wild Boar King's plans have succeeded. Hong Kong falls under the control of the boars, and the city is plunged into darkness.");
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