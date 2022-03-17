#include "PlayerHandler.h"

PlayerHandler::PlayerHandler() : userName(" "), userLives(5), gameOver(false)
{ }

void PlayerHandler::setUserName(string _userName)
{
	this->userName = _userName;
}

string PlayerHandler::getUserName()
{
	return this->userName;
}

void PlayerHandler::decreaseUserLives()
{
	this->userLives--;
}

bool PlayerHandler::canUserContinue()
{
	if (this->getNoOfLives() == 0
		|| this->gameOver == true)
		return false;
	else
		return true;
}

short PlayerHandler::getNoOfLives()
{
	return userLives;
}

void PlayerHandler::setGameOver()
{
	this->gameOver = true;
}
