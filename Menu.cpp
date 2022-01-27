#include "Menu.h"

void Menu::fillMenuContext()
{
	menuContext = "----- HANGMAN -----\n";
	menuContext.append("Menu:\n");
	menuContext.append("[1] Singleplayer mode\n");
	menuContext.append("[2] Multiplayer mode\n");
	menuContext.append("[0] Quit");
	menuContext.append("\n");
	menuContext.append("Player choice: ");
}

void Menu::askForNoOfPlayers()
{
	std::cout << askforNoOfPlayerMenuContext;
}

void Menu::fillAskforNoOfPlayerMenuContext()
{
	askforNoOfPlayerMenuContext = "Insert no of players: ";
}

void Menu::printWord(std::string _word)
{
	std::cout << _word;
}

void Menu::fillAskForLetterMenuContext()
{
	this->askForLetterMenuContext = "Your letter: ";
}

void Menu::printAskForLetterMenu()
{
	std::cout << this->askForLetterMenuContext;
}

void Menu::fillAllMenuContexts()
{
	fillMenuContext();
	fillAskForLetterMenuContext();
	fillAskforNoOfPlayerMenuContext();
}

void Menu::showMenu()
{
	std::cout << menuContext;
}