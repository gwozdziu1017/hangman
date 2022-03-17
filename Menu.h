#pragma once

/*
* Printing menu
* 13.01.2022 by DG
*/

#include <string>
#include <vector>

#include "IOHandler.h"

enum MessageBoxPurpose
{
	PlayerWin = 0,
	PlayerLose,
	AlreadyUsedLetter

};
class Menu {
public:
	Menu() { fillAllMenuContexts(); NEW_LINE = '\n'; };
	~Menu() {};

protected:
	void showMenu();
	void fillMenuContext();
	void askForNoOfPlayers();
	void fillAskforNoOfPlayerMenuContext();
	void printWord(std::string _word);
	void fillAskForLetterMenuContext();
	void printAskForLetterMenu();
	void fillAllMenuContexts();
	void printWord(std::vector<char> _word);
	void printYouWinMessage();
	void printYouLoseMessage();
	void fillYouWinMessageContext();
	void fillYouLoseMessageContext();
	void fillAlreadyUsedLetterContext();
	void printAlreadyUsedLetterMessage();
	void fillUserLivesMenuContext();
	void printUserLives(short _lives);
	void fillWrongLetterMessageContext();
	void printWrongLetterMessage();
	void fillPressAnyKeyToContinueMessageContext();
	void printPressAnyKeyToContinueMessage();
	
private:
	std::string menuContext;
	std::string askforNoOfPlayerMenuContext;
	std::string askForLetterMenuContext;
	std::string youWinMessageContext;
	std::string youLoseMessageContext;
	std::string alreadyUsedLetterContext;
	std::string userLivesMenuContext;
	std::string wrongLetterMessageContext;
	std::string pressAnyKeyToContinueMessageContext;
	char NEW_LINE;
};