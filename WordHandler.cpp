#include "WordHandler.h"

WordHandler::WordHandler() : sTheWord(nullptr), vAlreadyUsedLetters(0), sCurrentWord(nullptr) {}
WordHandler::~WordHandler() {}


string WordHandler::whGetWordFromDatabase()
{
	// currently returns only one word
	return "HANGMAN";
}

short WordHandler::whGetNoOfLettersInWord(string _word)
{
	return _word.length;
}

bool WordHandler::whFillTheWord(char _letter)
{
	bool isFoundInWord = false;

	for (short i = 0; i < this->sTheWord->length; i++)
	{
		if (_letter == sTheWord->at(i))
		{
			whShowLetterAtGivenIndex(i);
			whPutLetterIntoUsedLetters(_letter);
			isFoundInWord = true;
		}
	}
	return isFoundInWord;
}

bool WordHandler::whIsLetterAlreadyUsed(char _letter)
{
	if (vAlreadyUsedLetters.empty())
		return false;

	if (std::find(vAlreadyUsedLetters.begin(), vAlreadyUsedLetters.end(), _letter) != vAlreadyUsedLetters.end())
		return true;
	else
		return false;
}

void WordHandler::whShowLetterAtGivenIndex(short _index)
{
}

void WordHandler::whPutLetterIntoUsedLetters(char _letter)
{
	this->sTheWord->push_back(_letter);
}

void WordHandler::whCheckTheWord(char _letter)
{
	for (int i = 0; i < this->sTheWord->length; i++)
	{
		if (_letter == sTheWord->at(i))
		{
			this->vGuessedLettersIndexes->insert(i);
		}
	}
}

void WordHandler::whPrintCurrentWord()
{
}