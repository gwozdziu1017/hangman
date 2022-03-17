#include "../include/GameHandler.h"

void GameHandler::startGame()
{
	Menu::showMenu();
	short tempUserInput_short = IOHandler::getFromConsole<int>();
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

void GameHandler::gameOver()
{
	PlayerHandler::setGameOver();
	Menu::printPressAnyKeyToContinueMessage();
}

void GameHandler::startSingleplayerMode()
{
	WordHandler::setTheWord();
	WordHandler::fillCurrentWordWithDashesOnly(WordHandler::whGetNoOfLettersInTheWord());
	
	while (PlayerHandler::canUserContinue())
	{
		Menu::printWord(WordHandler::getCurrentWord());

		Menu::printAskForLetterMenu();
		this->letter = toupper(IOHandler::getFromConsole<char>());

		if (WordHandler::whIsLetterAlreadyUsed(this->letter))
		{
			Menu::printAlreadyUsedLetterMessage();
		}
		else
		{
			if (WordHandler::isLetterInTheWord(this->letter))
			{
				WordHandler::fillGuessedLettersIndexes(this->letter);
				WordHandler::setTheCorrectIndexes(this->letter);
				WordHandler::fillCurrentWordWithGuessedLetters();
				WordHandler::whPutLetterIntoUsedLetters(this->letter);
				if (WordHandler::isWholeWordGuessed())
				{
					// Player wins
					Menu::printYouWinMessage();
					GameHandler::gameOver();
				}
			}
			else
			{
				// TODO: print message: wrong letter
				PlayerHandler::decreaseUserLives();
				Menu::printWrongLetterMessage();
				Menu::printUserLives(PlayerHandler::getNoOfLives());
				if (PlayerHandler::getNoOfLives() == 0)
				{
					Menu::printYouLoseMessage();
					GameHandler::gameOver();
				}
				WordHandler::whPutLetterIntoUsedLetters(this->letter);
			}

		}
	}
}

void GameHandler::startMultiplayerMode(short _noOfPlayers)
{
	//TODO
}
