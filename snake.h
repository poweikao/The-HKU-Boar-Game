#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int snake(); // Do not change name. This function is used in main.cpp

const int BOARD_WIDTH = 25;
const int BOARD_HEIGHT = 15;
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

enum class GameOver
{
    WIN,
    COLLISSION,
    NOT_YET
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
    int how_many_already_eaten = 0;
};

class SnakeGame
{
public:
    SnakeGame();
    ~SnakeGame();
    int run();

private:
    void initialize_game();
    void draw_board();
    void draw_walls_and_everything();
    void draw_snake_body();
    void draw_food();
    void update_snake_head_direction();
    void update_food(GameOver &game_status);
    bool is_collision();
    bool is_food_eaten();
    bool is_game_over();
    void print_game_over(const GameOver &game_status);
    void print_score();

    Snake snake;
    Food food;
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    bool game_over;
    int score;
};

#endif
