#pragma once
#include "define.h"
#include "Deck.h"
class Card {
private:
    Deck deck;
public:
    Card();
    string getSuit(string);
    string getRank(string);
    string getColor(string);
    int getRankValue(string);
};

