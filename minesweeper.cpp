#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

#ifdef _WIN32 // VERY IMPORTANT!! DO NOT DELETE. WITHOUT THIS LINE MY COMPUTER CANNOT RUN THE CODE. ~Paul 4/12/2023
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Define constants

// Define enum and struct

// Function prototypes
int minesweeper();
bool is_mine(int row, int col, const char board[][5]);
void make_move(int *x, int *y);
void implement_mines(char answer_board[][5]);
void implement_numbers(char answer_board[][5]);
bool reveal_board(const int &r, const int &c, const char answer_board[][5], char game_board[][5]);
bool double_check_gameend(const char answer_board[][5], const char game_board[][5]);
void print_board(char game_board[][5]);
int main();

// Main function

int minesweeper()
{
    bool winning_condition = false;

    char game_board[5][5], answer_board[5][5];

    for (int i = 0; i < 25; i++)
    {
        game_board[i / 5][i % 5] = '#';
        answer_board[i / 5][i % 5] = ' ';
    }

    implement_mines(answer_board);
    implement_numbers(answer_board);

    int r, c;

    int how_many_moves = 20;
    while (true)
    {
        print_board(game_board);
        if (double_check_gameend(answer_board, game_board))
        {
            cout << endl
                 << "You won the minesweeper game!" << endl;
            return 1;
        }

        make_move(&r, &c);
        if (is_mine(r, c, answer_board))
        {
            return 0;
        }
        else
        {
            how_many_moves--;
            winning_condition = reveal_board(r, c, answer_board, game_board);
        }

        if (winning_condition | (how_many_moves == 0))
        {
            cout << endl
                 << "You won the minesweeper game!" << endl;
            return 1;
        }
    }
}

bool is_mine(int row, int col, const char answer_board[][5])
{
    if (answer_board[row][col] == '*')
        return (true);
    else
        return (false);
}

void make_move(int *r, int *c)
{
    cout << endl
         << "Please enter two integers (Row, Column): ";
    cin >> *r >> *c;
    return;
}

void implement_mines(char answer_board[][5])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5;) // 5 is the number of mines
    {
        int x = (rand() % 25) / 5;
        int y = (rand() % 25) % 5;

        // cout << "mine " << i << ' ' << x << ' ' << y << endl;

        if (answer_board[x][y] != '*')
        {
            answer_board[x][y] = '*';
            i++;
        }
        else
        { // there is already a mine there
            continue;
        }
    }
    return;
}

void implement_numbers(char answer_board[][5])
{
    char extended_answer_board[7][7];
    for (int i = 0; i < 49; i++)
    {
        extended_answer_board[i / 7][i % 7] = ' ';
    }
    for (int i = 0; i < 25; i++)
    {
        extended_answer_board[i / 5 + 1][i % 5 + 1] = answer_board[i / 5][i % 5];
    }
    int mine_count[5 * 5];
    for (int i = 0; i < 25; i++)
    {
        mine_count[i] = 0;
        for (int j = 0; j < 9; j++)
        {
            if (j == 4)
            {
                continue;
            }
            if (extended_answer_board[i / 5 + j / 3][i % 5 + j % 3] == '*')
            {
                mine_count[i]++;
            }
        }
    }
    for (int i = 0; i < 25; i++)
    {
        switch (answer_board[i / 5][i % 5])
        {
        case ' ':
            if (mine_count[i] != 0)
            {
                answer_board[i / 5][i % 5] = static_cast<char>('0' + mine_count[i]);
            }
            continue;
        case '*':
            continue;
        }
    }
    // print_board(answer_board);
}

bool reveal_board(const int &r, const int &c, const char answer_board[][5], char game_board[][5]) // return true means winning
{
    if (answer_board[r][c] != ' ')
    {
        // check winning condition
        for (int i = 0; i < 25; i++)
        {
            if (!is_mine(i / 5, i % 5, answer_board) && game_board[i / 5][i % 5] == '#')
            {
                game_board[r][c] = answer_board[r][c];
                return false;
            }
        }
        game_board[r][c] = answer_board[r][c];
        return true;
    }

    // white blocks are revealed together
    game_board[r][c] = ' ';
    char extended_answer_board[7][7];
    for (int i = 0; i < 49; i++)
    {
        extended_answer_board[i / 7][i % 7] = '#';
    }
    for (int i = 0; i < 25; i++)
    {
        extended_answer_board[i / 5 + 1][i % 5 + 1] = answer_board[i / 5][i % 5];
    }
    bool not_fully_revealed = true;
    while (not_fully_revealed)
    {
        not_fully_revealed = false;
        for (int i = 0; i < 25; i++)
        {
            if (answer_board[i / 5][i % 5] == ' ' && game_board[i / 5][i % 5] == '#')
            {
                for (int j = 1; j < 9; j = j + 2)
                {
                    if (extended_answer_board[i / 5 + j / 3][i % 5 + j % 3] == ' ')
                    {
                        game_board[i / 5][i % 5] = ' ';
                        not_fully_revealed = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 25; i++)
    {
        if (!is_mine(i / 5, i % 5, answer_board) && game_board[i / 5][i % 5] == '#')
        {
            return false;
        }
    }
    return true;
}

bool double_check_gameend(const char answer_board[][5], const char game_board[][5])
{
    for (int i = 0; i < 25; i++)
    {
        if (!is_mine(i / 5, i % 5, answer_board) && game_board[i / 5][i % 5] == '#')
        {
            return false;
        }
    }
    return true;
}

void print_board(char game_board[][5])
{
    system(CLEAR_COMMAND);

    cout << endl
         << ' ' << ' ';
    for (int i = 0; i < 5; i++)
        cout << i;
    cout << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i << ' ';
        for (int j = 0; j < 5; j++)
        {
            cout << game_board[i][j];
        }
        cout << endl;
    }
    return;
}

int main()
{
    if (minesweeper() == 0)
    {
        cout << "DEBUG: GAME OVER";
    }
}