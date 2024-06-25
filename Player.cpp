#include "Player.h"
#include <bits/stdc++.h>
using namespace std;

Player::Player(const string &name, char symbol) : name(name), symbol(symbol) {}

string Player::getName() const
{
    return name;
}

char Player::getSymbol() const
{
    return symbol;
}
