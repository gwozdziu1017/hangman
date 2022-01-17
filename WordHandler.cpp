#include "WordHandler.h"

WordHandler::WordHandler() : sTheWord(nullptr), vAlreadyUsedLetters(0), sCurrentWord(nullptr) {}
WordHandler::~WordHandler() {}


string WordHandler::whGetWordFromDatabase()
{
	// currently returns only one word
	return "HANGMAN";
}

void WordHandler::setTheWord()
{
	this->sTheWord = this->whGetWordFromDatabase();
}

string WordHandler::getTheWord()
{
	return this->sTheWord;
}

string WordHandler::getCurrentWord()
{
	return this->sCurrentWord;
}

int WordHandler::whGetNoOfLettersInTheWord()
{
	return this->sTheWord.length();
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

void WordHandler::whPutLetterIntoUsedLetters(char _letter)
{
	vAlreadyUsedLetters.push_back(_letter);
}

void WordHandler::fillCurrentWordWithDashesOnly(short _noOfLetters)
{
	for (short i = 0; i++; i < _noOfLetters)
	{
		sCurrentWord.append("_");
	}
}

void WordHandler::fillCurrentWordWithGuessedLetters()
{
	for (int i = 0; i < correctIndexes.size(); i++)
	{
		sCurrentWord.at(i) = sTheWord.at(i);
	}
}

bool WordHandler::isLetterInTheWord(char _letter)
{
	for (short i = 0; i < sTheWord.length(); i++)
	{
		if (sTheWord.at(i) == _letter)
			return true;
	}
	return false;
}

void WordHandler::setTheCorrectIndexes(char _letter)
{
	for (short i = 0; i < sTheWord.length(); i++)
	{
		if (_letter == (char)sTheWord.at(i))
		{
			correctIndexes.push_back(i);
		}
	}
	std::sort(correctIndexes.begin(), correctIndexes.end());
}

std::vector<int> WordHandler::getTheCorrectIndexes()
{
	return this->correctIndexes;
}

bool WordHandler::isWholeWordGuessed()
{
	if (sCurrentWord.size() == sTheWord.size())	//TODO check if this is correct
		return true;
	else
		return false;
}

