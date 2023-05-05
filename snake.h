#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <thread>

// Constants for the Snake game
const int BOARD_WIDTH = 25;
const int BOARD_HEIGHT = 15;
const int INITIAL_SNAKE_LENGTH = 3;

// A struct representing a 2D position with x and y coordinates
struct Position
{
    int x;
    int y;
};

// Enum class representing the possible directions of movement
// Note: This Direction enum class is also used in pushbox.cpp
enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

// Enum class representing the possible game over outcomes
enum class GameOver
{
    WIN,
    COLLISION,
    NOT_YET
};

// A struct representing the Snake, including its direction, length, and body positions
struct Snake
{
    Direction direction;
    int length;
    Position body[BOARD_WIDTH * BOARD_HEIGHT];
};

// A struct representing the Food in the Snake game, including its
// position, status (eaten or not), and a counter for how many have been eaten
struct Food
{
    Position position;
    bool eaten;
    int how_many_already_eaten = 0;
};

// A class representing the Snake game, including the game state,
// Snake, Food, and methods to manage the game loop and logic
class SnakeGame
{
public:
    // Constructor and destructor
    SnakeGame();
    ~SnakeGame();

    // Main method to run the Snake game and return the final score
    int run();

private:
    // Private member variables for the Snake game using dynamic memory managements
    Snake snake;
    Food food;
    char **board;
    bool game_over;
    int score;
    
    // Private helper methods for managing the Snake game
    void initialize_game();
    void draw_board();
    void print_walls_and_everything();
    void draw_snake_body();
    void draw_food();
    void update_snake_head_direction();
    void update_food(GameOver &game_status);
    bool is_collision();
    bool is_food_eaten();
    bool is_game_over();
    void print_game_over(const GameOver &game_status);
    void print_score();
};

// Main function for the Snake game
int snake();

#endif