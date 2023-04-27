#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int snake(); // Do not change name. This function is used in main.cpp

const int BOARD_WIDTH = 18;
const int BOARD_HEIGHT = 18;
const int INITIAL_SNAKE_LENGTH = 3;

struct Position
{
    int x;
    int y;
};

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake
{
    Direction direction;
    int length;
    Position body[BOARD_WIDTH * BOARD_HEIGHT];
};

struct Food
{
    Position position;
    bool eaten;
};

class SnakeGame
{
public:
    SnakeGame();
    ~SnakeGame();
    void run();

private:
    void initialize_game();
    void draw_board();
    void draw_walls();
    void draw_snake();
    void draw_food();
    void update_snake();
    void update_food();
    bool is_collision();
    bool is_food_eaten();
    bool is_game_over();
    void resume_game();
    void print_game_over();
    void print_score();

    Snake snake;
    Food food;
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    bool game_over;
    int score;
};

#endif
