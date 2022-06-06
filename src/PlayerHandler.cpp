#include "../include/PlayerHandler.h"

PlayerHandler::PlayerHandler() : userName(" "), userLives(5)
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
	if (this->getNoOfLives() == 0)
		return false;
	else
		return true;
}

short PlayerHandler::getNoOfLives()
{
	return userLives;
}

int PlayerHandler::getPlayerId()
{
	return playerId;
}