#pragma once
#include "define.h"
#include "Deck.h"
class PlayerCard {
private:
    Deck deck;
    string* playerCards;
    Texture cardsTextures[4];
    int numCards = 4;
    int money = 0;
public:
    PlayerCard();
    PlayerCard(int);
    void getCards(Deck);
    int getNumCards();
    int getMoney();
    string* getPlayerCards();
    Texture getCardTexture(int);
    void setCardTextures(Texture, int);
    void carryBet(int, int&);
    Texture drawPlayer(int, Texture);
    void printArray();
    void deleteArray();
};
