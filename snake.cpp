// Include system libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <thread>

// Include custom header files
#include "snake.h"

// Define clear screen command based on the operating system
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"
#include <ncurses.h>
#endif

//Function Prototypes
void update_direction(Direction &direction);

using namespace std;

// Main function
// Entry point for the snake game
int snake()
{
    // Do not change name. This function is used in main.cpp
    SnakeGame new_game;    // Create a new SnakeGame object
    return new_game.run(); // Start the game and return the final result
}

// SnakeGame constructor
SnakeGame::SnakeGame()
{
    // Allocate memory for the board
    board = new char *[BOARD_HEIGHT];
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        board[i] = new char[BOARD_WIDTH];
    }

    initialize_game(); // Initialize the game state
}

// SnakeGame destructor
SnakeGame::~SnakeGame()
{
    // Deallocate memory for the board
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

// Main game loop
// Returns 1 if the player wins, -1 if the player loses
int SnakeGame::run()
{
    GameOver game_status = GameOver::NOT_YET; // Initialize the game status

#ifdef __linux__
    initscr();  // Initialize ncurses
    timeout(0); // Set input to non-blocking mode
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
#endif

    // Game loop
    while (game_status == GameOver::NOT_YET)
    {
        update_direction(snake.direction); // Update the direction based on user input
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);
        score -= 20; // Decrease the score by 20 every game loop iteration
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);

        if (is_collision())
        {
            game_status = GameOver::COLLISION;
        }
        if (is_food_eaten()) // Check if the snake ate the food
        {
            food.eaten = true;
            score += 1200; // Increase the score by 1000 when the snake eats the food

            // Extend the snake's body
            for (int i = snake.length; i > 0; i--)
            {
                snake.body[i] = snake.body[i - 1];
            }
            snake.body[0] = food.position;
            snake.length++;
        }

        update_snake_head_direction(); // Update the snake's head direction
        update_food(game_status);      // Update the food on the board
        draw_board();                  // Draw the board
    }
    print_game_over(game_status); // Print the game over message
    print_score();                // Print the final score

#ifdef __linux__
    endwin(); // Clean up the terminal
#endif

    if (game_status == GameOver::WIN)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Initialize the game state
// Sets up the initial board, snake, and food
void SnakeGame::initialize_game()
{
    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Set up the snake
    snake.direction = Direction::RIGHT;
    snake.length = INITIAL_SNAKE_LENGTH;
    int x = BOARD_WIDTH / 2;
    int y = BOARD_HEIGHT / 2;
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++)
    {
        snake.body[i].x = x - i;
        snake.body[i].y = y;
    }

    // Set up the food
    food.eaten = true;
    GameOver game_status = GameOver::NOT_YET;
    update_food(game_status); // Place the first food on the board

    game_over = false;
    score = 0; // Initialize the score to 0
}

// Clears the console and redraws the game board, food, and snake.
void SnakeGame::draw_board()
{
    system(CLEAR_COMMAND);

    // Draw the board with walls, food, and snake
    draw_food();
    draw_snake_body();
    print_walls_and_everything();
}

// Draws the food on the board if it has not been eaten.
void SnakeGame::draw_food()
{
    // If the food is eaten, return without drawing anything
    if (food.eaten)
    {
        return;
    }
    // Draw the food on the board at its position
    board[food.position.y][food.position.x] = 'X';
}

// Draws the snake's body on the board.
void SnakeGame::draw_snake_body()
{
    // Iterate through each segment of the snake's body and draw it on the board
    for (int i = 0; i < snake.length; i++)
    {
        board[snake.body[i].y][snake.body[i].x] = 'O';
    }
}

// Linux version: Clears the screen and prints the game board, walls,
// and additional information such as the number of apples eaten and instructions for the player.
#ifdef __linux__
void SnakeGame::print_walls_and_everything()
{
    // Clear the screen
    clear();
    // Draw the top wall
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        mvprintw(0, i, "#");
    }

    // Draw the side walls and the board content
    for (int i = 0; i < BOARD_HEIGHT - 2; i++)
    {
        mvprintw(i + 1, 0, "#");                  // The left wall
        for (int j = 0; j < BOARD_WIDTH - 2; j++) // In the middle, the movable squares.
        {
            mvprintw(i + 1, j + 1, "%c", board[i][j]);
        }
        mvprintw(i + 1, BOARD_WIDTH - 1, "#"); // The right wall
    }
    // Draw the bottom wall
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        mvprintw(BOARD_HEIGHT - 1, i, "#");
    }

    // Print additional information
    mvprintw(BOARD_HEIGHT + 2, 0, "Apple eaten: %d", food.how_many_already_eaten - 1);
    mvprintw(BOARD_HEIGHT + 3, 0, "Use arrow keys to navigate your snake.");

    // Refresh the screen
    refresh();
}
#else
// This is the non-Linux version of the same function
void SnakeGame::print_walls_and_everything()
{
    for (int i = 0; i < BOARD_WIDTH + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        cout << "#";
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            cout << board[i][j];
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < BOARD_WIDTH + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
}
#endif

// Updates the position of the snake's head based on its current direction,
// and moves the rest of the body accordingly.
void SnakeGame::update_snake_head_direction()
{
    // Clear the last snake tail position
    board[snake.body[snake.length - 1].y][snake.body[snake.length - 1].x] = ' ';

    // Move the snake body
    for (int i = snake.length - 1; i > 0; i--)
    {
        snake.body[i] = snake.body[i - 1];
    }

    // Calculate the new head position based on the current direction
    Position new_head = snake.body[0];
    switch (snake.direction)
    {
    case Direction::UP:
        new_head.y--;
        break;
    case Direction::DOWN:
        new_head.y++;
        break;
    case Direction::LEFT:
        new_head.x--;
        break;
    case Direction::RIGHT:
        new_head.x++;
        break;
    default:
        break;
    }

    // Update the snake's head position if it's within the board boundaries
    if (new_head.x >= 0 && new_head.x < BOARD_WIDTH && new_head.y >= 0 && new_head.y < BOARD_HEIGHT)
    {
        snake.body[0] = new_head;
    }
}

// Generates a new food position if it is eaten, updates the
// food counter, and sets the game status to 'win' if enough food has been eaten.
// Input by reference: the game status. We arbitrary set the winning condition
// to 5 apples.
void SnakeGame::update_food(GameOver &game_status)
{
    // If the food is eaten
    if (food.eaten)
    {
        // Increment the food counter
        food.how_many_already_eaten++;

        // If the food counter exceeds the winning threshold, set the game status to 'win'
        if (food.how_many_already_eaten > 5)
        {
            game_status = GameOver::WIN;
            return;
        }

        // Generate a new food position on the board
        int x, y;
        do
        {
            srand((unsigned)time(NULL));
            bool no_collision_with_snake = true;
            do
            {
                x = rand() % (BOARD_WIDTH - 2) + 1;
                y = rand() % (BOARD_HEIGHT - 2) + 1;

                for (int i = 1; i < snake.length; i++)
                {
                    if (x == snake.body[i].x && y == snake.body[i].y)
                    {
                        no_collision_with_snake = false;
                    }
                }
            } while (!no_collision_with_snake);
        } while (board[y][x] != ' ' && board[y][x] != '#');

        food.position = {x, y};
        food.eaten = false;
    }
}

// Checks if the snake collides with the walls or its own body.
bool SnakeGame::is_collision()
{
    // Check if the snake collides with walls
    if (snake.body[0].x < 0 || snake.body[0].x >= BOARD_WIDTH || snake.body[0].y < 0 || snake.body[0].y >= BOARD_HEIGHT)
    {
        return true;
    }

    // Check if the snake collides with its own body
    for (int i = 1; i < snake.length; i++)
    {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
        {
            return true;
        }
    }

    return false;
}

// eturns true if the snake's head is at the same position as the food.
bool SnakeGame::is_food_eaten()
{
    return snake.body[0].x == food.position.x && snake.body[0].y == food.position.y;
}

// Returns true if the game is over.
bool SnakeGame::is_game_over()
{
    return game_over;
}

// Prints the game over message based on the game status (win or collision).
void SnakeGame::print_game_over(const GameOver &game_status)
{
    if (game_status == GameOver::WIN)
    {
        std::cout << "GAME OVER! You win!" << std::endl;
    }
    else if (game_status == GameOver::COLLISION)
    {
        std::cout << "GAME OVER! You lost!" << std::endl;
    }
}

// Prints the current score and waits for a second.
void SnakeGame::print_score()
{
    std::cout << "Score: " << score << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

// Updates the snake's direction based on the user's key input.
void update_direction(Direction &direction)
{
    // Detect operating system
#ifdef _WIN32
    // Windows
    if (_kbhit())
    {
        switch (_getch())
        {
        case 72: // Arrow up
            direction = Direction::UP;
            break;
        case 80: // Arrow down
            direction = Direction::DOWN;
            break;
        case 75: // Arrow left
            direction = Direction::LEFT;
            break;
        case 77: // Arrow right
            direction = Direction::RIGHT;
            break;
        }
    }
#else
    // Linux
    int ch = getch();
    if (ch != ERR)
    {
        switch (ch)
        {
        case KEY_UP: // Arrow up
            direction = Direction::UP;
            break;
        case KEY_DOWN: // Arrow down
            direction = Direction::DOWN;
            break;
        case KEY_LEFT: // Arrow left
            direction = Direction::LEFT;
            break;
        case KEY_RIGHT: // Arrow right
            direction = Direction::RIGHT;
            break;
        }
    }
#endif
}