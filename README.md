# comp2113 Project - The HKU Boar Game

## Team Members

- Kao Po-wei
- Huang Xiaolin

## Main Story Line

In 2043, Hong Kong was taken over by a group of highly intelligent and mischievous wild boars. As a new student at HKU, you find yourself trapped on campus with these boars running amok. The boars have planted mines all over the campus, and it's up to you to sweep them clean.

The Wild Boar King isn't giving up that easily after you successfully swept all the mines - let me remind you. Instead, he's issued a new challenge, and it's time to put your skills to the test once again. The Wild Boar King's challenge is a game of Snake - the classic arcade game where you control a growing snake and try to eat as many apples as possible without running into the walls or your tail. 

It turned out that after you've proven your skills to the Wild Boar King, he's come to ask for your help. The boars have had a powerful crystal stolen from them, and they need it back to carry out their plans. The crystal is hidden in a chamber deep within the campus, but a maze of boxes blocks the entrance. The Wild Boar King knows you're the only one who can push the boxes and clear a path to the chamber. 

Complete the challenges to uncover clues about the boars' plans and the secret to defeating them. But fear not - you have what it takes to save the day!

## Game Rules

1. Have fun
2. There are 3 games - minesweeper, snake and push box
3. Pass through the 3 games and you will win
4. Fail either one of them, and you lose

## Coding Features and Requirements Matched

### Interactive Interface

The HKU Boar Game comprises of 4 major parts - the main interface, the minesweeper game, the snake game, and the push box game. In the minesweeper game, the program is able to detect and compare the input of users against the answer board and the current game status. In the snake game and the push box game, player's movements are recorded into the `Position` struct, which will then be manipulated, recorded, and updated based on the user arrow key inputs. 

(Requirement 2: Data structures for storing game status)

### Dynamic Memory Management

The HKU Boar Game leverages a lot of dynamic memory management to save memories and avoid `stack smashed` errors. For example, in the snake game, the game board that contains the snake and the walls are recorded in `char** board[][]`, which is an 2D array of pointers. The values that the pointers point to are later in the code assigned and manipulated. 

(Requirement 3: Dynamic memory management)

### Random Mines, Snake Fruits, and Boxes

As essential features in any arcade game, all of our 3 mini arcade games (minesweeper, snake, push box) contains randomly generated datasets. In the minesweeper game, it is the locations of the mines that are randomly generated. In the snake game, it is the locations of the apples that are randomly gnerated. And for the push the box game, the initial location of the player and the initial location of the box are all randomly generated. 

(Requirement 1: Generation of random game sets or events)

### Three Mini Games - All In One

Each mini arcade games are its own .cpp and .h files. In addition, the plot of the game has its own .cpp and .h files as well. They are all linked by the Makefile. 

(Requirement 5: Program codes in multiple files)


## Non-standard Libraries

* ncurses - This library is used for handling the terminal screen in non-Windows environments. The printMap function uses ncurses functions such as printw, clear, and refresh.

## Compilation and Execution Instructions on Linux

1. Clone the GitHub repository at `https://github.com/poweikao/The-HKU-Boar-Game.git`
2. Navigate to the project folder in the terminal.
3. Compile the program using the following command: `make all`
4. ncurses.h should download itself.
5. Run the compiled executable to play the game: `./THE_HKU_BOAR_GAME`

## Compiling  options

* `make all` will download ncurses and compile the entire game for you. 
* `make clean` will delete all .o files and executables, but it doesn't uninstall ncurses. 
* `make deep_clean` will delete all intemediary files and uninstall ncurses. 
* `make ncurses` downloads ncurses only.

## References

This code has referred and/or directly quoted codes from the following sources. We tried to modify the codes as much as we can, but for downoading and installing ncurses, it is way beyond our capacity. You would find the file `buildncurses.sh` to be very similar to the many samples you would find online.  

- Ncurses library
- https://github.com/Colton-Ko/tetris-in-ncurses/ for how to install ncurses on Linux and buildncurses.sh
- https://cloud.tencent.com/developer/ask/sof/108501626 for reading arrow key inputs
- https://stackoverflow.com/questions/5437643/strange-behaviour-of-stdcout-in-linux
- https://stackoverflow.com/questions/903221/press-enter-to-continue
- https://www.devopsschool.com/blog/make-for-windows-nmake/