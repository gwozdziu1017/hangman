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
	short whGetNoOfLettersInWord(string _word);
	bool whFillTheWord(char _letter);  // filling the word and returns true if letter was found in the word
	bool whIsLetterAlreadyUsed(char _letter);  // checks if letter was previously used
	void whShowLetterAtGivenIndex(short _index);
	void whPutLetterIntoUsedLetters(char _letter);
	void whCheckTheWord(char _letter);	// checks if letters given by user match with the word and returns on which indexes there is match
	void whPrintCurrentWord();
private:
	string* sTheWord;
	std::vector<char> vAlreadyUsedLetters;
	std::set<short>* vGuessedLettersIndexes;
	string* sCurrentWord;
};