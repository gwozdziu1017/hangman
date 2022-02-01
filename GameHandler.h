#pragma once

// Managing the whole game
// 13.01.2022 by DG

#include <iostream>
#include <string>

#include "IGameHandler.h"
#include "Menu.h"
#include "PlayerHandler.h"
#include "WordHandler.h"

class GameHandler : public Menu, PlayerHandler, WordHandler {
public:
	GameHandler() { noOfPlayers = 0; letter = 'a'; theWord = ""; };
	~GameHandler() {};
	void startGame(); // get input and start single or multiplayer
protected:
	//TODO these two functions should be close into one - template?
	short getUserInput_short();
	std::string getUserInput_string(); 
	char getUserInput_char();

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