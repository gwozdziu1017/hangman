#pragma once

/*
Class WordHanlder reponsible for:
	* Word drawing from local database
	* Checking given by user letters
	* Fulfilling the word
Prefix: wh

	Created by: gwozdziu
	Date: 04.01.2022
*/

#include <vector>
#include <string>
#include <set>
#include <algorithm>

typedef std::string string;

class WordHandler
{
public:
	WordHandler();
	~WordHandler();
protected:
	string whGetWordFromDatabase();
	void setTheWord();
	string getTheWord();
	string getCurrentWord();
	int whGetNoOfLettersInTheWord();
	bool whIsLetterAlreadyUsed(char _letter);  // checks if letter was previously used
	void whPutLetterIntoUsedLetters(char _letter);
	void fillCurrentWordWithDashesOnly(short _noOfLetters); // fills current word with '_'
	void fillCurrentWordWithGuessedLetters();
	bool isLetterInTheWord(char _letter);
	void setTheCorrectIndexes(char _letter);
	std::vector<int> getTheCorrectIndexes();
	bool isWholeWordGuessed();
private:
	string sTheWord;
	std::vector<char> vAlreadyUsedLetters;
	std::set<short> vGuessedLettersIndexes;
	std::vector<int> correctIndexes;
	string sCurrentWord;
};