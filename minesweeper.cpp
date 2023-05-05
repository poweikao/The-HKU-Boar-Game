// Include system libraries
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>

// Include custom header files
#include "minesweeper.h"

// Define clear screen command based on the operating system
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

// Main function

// Main function for Minesweeper game
// Returns 1 if the player wins and -1 if the player loses
int minesweeper()
{
    bool winning_condition = false;
    bool first_move_detector = true;

    char game_board[5][5], answer_board[5][5];

    // Initialize game_board and answer_board
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
        if (double_check_gameend(answer_board, game_board))
        {
            cout << endl
                 << "You won the minesweeper game!" << endl;
            return 1;
        }
        
        print_board(game_board);
        make_move(&r, &c);

        // Secret debugging auto win game code
        if (r == 999)
        {
            return 1;
        }

        if (is_mine(r, c, answer_board))
        {
            if (first_move_detector)
            {
                return minesweeper();
            }
            else
            {
                return -1;
            }
        }
        else
        {
            first_move_detector = false;
            how_many_moves--;
            winning_condition = reveal_board(r, c, answer_board, game_board);
        }

        if (winning_condition || (how_many_moves == 0))
        {
            cout << endl
                 << "You won the minesweeper game!" << endl;
            return 1;
        }
    }
}

// Function to check if there is a mine at the specified row and column in the answer_board
// Input: row, col (integer coordinates), answer_board (2D character array)
// Output: true if there is a mine at the specified coordinates, false otherwise
bool is_mine(int row, int col, const char answer_board[][5])
{
    if (answer_board[row][col] == '*')
        return (true);
    else
        return (false);
}

// Function to get user input for the next move
// Input: pointers to row and column integers
// Output: modifies the row and column integers with the user's input
void make_move(int *r, int *c)
{
    while (true)
    {
        cout << endl
             << "Please enter two integers (Row Column): ";
        cin >> *r >> *c;
        if (*r == 999)
        { // 999 is the secret win game code
            break;
        }
        else if (*r >= 0 && *r <= 4 && *c >= 0 && *c <= 4 && cin.good())
        {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input: Row and Column must be integers between 0 and 4." << endl;
    }
}

// Function to randomly place mines on the answer_board
// Input: answer_board (2D character array)
// Output: modifies answer_board by placing mines ('*') randomly
void implement_mines(char answer_board[][5])
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4;)
    { // 4 is the number of mines
        int x = (rand() % 25) / 5;
        int y = (rand() % 25) % 5;

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

// Function to calculate and place the numbers on the answer_board
// based on the number of adjacent mines
// Input: answer_board (2D character array)
// Output: modifies answer_board by placing the number of adjacent mines for each cell
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
}

// Reveal a position on the game board and check if the game is won
// Input: r and c (the position to reveal), the answer board (for multiple reveals), the game board
// Returns true if the game is won, false otherwise
bool reveal_board(const int &r, const int &c, const char answer_board[][5], char game_board[][5])
{
    // If the clicked position contains a mine or a number
    if (answer_board[r][c] != ' ')
    {
        // Check if all non-mine positions have been revealed
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

    // If the clicked position is an empty space, reveal all connected empty spaces
    game_board[r][c] = ' ';
    char extended_answer_board[7][7];

    // Initialize the extended answer board with '#' characters
    for (int i = 0; i < 49; i++)
    {
        extended_answer_board[i / 7][i % 7] = '#';
    }

    // Copy the answer board into the extended answer board
    for (int i = 0; i < 25; i++)
    {
        extended_answer_board[i / 5 + 1][i % 5 + 1] = answer_board[i / 5][i % 5];
    }

    // Reveal all connected empty spaces on the game board
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

    // Check if all non-mine positions have been revealed
    for (int i = 0; i < 25; i++)
    {
        if (!is_mine(i / 5, i % 5, answer_board) && game_board[i / 5][i % 5] == '#')
        {
            return false;
        }
    }
    return true;
}

// Double check if the game has ended by comparing answer_board and game_board
// Input: the answer board and the current game board
// Returns true if the game has ended, false otherwise
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

// Print the current state of the game board
// Input: the game board
void print_board(char game_board[][5])
{
    system(CLEAR_COMMAND);

    // Print the column numbers
    cout << endl
         << ' ' << ' ' << ' ' << ' ';
    for (int i = 0; i < 5; i++)
        cout << i;
    cout << endl
         << endl;

    // Print the row numbers and the game board
    for (int i = 0; i < 5; i++)
    {
        cout << ' ' << ' ' << i << ' ';
        for (int j = 0; j < 5; j++)
        {
            cout << game_board[i][j];
        }
        cout << endl;
    }

    // Print additional information about the game
    cout << endl
         << "There are 4 mines and 21 no mine squares." << endl
         << "There're no flags. Remember where the mines are by your head!" << endl
         << "Let's chanllenge ourselves!" << endl;
    return;
}