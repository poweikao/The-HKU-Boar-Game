#ifndef PUSHBOX_H
#define PUSHBOX_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int pushbox(); // Do not change name. This function is used in main.cpp

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;

enum class CellType
{
    WALL,
    PLAYER,
    BOX,
    DESTINATION,
    FLOOR
};

class BoxGame
{
public:
    BoxGame();
    void run();

private:
    void initialize_game();
    void draw_board();
    void move_player(int dx, int dy);
    bool is_valid_move(int x, int y);
    bool is_game_over();
    void print_game_over();

    CellType board[BOARD_HEIGHT][BOARD_WIDTH];
    int player_x, player_y;
    int num_boxes_on_target;
};

#endif
