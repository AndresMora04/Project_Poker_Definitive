#include "Card.h"

Card::Card() {}

string Card::getSuit(string card) {
    for (int i = card.length() - 1; i >= 0; i--) {
        if (card[i - 1] == '_') {
            return card.substr(i, card.length());
            cout << card.substr(i, 5);
            continue;
        }
    }
}

string Card::getRank(string card) {
    for (int i = 0; i < card.length(); i++) {
        if (card[i] == '_') {
            return card.substr(0, i);
            continue;
        }
    }
}

string Card::getColor(string card) {
    return (getSuit(card) == "Corazones" || getSuit(card) == "Diamantes") ? "Rojo" : "Negro";
}

int Card::getRankValue(string card) {
    if (getRank(card) == "A") return 14;
    else if (getRank(card) == "K") return 13;
    else if (getRank(card) == "Q") return 12;
    else if (getRank(card) == "J") return 11;
    else return stoi(getRank(card));
}
