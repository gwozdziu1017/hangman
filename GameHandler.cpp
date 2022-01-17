#include "GameHandler.h"

short GameHandler::getUserInput_short()
{
	short tempUserInput = 0;
	std::cin >> tempUserInput;
	return tempUserInput;
}

std::string GameHandler::getUserInput_string()
{
	std::string tempUserInput;
	std::cin >> tempUserInput;

	return tempUserInput;
}

char GameHandler::getUserInput_char()
{
	char tempUserInput;
	std::cin >> tempUserInput;

	return tempUserInput;
}

void GameHandler::startGame()
{
	short tempUserInput_short = getUserInput_short();
	switch (tempUserInput_short)
	{
	case 1: // singleplayer
		this->startSingleplayerMode();
		break;
	case 2: // multiplayer
		Menu::askForNoOfPlayers();
		this->setNoOfPlayers(this->getNoOfPlayers());
		this->startMultiplayerMode(this->noOfPlayers);
	case 0:
		// TODO: this is incorrect way of finishing program, a lot of unfreed memory
		system("exit");
		break;
	default:
		// TODO: add an error message that input is incorrect
		this->startGame();
		break;
	}
}

void GameHandler::setNoOfPlayers(short _noOfPlayers)
{
	this->noOfPlayers = _noOfPlayers;
}

short GameHandler::getNoOfPlayers()
{
	return this->noOfPlayers;
}

void GameHandler::startSingleplayerMode()
{
	std::vector<int>* correctIndexes = new std::vector<int>();

	WordHandler::setTheWord();
	WordHandler::fillCurrentWordWithDashesOnly(WordHandler::whGetNoOfLettersInTheWord());
	
	while (PlayerHandler::canUserContinue())
	{
		Menu::printWord(WordHandler::getCurrentWord());

		Menu::printAskForLetterMenu();
		this->letter = getUserInput_char();

		if (WordHandler::whIsLetterAlreadyUsed(this->letter))
		{
			//TODO print error: letter already used
			break;
		}
		else
		{
			if (WordHandler::isLetterInTheWord(this->letter))
			{
				WordHandler::setTheCorrectIndexes(this->letter);
				WordHandler::fillCurrentWordWithGuessedLetters();
				if (WordHandler::isWholeWordGuessed())
				{
					//TODO: Player wins
				}
			}
			else
			{
				// TODO: print message: wrong letter
				PlayerHandler::decreaseUserLives();
			}

		}
	}
}

void GameHandler::startMultiplayerMode(short _noOfPlayers)
{
	//TODO
}
