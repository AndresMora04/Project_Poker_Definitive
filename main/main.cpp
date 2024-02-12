#include "Deck.h"
#include "PlayerCard.h"
#include "Card.h"
#include "Dealer.h"
#include "define.h"
#include "Game.h"

int main() {
    srand(time(NULL));
    Game game;
    game.run();

    return 0;

}