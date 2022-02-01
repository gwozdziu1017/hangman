#pragma once

/*
* Printing menu
* 13.01.2022 by DG
*/

#include <string>
#include <vector>
#include <iostream>

class Menu {
public:
	Menu() { fillAllMenuContexts(); };
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
	
private:
	std::string menuContext;
	std::string askforNoOfPlayerMenuContext;
	std::string askForLetterMenuContext;
};