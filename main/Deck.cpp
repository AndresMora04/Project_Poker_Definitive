#include "Deck.h"

Deck::Deck()
{
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            cards[i][j] = ranks[j] + "_de_" + suits[i];
        }
    }
}

void Deck::DeckTexture() {
    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int j = 0; j < NUM_RANKS; ++j) {
            cardTextures[i][j].loadFromFile("imagens/" + ranks[j] + "_de_" + suits[i] + ".png");
        }
    }
}

string* Deck::getFlop()
{
    string* newArray = new string[3];
    for (int i = 0; i < 3; i++) {
        int chooseRow = rand() % NUM_SUITS;
        int chooseColum = rand() % NUM_RANKS;
        newArray[i] = cards[chooseRow][chooseColum];
    }
    return newArray;
    deleteArray(newArray);
}

string Deck::getTurn()
{
    int chooseRow = rand() % NUM_SUITS;
    int chooseColum = rand() % NUM_RANKS;
    return cards[chooseRow][chooseColum];
}

string Deck::getRiver()
{
    int chooseRow = rand() % NUM_SUITS;
    int chooseColum = rand() % NUM_RANKS;
    return cards[chooseRow][chooseColum];
}

void Deck::print()
{
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            cout << cards[i][j] << "  ";
        }
    }
}

Texture Deck::printTextures(string suit, string rank, Texture texture)
{
    texture.loadFromFile("imagens/" + rank + "_de_" + suit + ".png");
    //cout << "imagens/" + rank + "_de_" + suit + ".png";
    return texture;
}

void Deck::deleteArray(string* array)
{
    delete[] array;
}

string Deck::getCard()
{
    int chooseRow = rand() % NUM_SUITS;
    int chooseColum = rand() % NUM_RANKS;
    return cards[chooseRow][chooseColum];
}
