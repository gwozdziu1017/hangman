#include "Menu.h"

void Menu::fillMenuContext()
{
	this->menuContext = "----- HANGMAN -----\n";
	this->menuContext.append("Menu:\n");
	this->menuContext.append("[1] Singleplayer mode\n");
	this->menuContext.append("[2] Multiplayer mode\n");
	this->menuContext.append("[0] Quit");
	this->menuContext.append("\n");
	this->menuContext.append("Player choice: ");
}

void Menu::askForNoOfPlayers()
{
	IOHandler::sendToConsole(askforNoOfPlayerMenuContext);
}

void Menu::fillAskforNoOfPlayerMenuContext()
{
	this->askforNoOfPlayerMenuContext = "Insert no of players: ";
}

void Menu::printWord(std::string _word)
{
	IOHandler::sendToConsole(_word);
}

void Menu::fillAskForLetterMenuContext()
{
	this->askForLetterMenuContext = "Your letter: ";
}

void Menu::printAskForLetterMenu()
{
	IOHandler::sendToConsole(this->askForLetterMenuContext);
}

void Menu::fillAllMenuContexts()
{
	fillMenuContext();
	fillAskForLetterMenuContext();
	fillAskforNoOfPlayerMenuContext();
}

void Menu::printWord(std::vector<char> _word)
{
	for (auto i : _word)
	{
		IOHandler::sendToConsole(i);
		IOHandler::sendToConsole(" ");
	}
}

void Menu::printYouWinMessage()
{
	system("cls");
	IOHandler::sendToConsole("You win motherfucker!");
}

void Menu::showMenu()
{
	IOHandler::sendToConsole(this->menuContext);
}