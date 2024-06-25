#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>
using namespace std;

class Player {
public:
    Player(const string &name, char symbol);

    string getName() const;
    char getSymbol() const;

private:
    string name;
    char symbol;
};

#endif // PLAYER_H
