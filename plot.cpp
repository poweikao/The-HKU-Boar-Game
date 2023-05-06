// system libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// Include custom header files
#include "plot.h"

// Define clear screen command based on the operating system
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

/**
 * This function prints the game menu.
 */

void print_menu()
{
    system(CLEAR_COMMAND); // clear the console screen
    printf("=============================================\n");
    printf("||      Welcome to the HKU Boar Game!      ||\n");
    printf("=============================================\n\n");

    printf("BACKGROUND: In the year 2043, Hong Kong has been\n");
    printf("overrun by highly intelligent and mischievious\n");
    printf("wild boars. They've now taken control of the city.\n\n");

    printf("SCENARIO: The University of Hong Kong's campus is\n");
    printf("now entirely populated by these wild boars, and as a\n");
    printf("college student, you must face their challenges.\n\n");

    printf("MISSION: Complete three quests given by the boars\n");
    printf("to prove your worth and pass their trials. Can you\n");
    printf("overcome the obstacles and embark on this adventure?\n\n");

    printf("=============================================\n");
    printf("||             About the Game              ||\n");
    printf("=============================================\n\n");
    printf("Please choose an option:\n");
    printf("      <N>: New Game\n");
    printf("      <V>: View Past Game Records\n");
    printf("      <Q>: Quit\n\n");
}

/**
 * This function prints the plots.
 * 
 * Inputs: int stage - where we are at in terms of game progress.
 */

void plot(int stage)
{
    switch (stage)
    {
    case 1:
        // This is what happens in the very beginning

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||           Escape the Boargeddon!        ||\n");
        printf("=============================================\n\n");

        printf("BACKGROUND: In the year 2043, Hong Kong has been\n");
        printf("taken over by a group of highly intelligent and\n");
        printf("mischievous wild boars.\n\n");

        printf("The wild boars now run the city, and they have a\n");
        printf("tendency to lock people in their university campuses.\n\n");

        printf("As a new student at HKU, you find yourself trapped\n");
        printf("on campus with these boars running amok.\n\n");

        printf("It's late afternoon, and you want to get out of the\n");
        printf("school and get home. What can you do?\n\n");

        printf("Complete the wild boars' challenges to uncover clues\n");
        printf("about the boars' plans and the secret to defeating them!\n\n");

        printf("Fear not - you have what it takes to save the day!\n\n");

        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND);
        printf("=============================================\n");
        printf("||      Challenge 1/3: Minesweeping        ||\n");
        printf("=============================================\n\n");

        printf("Welcome to the Minesweeper challenge! The boars\n");
        printf("have planted mines all over the campus, and it's\n");
        printf("up to you to sweep them clean.\n\n");

        printf("This is your first challenge. Your task is to uncover\n");
        printf("all the safe spots on the grid without detonating\n");
        printf("any of the hidden mines.\n\n");

        printf("Each square on the grid contains a hidden number\n");
        printf("that indicates the number of mines in the adjacent\n");
        printf("squares. Use this information to deduce the location\n");
        printf("of the mines.\n\n");

        printf("But be careful - one wrong move and you'll be blown\n");
        printf("to smithereens!\n\n");
        printf("(1/2)\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // to avoid the screen jumping too fast
        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND);
        printf("=============================================\n");
        printf("||      Challenge 1/3: Minesweeping        ||\n");
        printf("=============================================\n\n");

        printf("To uncover a square, simply type in its coordinates.\n");
        printf("If it's safe, you'll see a number pop up indicating\n");
        printf("how many mines are nearby. If it's a mine, the game\n");
        printf("will be over.\n\n");

        printf("There are 4 mines - you have to clear all other 21\n");
        printf("squares, and leave the 4 mines untouched. Only after\n");
        printf("you have identified the 21 safe squares can you proceed.\n\n");

        printf("Use your logical thinking and deduction skills to\n");
        printf("navigate the minefield and emerge victorious. Good\n");
        printf("luck, and watch your step!\n\n");
        printf("(2/2)\n");

        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();
        break;
    case 2:
        // This is what happens when you passed challenge 1 and awaits challenge 2

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||          Challenge 2/3: Snake           ||\n");
        printf("=============================================\n\n");

        printf("Congratulations on completing the Minesweeper\n");
        printf("challenge! You've successfully navigated the\n");
        printf("minefield and swept it clean of boar-planted mines.\n\n");

        printf("But the intelligent wild boars aren't giving up that\n");
        printf("easily. They've issued a new challenge, and it's time\n");
        printf("to put your skills to the test once again.\n\n");

        printf("The challenge is a game of Snake - the classic arcade\n");
        printf("game where you control a growing snake and try to eat\n");
        printf("as many apples as possible without running into your\n");
        printf("own tail.\n\n");
        printf("(1/2)\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear cin stream
        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||          Challenge 2/3: Snake           ||\n");
        printf("=============================================\n\n");

        printf("But this isn't just any game of Snake - because you\n");
        printf("cleared the minefield, now the Wild Boar King has\n");
        printf("heard of you. He's impressed.\n\n");

        printf("The Wild Boar King has promised to reveal information\n");
        printf("about a boars' secret plan if you can successfully\n");
        printf("catch 5 mischievously and randomly spawned apples in\n");
        printf("Snake.\n\n");

        printf("It's a risky game, but you know you can do it. Good\n");
        printf("luck, my fellow HKU challenger!\n\n");
        printf("(2/2)\n");

        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();
        break;
    case 3:
        // This is what happens when you passed challenge 2 and are waiting for challenge 3

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||      Challenge 3/3: Push the Box        ||\n");
        printf("=============================================\n\n");

        printf("Congratulations on completing the Snake challenge!\n");
        printf("You've proven your skills to the Wild Boar King\n");
        printf("himself, and he's come to ask for your help.\n\n");

        printf("The boars have had a powerful crystal stolen from\n");
        printf("them, and they will only release you from the HKU\n");
        printf("campus if you can help them retrieve it back.\n\n");

        printf("The crystal is hidden in a secret chamber deep\n");
        printf("within the campus, guarded by ancient traps and\n");
        printf("its entrance is blocked by a giant iron gate that\n");
        printf("cannot be simply opened.\n\n");
        printf("(1/2)\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||      Challenge 3/3: Push the Box        ||\n");
        printf("=============================================\n\n");

        printf("You must detonate the gate open using TNT. However,\n");
        printf("the wild boars cannot move the TNT because it's too\n");
        printf("heavy for them. They need your strength.\n\n");

        printf("The Wild Boar King knows that you're the only one\n");
        printf("who can push the TNT and clear a path to the chamber.\n");
        printf("He promises to reward you with valuable information\n");
        printf("about the boars' plans if you can succeed.\n\n");

        printf("But it's not going to be easy! The TNT are heavy and\n");
        printf("can only be pushed, not pulled. You'll need to use\n");
        printf("your strategic thinking to maneuver through the\n");
        printf("labyrinth of corridors and create a clear path!\n\n");
        printf("(2/2)\n");

        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();
        break;
    case 4:
        // This is what happens when you passed all challenges in the end

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||           CONNGRATULATIONS!!            ||\n");
        printf("=============================================\n\n");

        printf("Congratulations, you have successfully completed all\n");
        printf("of the challenges. The Wild Boar King and all the wild\n");
        printf("boars are deeply impressed.\n\n");

        printf("But your adventure doesn't end there.\n\n");

        printf("The Wild Boar King approaches you with a strange\n");
        printf("request - to help him create a powerful potion to save\n");
        printf("his prized pig, who has fallen ill with a mysterious\n");
        printf("disease.\n\n");

        printf("With your skills and determination, you gather the\n");
        printf("necessary ingredients and brew the potion, saving the\n");
        printf("pig's life and earning the gratitude of the Wild Boar\n");
        printf("King.\n\n");
        printf("(1/2)\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear cin stream
        printf("\n_____________________________________________\n");
        std::puts("Press Enter to continue...");
        std::cin.get();

        system(CLEAR_COMMAND); // clear the console screen
        printf("=============================================\n");
        printf("||           CONNGRATULATIONS!!            ||\n");
        printf("=============================================\n\n");

        printf("You can finally go home now! But as a token of\n");
        printf("gratitude, the Wild Boar King invites you to a grand\n");
        printf("feast in his honor, where you enjoy a night of\n");
        printf("celebration and laughter.\n\n");

        printf("You make friends with the wild boars and savor the\n");
        printf("joyful night.\n\n");

        printf("Are you still afraid of the wild boars? Fear no more,\n");
        printf("for you now know that whatever life may throw at you,\n");
        printf("you will be here to catch it.\n\n");

        printf("After this event, you know that the boars are no\n");
        printf("longer your threats. Be a proud HKUer and share your\n");
        printf("incredible tale of courage and friendship!\n\n");
        printf("(2/2)\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        break;
    case -1:
        // This is what happens when you fail either one of the challenge

        system(CLEAR_COMMAND); // lear the console screen

        printf("=============================================\n");
        printf("||                GAME OVER                ||\n");
        printf("=============================================\n\n");

        printf("Unfortunately, you were not able to complete one of \n");
        printf("the challenges.\n\n");

        printf("But fear not - there is always a second chance.\n\n");
        printf("You will now be redirected back to the main page...\n");

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return;
    }
}