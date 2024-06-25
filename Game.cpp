#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

Game::Game(const Player &player1, const Player &player2)
    : player1(player1), player2(player2), currentPlayer(true),
      window(sf::VideoMode(600, 600), "Tic-Tac-Toe") {
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Error loading font\n";
    }
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
}

void Game::play() {
    bool gameWon = false;
    bool draw = false;

    while (window.isOpen()) {
        handleEvents();

        window.clear(sf::Color::White);
        drawBoard();
        window.display();

        if (gameWon || draw) {
            continue;
        }

        if (board.checkWin(currentPlayer ? player1.getSymbol() : player2.getSymbol())) {
            gameWon = true;
            displayWinner(currentPlayer ? player1.getName() : player2.getName());
        } else if (board.isFull()) {
            draw = true;
            displayWinner("Draw");
        }
    }
}

void Game::switchPlayer() {
    currentPlayer = !currentPlayer;
}

bool Game::makeMove(int row, int col) {
    return board.makeMove(row, col, currentPlayer ? player1.getSymbol() : player2.getSymbol());
}

void Game::drawBoard() {
    sf::RectangleShape line(sf::Vector2f(600, 5));
    line.setFillColor(sf::Color::Black);
    for (int i = 1; i < 3; ++i) {
        line.setPosition(0, i * 200);
        window.draw(line);
        line.setRotation(90);
        line.setPosition(i * 200, 0);
        window.draw(line);
        line.setRotation(0);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            if (board.getSymbol(i, j) != ' ') {
                text.setString(board.getSymbol(i, j));
                text.setPosition(j * 200 + 90, i * 200 + 80);
                window.draw(text);
            }
        }
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            int row = event.mouseButton.y / 200;
            int col = event.mouseButton.x / 200;
            if (makeMove(row, col)) {
                if (board.checkWin(currentPlayer ? player1.getSymbol() : player2.getSymbol())) {
                    displayWinner(currentPlayer ? player1.getName() : player2.getName());
                } else if (board.isFull()) {
                    displayWinner("Draw");
                } else {
                    switchPlayer();
                }
            }
        }
    }
}

void Game::displayWinner(const string &winner) {
    window.clear(sf::Color::White);
    text.setString(winner + " wins!");
    text.setPosition(200, 250);
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(3));
    window.close();
}
