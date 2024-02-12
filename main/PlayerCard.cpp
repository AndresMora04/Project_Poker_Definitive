#include "PlayerCard.h"


PlayerCard::PlayerCard() {}

PlayerCard::PlayerCard(int money) {
    this->money = money;
    this->playerCards = new string[numCards];
}

void PlayerCard::getCards(Deck deck) {
    for (int i = 0; i < numCards; i++) {
        playerCards[i] = deck.getCard();
    }
}

int PlayerCard::getNumCards()
{
    return numCards;
}

int PlayerCard::getMoney()
{
    return this->money;
}

string* PlayerCard::getPlayerCards()
{
    return playerCards;
}

Texture PlayerCard::getCardTexture(int index)
{
    return cardsTextures[index];
}

void PlayerCard::setCardTextures(Texture cardTexture, int index)
{
    cardsTextures[index] = cardTexture;
}

void PlayerCard::carryBet(int newBet, int& actualBet) {
    actualBet += newBet;
    this->money = money - newBet;
}

Texture PlayerCard::drawPlayer(int numPlayer, Texture texture)
{
    string player = to_string(numPlayer);
    texture.loadFromFile("player" + player + ".png");
    return texture;
}

void PlayerCard::printArray()
{
    for (int i = 0; i < numCards; i++) {
        cout << playerCards[i] << " ";
    }
}

void PlayerCard::deleteArray()
{
    delete[] playerCards;
}

