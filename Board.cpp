#include "Board.h"
#include <bits/stdc++.h>
using namespace std;

Board::Board() : board(3, vector<char>(3, ' ')) {}

void Board::printBoard() const
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << (cell == ' ' ? '.' : cell) << ' ';
        }
        cout << endl;
    }
}

bool Board::makeMove(int row, int col, char symbol)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

bool Board::checkWin(char symbol) const
{
    return checkRowWin(symbol) || checkColWin(symbol) || checkDiagonalWin(symbol);
}

bool Board::isFull() const
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

char Board::getSymbol(int row, int col) const
{
    return board[row][col];
}

bool Board::checkRowWin(char symbol) const
{
    for (const auto &row : board)
    {
        if (row[0] == symbol && row[1] == symbol && row[2] == symbol)
        {
            return true;
        }
    }
    return false;
}

bool Board::checkColWin(char symbol) const
{
    for (int col = 0; col < 3; ++col)
    {
        if (board[0][col] == symbol && board[1][col] == symbol && board[2][col] == symbol)
        {
            return true;
        }
    }
    return false;
}

bool Board::checkDiagonalWin(char symbol) const
{
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return true;
    }
    return false;
}
