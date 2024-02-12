#include "Dealer.h"
Dealer::Dealer() {};

Dealer::Dealer(Deck deck) {
    showedCards = new string[5];
    this->deck = deck;
}

string* Dealer::getPlayerCards(PlayerCard playerCard)
{
    return playerCard.getPlayerCards();
}

string* Dealer::getFlop() {
    cardsSize = 4;
    return deck.getFlop();
}

string Dealer::getTurn() {
    cardsSize = 5;
    return deck.getTurn();
}

string Dealer::getRiver() {
    cardsSize = 6;
    return deck.getRiver();
}

void Dealer::setCardTextures(string cardName, int index)
{
    Texture texture;
    texture.loadFromFile("imagens/" + cardName + ".png");
    cardTextures[index] = texture;
}

string* Dealer::getShowedCards() {
    return this->showedCards;
}

Texture Dealer::getTexture(int index)
{
    return cardTextures[index];
}

void Dealer::fillShowedCards(string card, int& index) {
    showedCards[index] = card;
    index++;
}

int Dealer::getCardsSize()
{
    return cardsSize;
}

void Dealer::deleteArray()
{
    delete[] showedCards;
}
