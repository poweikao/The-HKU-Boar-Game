#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023 No problem! ~Lucy
#define CLEAR_COMMAND "cls"
#include <conio.h>
#else
#define CLEAR_COMMAND "clear"
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
    new_game.run();
    return 0;
}

int main(){
    snake();
    return 0;
}

///////

SnakeGame::SnakeGame() {
    initialize_game();
}

SnakeGame::~SnakeGame() {
    // Do nothing
}

void SnakeGame::run() {
    while (!game_over) {
        update_direction(snake.direction);
        draw_board();
        update_snake();
        update_food();
        if (is_collision()) {
            game_over = true;
        }
        if (is_food_eaten()) {
            score++;
            snake.length++;
        }
        if (is_game_over()) {
            game_over = true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    print_game_over();
    print_score();
}

void SnakeGame::initialize_game() {
    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Set up the snake
    snake.direction = Direction::RIGHT;
    snake.length = INITIAL_SNAKE_LENGTH;
    int x = BOARD_WIDTH / 2;
    int y = BOARD_HEIGHT / 2;
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        snake.body[i].x = x - i;
        snake.body[i].y = y;
    }

    // Set up the food
    food.eaten = true;
    update_food();

    game_over = false;
    score = 0;
}

void SnakeGame::draw_board() {
    // Clear the console
    system(CLEAR_COMMAND);

    // Draw the board with walls, snake, and food
    draw_walls();
    draw_snake();
    draw_food();
}

void SnakeGame::draw_walls() {
    for (int i = 0; i < BOARD_WIDTH + 2; i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < BOARD_WIDTH; j++) {
            cout << board[i][j];
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < BOARD_WIDTH + 2; i++) {
        cout << "#";
    }
    cout << endl;
}

void SnakeGame::draw_snake() {
    board[snake.body[snake.length-1].y][snake.body[snake.length-1].x] = ' ';
    // ^^ added this line to make the snake's tail auto disappearing ~Paul 27 Apr
    
    for (int i = 0; i < snake.length; i++) {
        board[snake.body[i].y][snake.body[i].x] = 'O';
    }
}

void SnakeGame::draw_food() {
    if (food.eaten) {
        return;
    }
    board[food.position.y][food.position.x] = 'X';
}

void update_direction(Direction& direction) { // this piece of code is delicate. Don't change it.
    // Detect operating system
    #ifdef _WIN32
    // Windows
    if (_kbhit()) {
        switch (_getch()) {
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
    if (ch != ERR) {
        switch (ch) {
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

void SnakeGame::update_snake() {
    // Move the snake
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    switch (snake.direction) {
    case Direction::UP:
        snake.body[0].y--;
        break;
    case Direction::DOWN:
        snake.body[0].y++;
        break;
    case Direction::LEFT:
        snake.body[0].x--;
        break;
    case Direction::RIGHT:
        snake.body[0].x++;
        break;
    }
}

void SnakeGame::update_food() {
    if (food.eaten) {
        int x, y;
        do {
            x = rand() % BOARD_WIDTH;
            y = rand() % BOARD_HEIGHT;
        } while (board[y][x] != ' ');

        food.position = {x, y};
        food.eaten = false;
    }
}

bool SnakeGame::is_collision() {
    // Check if the snake collides with walls
    if (snake.body[0].x < 0 || snake.body[0].x >= BOARD_WIDTH ||
        snake.body[0].y < 0 || snake.body[0].y >= BOARD_HEIGHT) {
        return true;
    }

    // Check if the snake collides with its own body
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x &&
            snake.body[0].y == snake.body[i].y) {
            return true;
        }
    }

    return false;
}

bool SnakeGame::is_food_eaten() {
    return snake.body[0].x == food.position.x && snake.body[0].y == food.position.y;
}

bool SnakeGame::is_game_over() {
    return game_over;
}

void SnakeGame::resume_game() {
    system(CLEAR_COMMAND);
}

void SnakeGame::print_game_over() {
    std::cout << "GAME OVER!" << std::endl;
}

void SnakeGame::print_score() {
    std::cout << "Score: " << score << std::endl;
}
