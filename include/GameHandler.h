#pragma once

// Managing the whole game
// 13.01.2022 by DG

#include <string>
#include <algorithm>
#include <type_traits>

#include "../include/Menu.h"
#include "../include/PlayerHandler.h"
#include "../include/WordHandler.h"
#include "../include/IOHandler.h"

typedef std::vector<std::shared_ptr<PlayerHandler>>::iterator PlayerHandlerIterator;

class GameHandler : public Menu, PlayerHandler, WordHandler {
public:
	GameHandler() : noOfPlayers(0), letter('a'), theWord(""), gameOver(false) {};
	void startGame(); // get input and start single or multiplayer
	void setNoOfPlayers(short _noOfPlayers);
	short getNoOfPlayers();
	void startSingleplayerMode();
	void startMultiplayerMode(short _noOfPlayers); //TODO
	void setupPlayers(const int _noOfPlayers, std::vector<std::shared_ptr<PlayerHandler> >& _vectorOfPlayers);
	bool isGameOver(std::vector<std::shared_ptr<PlayerHandler> > vectorOfPlayers = std::vector<std::shared_ptr<PlayerHandler> >()); // default empty because it can be used for singleplayer also
	int getNextPlayerId(std::vector<std::shared_ptr<PlayerHandler> > vectorOfPlayers, int currentPlayerId);
	void setGameOver(bool value);
	bool run();
	void correctLetter();
	void incorrectLetter();
	void continueGame();
private:
	bool gameOver;
	short noOfPlayers;
	char letter;
	std::string theWord;
};