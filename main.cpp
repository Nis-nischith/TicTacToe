#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    string player1Name, player2Name;

    cout << "Enter name for Player 1 (X): ";
    cin >> player1Name;
    Player player1(player1Name, 'X');

    cout << "Enter name for Player 2 (O): ";
    cin >> player2Name;
    Player player2(player2Name, 'O');

    Game game(player1, player2);
    game.play();

    return 0;
}
