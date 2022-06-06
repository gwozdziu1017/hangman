#pragma once

#include <string>

typedef std::string string;
typedef unsigned int uint;

class PlayerHandler {
public:
	PlayerHandler();
	PlayerHandler(uint _playerId, string _userName) : playerId(_playerId), userName(_userName), userLives(5) {}
	~PlayerHandler() {};
	void setUserName(string _userName);
	string getUserName();
	void decreaseUserLives();
	bool canUserContinue();
	short getNoOfLives();
	int getPlayerId();
private:
	uint playerId;
	string userName;
	short userLives;
};