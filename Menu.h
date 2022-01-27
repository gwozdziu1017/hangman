#pragma once

/*
* Printing menu
* 13.01.2022 by DG
*/

#include <string>
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
	
private:
	std::string menuContext;
	std::string askforNoOfPlayerMenuContext;
	std::string askForLetterMenuContext;
};