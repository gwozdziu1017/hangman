#pragma once

#include <string>

typedef std::string string;

class PlayerHandler {
public:
	PlayerHandler();
	~PlayerHandler() {};
protected:
	void setUserName(string _userName);
	string getUserName();
	void decreaseUserLives();
	bool canUserContinue();
	short getNoOfLives();
private:
	string userName;
	short userLives;

};