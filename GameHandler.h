#pragma once

// Managing the whole game
// 13.01.2022 by DG

#include <string>

#include "IGameHandler.h"
#include "Menu.h"
#include "PlayerHandler.h"
#include "WordHandler.h"
#include "IOHandler.h"

class GameHandler : public Menu, PlayerHandler, WordHandler {
public:
	GameHandler() { noOfPlayers = 0; letter = 'a'; theWord = ""; };
	void startGame(); // get input and start single or multiplayer
protected:
	void setNoOfPlayers(short _noOfPlayers);
	short getNoOfPlayers();
	void gameOver(); // TODO
	void startSingleplayerMode();
	void startMultiplayerMode(short _noOfPlayers); //TODO
private:
	short noOfPlayers;
	char letter;
	std::string theWord;
};