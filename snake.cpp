#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdlib>

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"
#include <ncurses.h>
#endif

using namespace std;

// Define constants

// Define enum and struct

// Function prototypes
#include "snake.h"
#include <chrono>
#include <thread>

void update_direction(Direction &direction);

// Main function
int snake()
{
    // Do not change name. This function is used in main.cpp
    SnakeGame new_game;
    return new_game.run();
}

///////

SnakeGame::SnakeGame()
{
    // Allocate memory for the board
    board = new char *[BOARD_HEIGHT];
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        board[i] = new char[BOARD_WIDTH];
    }

    initialize_game();
}

SnakeGame::~SnakeGame()
{
    // Deallocate memory for the board
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    // Other destructor code...
}

int SnakeGame::run()
{
    GameOver game_status = GameOver::NOT_YET;

#ifdef __linux__
    initscr();  // Initialize ncurses
    timeout(0); // Set input to non-blocking mode
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
#endif

    while (game_status == GameOver::NOT_YET)
    {
        update_direction(snake.direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);
        score -= 20;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        update_direction(snake.direction);

        if (is_collision())
        {
            game_status = GameOver::COLLISSION;
        }
        if (is_food_eaten())
        {
            food.eaten = true;
            score += 1000;
            for (int i = snake.length; i > 0; i--)
            {
                snake.body[i] = snake.body[i - 1];
            }
            snake.body[0] = food.position;
            snake.length++;
        }

        update_snake_head_direction();
        update_food(game_status);
        draw_board();
    }
    print_game_over(game_status);
    print_score();

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
    update_food(game_status);

    game_over = false;
    score = 0;
}

void SnakeGame::draw_board()
{
    // Clear the console
    system(CLEAR_COMMAND);

    // Draw the board with walls and food
    draw_food();
    draw_snake_body();
    draw_walls_and_everything();
}

void SnakeGame::draw_walls_and_everything()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        cout << "#";                          // The left wall
        for (int j = 0; j < BOARD_WIDTH -2 ; j++) // In the middle, the movable squares.
        {
            cout << board[i][j];
        }
        cout << "#" << endl; // The right wall
    }
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        cout << "#";
    }
    cout << endl
         << "Apple eaten: " << food.how_many_already_eaten - 1 << endl
         << "Use arrow keys to navigate your snake." << endl;
}

void SnakeGame::draw_snake_body()
{

    for (int i = 0; i < snake.length; i++)
    {
        board[snake.body[i].y][snake.body[i].x] = 'O';
    }
}

void SnakeGame::draw_food()
{
    if (food.eaten)
    {
        return;
    }
    board[food.position.y][food.position.x] = 'X';
}

void SnakeGame::update_snake_head_direction()
{
    board[snake.body[snake.length - 1].y][snake.body[snake.length - 1].x] = ' ';
    // ^^ added this line to make the snake's tail auto disappearing ~Paul 27 Apr

    // Move the snake
    // Move the snake
    for (int i = snake.length - 1; i > 0; i--)
    {
        snake.body[i] = snake.body[i - 1];
    }
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

    if (new_head.x >= 0 && new_head.x < BOARD_WIDTH && new_head.y >= 0 && new_head.y < BOARD_HEIGHT)
    {
        snake.body[0] = new_head;
    }
}

void SnakeGame::update_food(GameOver &game_status)
{
    if (food.eaten)
    {
        food.how_many_already_eaten++;

        if (food.how_many_already_eaten > 5)
        {
            game_status = GameOver::WIN;
            return;
        }

        int x, y;
        do
        {
            srand((unsigned)time(NULL));
            do
            {
                x = rand() % BOARD_WIDTH;
                y = rand() % BOARD_HEIGHT;
            } while (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT);
        } while (board[y][x] != ' ');

        food.position = {x, y};
        food.eaten = false;
    }
}

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

bool SnakeGame::is_food_eaten()
{
    return snake.body[0].x == food.position.x && snake.body[0].y == food.position.y;
}

bool SnakeGame::is_game_over()
{
    return game_over;
}

void SnakeGame::print_game_over(const GameOver &game_status)
{
    if (game_status == GameOver::WIN)
    {
        std::cout << "GAME OVER! You win!" << std::endl;
    }
    else if (game_status == GameOver::COLLISSION)
    {
        std::cout << "GAME OVER! You lost!" << std::endl;
    }
}

void SnakeGame::print_score()
{
    std::cout << "Score: " << score << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

// Direction-getting related utilities
void update_direction(Direction &direction)
{ // this piece of code is delicate. Don't change it.
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

/* int main()
{
    snake();
    return 0;
}
 */