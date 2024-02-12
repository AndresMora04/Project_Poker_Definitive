#pragma once
#include "define.h"
class Deck
{
private:
    string suits[NUM_SUITS] = { "Corazones", "Diamantes", "Treboles", "Picas" };
    string ranks[NUM_RANKS] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string cards[NUM_SUITS][NUM_RANKS];
    Texture cardTextures[NUM_SUITS][NUM_RANKS];
public:
    Deck();
    void DeckTexture();
    string* getFlop();
    string getTurn();
    string getRiver();
    void print();
    Texture printTextures(string, string, Texture);
    void deleteArray(string*);
    string getCard();
};