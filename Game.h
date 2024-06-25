#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game(const Player &player1, const Player &player2);
    void play();

private:
    Player player1;
    Player player2;
    Board board;
    bool currentPlayer;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;

    void switchPlayer();
    bool makeMove(int row, int col);
    void drawBoard();
    void handleEvents();
    void displayWinner(const std::string &winner);
};

#endif // GAME_H
