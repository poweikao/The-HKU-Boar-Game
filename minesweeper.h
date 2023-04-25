#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int minesweeper(); // Do not change name. This function is used in main.cpp
bool is_mine(int row, int col, const char board[][5]);
void make_move(int *x, int *y);
void implement_mines(char answer_board[][5]);
void implement_numbers(char answer_board[][5]);
bool reveal_board(const int &r, const int &c, const char answer_board[][5], char game_board[][5]);
bool double_check_gameend(const char answer_board[][5], const char game_board[][5]);
void print_board(char game_board[][5]);

#endif
