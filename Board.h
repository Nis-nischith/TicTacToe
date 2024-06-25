#ifndef BOARD_H
#define BOARD_H

#include <vector>
using namespace std;

class Board {
public:
    Board();
    void printBoard() const;
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;
    char getSymbol(int row, int col) const;

private:
    vector<std::vector<char>> board;
    bool checkRowWin(char symbol) const;
    bool checkColWin(char symbol) const;
    bool checkDiagonalWin(char symbol) const;
};

#endif // BOARD_H
