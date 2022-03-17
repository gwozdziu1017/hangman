#include "../include/Menu.h"

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
	fillYouWinMessageContext();
	fillYouLoseMessageContext();
	fillAlreadyUsedLetterContext();
	fillUserLivesMenuContext();
	fillWrongLetterMessageContext();
	fillPressAnyKeyToContinueMessageContext();
}

void Menu::printWord(std::vector<char> _word)
{
	for (auto i : _word)
	{
		IOHandler::sendToConsole(i);
		IOHandler::sendToConsole(" ");
	}
	IOHandler::sendToConsole(this->NEW_LINE);
}

void Menu::printYouWinMessage()
{
	system("cls");
	IOHandler::sendToConsole(youWinMessageContext);
}

void Menu::printYouLoseMessage()
{
	system("cls");
	IOHandler::sendToConsole(youLoseMessageContext);
}

void Menu::fillYouWinMessageContext()
{
	this->youWinMessageContext = "You win motherfucker!";
}

void Menu::fillYouLoseMessageContext()
{
	this->youLoseMessageContext = "You lose motherfucker!";
}

void Menu::fillAlreadyUsedLetterContext()
{
	this->alreadyUsedLetterContext = "This letter was already used.";
}

void Menu::printAlreadyUsedLetterMessage()
{
	IOHandler::sendToConsole(alreadyUsedLetterContext);
	IOHandler::sendToConsole(this->NEW_LINE);
}

void Menu::fillUserLivesMenuContext()
{
	this->userLivesMenuContext = "Your lives: ";
}

void Menu::printUserLives(short _lives)
{
	IOHandler::sendToConsole(userLivesMenuContext + std::to_string(_lives));
	IOHandler::sendToConsole<char>(this->NEW_LINE);
}

void Menu::fillWrongLetterMessageContext()
{
	this->wrongLetterMessageContext = "Wrong letter! ";
}

void Menu::printWrongLetterMessage()
{
	IOHandler::sendToConsole(this->wrongLetterMessageContext);
	IOHandler::sendToConsole(this->NEW_LINE);
}

void Menu::fillPressAnyKeyToContinueMessageContext()
{
	this->pressAnyKeyToContinueMessageContext = "Press any key to continue...";
}

void Menu::printPressAnyKeyToContinueMessage()
{
	IOHandler::sendToConsole(pressAnyKeyToContinueMessageContext);
}


void Menu::showMenu()
{
	IOHandler::sendToConsole(this->menuContext);
}