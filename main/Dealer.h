#pragma once
#include "Deck.h"
#include "PlayerCard.h"
class Dealer {
private:
    string* showedCards;
    Deck deck;
    Texture cardTextures[4];
    int cardsSize = 0;
public:
    Dealer();
    Dealer(Deck);
    string* getPlayerCards(PlayerCard playerCard);
    string* getFlop();
    string getTurn();
    string getRiver();
    void setCardTextures(string, int);
    string* getShowedCards();
    Texture getTexture(int);
    void fillShowedCards(string, int&);
    int getCardsSize();
    void deleteArray();
};