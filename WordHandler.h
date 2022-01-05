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
#include "IWordHandler.h"

#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

typedef std::string string;

class WordHandler : IWordHandler
{
public:
	WordHandler();
	~WordHandler();
//protected:
	string whGetWordFromDatabase() override;
	short whGetNoOfLettersInWord(string _word) override;
	bool whFillTheWord(char _letter) override;  // filling the word and returns true if letter was found in the word
	bool whIsLetterAlreadyUsed(char _letter) override;  // checks if letter was previously used
	void whShowLetterAtGivenIndex(short _index) override;
	void whPutLetterIntoUsedLetters(char _letter) override;
	void whCheckTheWord(char _letter) override;	// checks if letters given by user match with the word and returns on which indexes there is match
	void whPrintCurrentWord() override;
	void whFillTheWordWithDashes(size_t _size) override;   // filling the word with "_ _ _ _"
	void whSetTheWord() override;
//private:
	string sTheWord;
	std::vector<char> vAlreadyUsedLetters;
	std::set<short>* vGuessedLettersIndexes;
	string* sCurrentWord;
};