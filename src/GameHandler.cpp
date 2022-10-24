#include "../include/GameHandler.h"

/*
	Runs game.
	Returns false when game is over.
*/
bool GameHandler::run()
{
	this->startGame();
	return false;
}

/*
	Prints main menu and starts single or multiplier mode.
*/
void GameHandler::startGame()
{
	Menu::showMenu();
	std::string userInputString = IOHandler::getFromConsole<std::string>();
	short userInput {0};
	try
	{
		userInput = std::stoi (userInputString);
	}
	catch(const std::exception& e)
	{
		userInput = 0;
	}

	switch (userInput)
	{
	case 1:{ // singleplayer
		this->startSingleplayerMode();
		break;
	}
	case 2:{ // multiplayer
		Menu::askForNoOfPlayers();
		auto _noOfPlayers = IOHandler::getFromConsole<int>();
		this->setNoOfPlayers(_noOfPlayers);
		this->startMultiplayerMode(this->noOfPlayers);
		break;
	}
	case 3:{
		GameHandler::setGameOver(true);
		break;
	}
	default:{
		// TODO: add an error message that input is incorrect
		this->startGame();
		break;
	}
	}
}

/*
	Sets number of players.
*/
void GameHandler::setNoOfPlayers(short _noOfPlayers)
{
	this->noOfPlayers = _noOfPlayers;
}

/*
	Gets number of players.
	Returns noOfPlayers.
*/
short GameHandler::getNoOfPlayers()
{
	return this->noOfPlayers;
}

/*
	Handles situation when user gave correct letter
*/
void GameHandler::correctLetter()
{
	WordHandler::fillGuessedLettersIndexes(this->letter);
	WordHandler::setTheCorrectIndexes(this->letter);
	WordHandler::fillCurrentWordWithGuessedLetters();
	WordHandler::whPutLetterIntoUsedLetters(this->letter);
	if (WordHandler::isWholeWordGuessed())
	{
		// Player wins
		Menu::printYouWinMessage();
		Menu::printPressAnyKeyToContinueMessage();
		setGameOver(true);
	}
}

/*
	Handles situation when user gave incorrect letter
*/
void GameHandler::incorrectLetter()
{
	PlayerHandler::decreaseUserLives();
	Menu::printWrongLetterMessage();
	Menu::printUserLives(PlayerHandler::getNoOfLives());
	if (PlayerHandler::getNoOfLives() == 0)
	{
		Menu::printYouLoseMessage();
		Menu::printPressAnyKeyToContinueMessage();
		setGameOver(true);
	}
	WordHandler::whPutLetterIntoUsedLetters(this->letter);
}

/*
	Shared part of the game.
	Printing current word, asking for letter and proceeding with given letter
*/
void GameHandler::continueGame()
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
			this->correctLetter();
		else
			this->incorrectLetter();
	}
}

/*
	Starts game for singleplayer mode.
*/
void GameHandler::startSingleplayerMode()
{
	WordHandler::setTheWord();
	WordHandler::fillCurrentWordWithDashesOnly(WordHandler::whGetNoOfLettersInTheWord());
	
	while (!isGameOver())
	{
		this->continueGame();
	}
}

/*
	Returns true if game can be continued.
*/
bool GameHandler::isGameOver(std::vector<std::shared_ptr<PlayerHandler> > vectorOfPlayers)
{
	if(gameOver)
		return true;

	if(vectorOfPlayers.size() > 0)
	{
		for(auto player : vectorOfPlayers)
		{
			if (player -> canUserContinue() == true)
				return false;
		}
		return true;
	}
	else
	{
		return !PlayerHandler::canUserContinue();
	}
}

/*
	Setup players for multiplayer mode by asking and assigning them ids names etc.
*/
void GameHandler::setupPlayers(const int _noOfPlayers, std::vector<std::shared_ptr<PlayerHandler> >& _vectorOfPlayers)
{
	uint playerId_ = 0;
	for(int playerIter = 1; playerIter <= _noOfPlayers; playerIter++)
	{
		Menu::fillAskForNameMenuContext(playerIter);
		Menu::printAskForNameMenuContext();
		
		std::string playerName = IOHandler::getFromConsole<std::string>();
		std::shared_ptr<PlayerHandler> playerPtr = std::make_shared<PlayerHandler>(playerId_, playerName);

		_vectorOfPlayers.push_back(playerPtr);
		playerId_++;
	}
}
void GameHandler::startMultiplayerMode(short _noOfPlayers)
{
	// Setup players
	std::vector<std::shared_ptr<PlayerHandler> > vectorOfPlayers;
	vectorOfPlayers.reserve(_noOfPlayers);
	this->setupPlayers(_noOfPlayers, vectorOfPlayers);
	bool switchPlayer = false;
	int playerId = 0;

	WordHandler::setTheWord();
	WordHandler::fillCurrentWordWithDashesOnly(WordHandler::whGetNoOfLettersInTheWord());

	while(!isGameOver(vectorOfPlayers))
	{
		Menu::printWord(WordHandler::getCurrentWord());
		IOHandler::sendToConsole(vectorOfPlayers[playerId]->getUserName() + " ");
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
					GameHandler::setGameOver(true);
				}
			}
			else
			{
				vectorOfPlayers[playerId] -> decreaseUserLives();
				Menu::printWrongLetterMessage();
				IOHandler::sendToConsole(vectorOfPlayers[playerId]->getUserName() + " ");
				Menu::printUserLives(vectorOfPlayers[playerId]->getNoOfLives());
				if (vectorOfPlayers[playerId] -> getNoOfLives() == 0)
				{
					Menu::printYouLoseMessage();
				}
				playerId = this->getNextPlayerId(vectorOfPlayers, playerId);
				if(playerId == -1)
					this->setGameOver(true);
				switchPlayer = true;

				WordHandler::whPutLetterIntoUsedLetters(this->letter);
			}
		}
	}
}

int GameHandler::getNextPlayerId(std::vector<std::shared_ptr<PlayerHandler> > vectorOfPlayers, const int currentPlayerId)
{
	// first of all look from current player to end of players vector
	for(auto tempId = currentPlayerId + 1; tempId < vectorOfPlayers.size(); tempId++)
	{
		if(vectorOfPlayers[tempId] -> canUserContinue())
			return tempId;
	}

	// if there is no player after current one then find first lowest id of player who can continue
	for(auto playerPtr : vectorOfPlayers)
	{
		// if current player occurs again it means that there is no other player left
		if(playerPtr->getPlayerId() > currentPlayerId)
			return -1;
		else
		{
			if(playerPtr->canUserContinue())
				return playerPtr->getPlayerId();
		}
	}
	return -1;
}

void GameHandler::setGameOver(bool value)
{
	this->gameOver = value;
}
