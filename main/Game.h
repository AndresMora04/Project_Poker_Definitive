#include "define.h"
#include "Deck.h"
#include "Card.h"
#include "Dealer.h"
class Game {
private:
	RenderWindow window;
	Texture backgroundImageTexture;
	Sprite backgroundImage;

	Texture playButtonTexture, addPlayerButtonTexture;
	Texture exitButtonTexture, readyButtonTexture;
	Texture betButtonTexture, surrenderButtonTexture;
	Texture showMyCardsTexture;
	Sprite playButton, addPlayerButton;
	Sprite exitButton, readyButton;
	Sprite betButton, surrenderButton;
	Sprite showMyCardsButton;

	Texture reverseCardTexture;
	Sprite reverseCardImage;

	Texture playerImageTexture;
	Sprite playerImage;
	Texture playerImagesTexture[6];
	Sprite playerImages[6];

	Texture playerTextures[4];
	Deck deck;
	Dealer dealer;
	PlayerCard* players;
	int numPlayers = 0;
	int actualBet = 0;
	int index = 0;
	int turn = 0;
	int turnBet = 0;
	bool allPlayersBetEnough = false;
	bool playButtonClicked = false;
	bool readyButtonClicked = false;
	bool lessThanTwoPlayers = false;
	bool showCards = true;
	bool cardShown = false;

	Font welcomefont, playerAdvertFont, maxPlayersAdvertFont;
	Text welcomeText, playerAdvertText, maxPlayersAdvertText;
	
	Sprite sprite;


public:
	Game() : window(VideoMode(1100, 600), "Game"), numPlayers(0) {
		loadTextures();
		loadTexts();
		setupSprites();
		this->deck = Deck();
		this->dealer = Dealer(deck);
	}

	void run() {
		while (window.isOpen()) {
			handleEvents();
			update();
			render();
		}
	}

	void loadTextures() {
		backgroundImageTexture.loadFromFile("screen/START_SCREEN.jpg");
		playButtonTexture.loadFromFile("screen/playButton.jpg");
		addPlayerButtonTexture.loadFromFile("screen/botonJugador.png");
		exitButtonTexture.loadFromFile("screen/botonSalir.png");
		readyButtonTexture.loadFromFile("screen/botonJugar.png");
		playerImageTexture.loadFromFile("players/player0.png");
		betButtonTexture.loadFromFile("screen/botonApostar.png");
		surrenderButtonTexture.loadFromFile("screen/botonRendirse.png");
		showMyCardsTexture.loadFromFile("screen/verCartas.png");
		reverseCardTexture.loadFromFile("screen/reversoCarta.jpg");

		for (int i = 0; i < 6; ++i) {
			if (!playerImagesTexture[i].loadFromFile("players/player" + to_string(i) + ".png")) {
				cout << "Failed to load player image " << i << "!" << endl;
			}
		}
	}

	void loadTexts() {
		welcomefont.loadFromFile("Chakra_Petch/ChakraPetch-Bold.ttf");
		welcomeText.setFont(welcomefont);
		welcomeText.setString("Bienvenidos al juego\n\n\n\n   ¡Que lo disfrutes!");
		welcomeText.setCharacterSize(74);
		welcomeText.setFillColor(Color::White);
		welcomeText.setPosition(205, 20);

		playerAdvertFont.loadFromFile("Chakra_Petch/ChakraPetch-Bold.ttf");
		playerAdvertText.setFont(playerAdvertFont);
		playerAdvertText.setString("Debe agregar minimo dos jugadores\n                       para jugar");
		playerAdvertText.setCharacterSize(55);
		playerAdvertText.setFillColor(Color::White);
		playerAdvertText.setPosition(-1000, -1000);

		maxPlayersAdvertFont.loadFromFile("Chakra_Petch/ChakraPetch-Bold.ttf");
		maxPlayersAdvertText.setFont(maxPlayersAdvertFont);
		maxPlayersAdvertText.setString("Maximo de jugadores alcanzado");
		maxPlayersAdvertText.setCharacterSize(55);
		maxPlayersAdvertText.setFillColor(Color::White);
		maxPlayersAdvertText.setPosition(-1000, -1000);
	}

	void setupSprites() {
		backgroundImage.setTexture(backgroundImageTexture);
		backgroundImage.setScale(static_cast<float>(window.getSize().x) / backgroundImageTexture.getSize().x,
			static_cast<float>(window.getSize().y) / backgroundImageTexture.getSize().y);

		playButton.setTexture(playButtonTexture);
		playButton.setScale(0.78f, 0.77f);
		playButton.setPosition(278, 135);

		addPlayerButton.setTexture(addPlayerButtonTexture);
		addPlayerButton.setScale(0.5f, 0.6f);
		addPlayerButton.setPosition(400, 290);

		exitButton.setTexture(exitButtonTexture);
		exitButton.setScale(0.62f, 0.55f);
		exitButton.setPosition(435, 420);

		readyButton.setTexture(readyButtonTexture);
		readyButton.setScale(0.5f, 0.5f);
		readyButton.setPosition(430, 150);

		betButton.setTexture(betButtonTexture);
		betButton.setScale(0.8f, 0.8f);
		betButton.setPosition(380, 400);

		surrenderButton.setTexture(surrenderButtonTexture);
		surrenderButton.setScale(0.8f, 0.8f);
		surrenderButton.setPosition(580, 400);

		showMyCardsButton.setTexture(showMyCardsTexture);
		showMyCardsButton.setScale(0.9f, 0.7f);
		showMyCardsButton.setPosition(-1000, -1000);

		reverseCardImage.setTexture(reverseCardTexture);
		reverseCardImage.setScale(0.1f, 0.1f);
		reverseCardImage.setPosition(-1000, -1000);

		playerImage.setTexture(playerImageTexture);

		for (int i = 0; i < 6; i++) {
			playerImages[i].setTexture(playerImagesTexture[i]);
			playerImages[i].setScale(0.9f, 0.9f);
		}
	}

	void hideOrShowCards() {
		if (showCards) {
			reverseCardImage.setPosition(-1000, -1000);
			cout << "ocultar" << endl;
		}
		else {
			reverseCardImage.setPosition(200, 200);
			cout << "mostrar" << endl;
		}
	}

	void handleEvents() {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				handleMouseClick(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}

	void handleMouseClick(int x, int y) {
		if (playButton.getGlobalBounds().contains(x, y)) {
			playButtonClicked = true;
			playButton.setPosition(-1000, -1000);
			welcomeText.setPosition(-1000, -1000);
			addPlayerButton.setPosition(400, 290);
			exitButton.setPosition(435, 420);
			readyButton.setPosition(430, 150);
			backgroundImageTexture.loadFromFile("screen/table7.png");
			backgroundImage.setTexture(backgroundImageTexture);
			backgroundImage.setScale(static_cast<float>(window.getSize().x) / backgroundImageTexture.getSize().x,
				static_cast<float>(window.getSize().y) / backgroundImageTexture.getSize().y);
		}
		else if (addPlayerButton.getGlobalBounds().contains(x, y)) {
			lessThanTwoPlayers = false;
			if (numPlayers < 6) {
				switch (numPlayers) {
				case 0:
					playerImages[numPlayers].setPosition(200, 10); 
					break;
				case 1:
					playerImages[numPlayers].setPosition(705, 10); 
					break;
				case 2:
					playerImages[numPlayers].setPosition(200, 490); 
					break;
				case 3:
					playerImages[numPlayers].setPosition(705, 490);
					break;
				case 4:
					playerImages[numPlayers].setPosition(1, 205);
					break;
				case 5:
					playerImages[numPlayers].setPosition(995, 205);
					break;
				}
				playerImages[numPlayers].setScale(0.55f, 0.55f);
				numPlayers++;
			}
			else {
				maxPlayersAdvertText.setPosition(145, 480);
				cout << "Maximo de jugadores" << endl;
			}
		}
		else if (exitButton.getGlobalBounds().contains(x, y)) {
			window.close();
		}

		if (readyButton.getGlobalBounds().contains(x, y)) {
			if (numPlayers > 1) {
				readyButtonClicked = true;
				addPlayerButton.setPosition(-1000, -1000);
				readyButton.setPosition(-1000, -1000);
				exitButton.setPosition(1060, 0);
				exitButton.setScale(0.13f, 0.3f);
				playerAdvertText.setPosition(-1000, -1000);
				maxPlayersAdvertText.setPosition(-1000, -1000);
				betButton.setPosition(380, 300);
				surrenderButton.setPosition(580, 300);
				showMyCardsButton.setPosition(383, 380);
				reverseCardImage.setPosition(200, 200);

				players = new PlayerCard[numPlayers];
				for (int i = 0; i < numPlayers; i++) {
					players[i] = PlayerCard(20000);
					players[i].getCards(deck);
					players[i].printArray();
					cout << endl;
				}

				for (int i = 0; i < numPlayers; i++) {
					for (int j = 0; j < 4; ++j) {
						std::string card = players[i].getPlayerCards()[j];
						std::string suit = Card().getSuit(card);
						std::string rank = Card().getRank(card);
						sf::Texture texture;
						texture = deck.printTextures(suit, rank, texture);
						players[i].setCardTextures(texture, j);
					}
				}
			}
			else {
				playerAdvertText.setPosition(100, 80);
				lessThanTwoPlayers = true;
				cout << "No se puede iniciar la partida" << endl;
			}
		}
		if (turnBet < numPlayers) {
			if (betButton.getGlobalBounds().contains(x, y)) {
				players[turnBet].carryBet(20000, actualBet);
				turnBet++;
			}
		}
		else if (turnBet == numPlayers) {
			if (turn == 0) {
				string* newFlop = dealer.getFlop();
				for (int i = 0; i < 3; i++) {
					dealer.fillShowedCards(newFlop[i], index);
					dealer.setCardTextures(newFlop[i], index);
				}
				turn++;
			}
			else if (turn == 1) {
				string newTurn = dealer.getTurn();
				dealer.fillShowedCards(newTurn, index);
				dealer.setCardTextures(newTurn, index);
				turn++;
			}
			else if (turn == 2) {
				string newRiver = dealer.getRiver();
				dealer.fillShowedCards(newRiver, index);
				dealer.setCardTextures(newRiver, index);
				turn++;
			}
			else {
				playerAdvertText.setPosition(100, 80);
			}
		}

		if (surrenderButton.getGlobalBounds().contains(x, y)) {
			cout << "Rendirse" << endl;
		}

		if (showMyCardsButton.getGlobalBounds().contains(x, y)) {
			if (cardShown) {
				showCards = !showCards;
				hideOrShowCards();
			}
			else {
				hideOrShowCards();
				cardShown = true;
			}
		}
	}

	void update() {
	}

	void render() {
		window.clear();
		window.draw(backgroundImage);
		window.draw(welcomeText);
		if (playButtonClicked) {
			window.draw(addPlayerButton);
			window.draw(exitButton);
			window.draw(readyButton);
		}
		window.draw(playButton);

		for (int i = 0; i < numPlayers; ++i) {
			window.draw(playerImages[i]);
		}

		if (lessThanTwoPlayers) {
			window.draw(playerAdvertText);
		}
		if (numPlayers >= 6) {
			window.draw(maxPlayersAdvertText);
		}
		if (readyButtonClicked) {
			float xOffset = 0.0f;
			window.draw(betButton);
			window.draw(surrenderButton);
			window.draw(showMyCardsButton);
			window.draw(reverseCardImage);
			for (int i = 0; i < numPlayers; i++) {
				for (int j = 0; j < 4; j++) {
					Sprite sprite;
					sprite.setTexture(players[i].getCardTexture(j));
					sprite.setPosition(xOffset, 0);
					sprite.setScale(0.2f, 0.2f);
					window.draw(sprite);
					xOffset += 50.0f; 
				}
			}
			for (int i = 0; i < dealer.getCardsSize(); i++) {
				Sprite sprite;
				sprite.setTexture(dealer.getTexture(i));
				sprite.setPosition(xOffset, 0);
				sprite.setScale(0.2f, 0.2f);
				window.draw(sprite);
				xOffset += 50.0f;
			}
		}
		if (showCards) {
			window.draw(reverseCardImage);
		}
		window.display();
	}
};

