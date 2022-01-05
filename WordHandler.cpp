#include "WordHandler.h"

WordHandler::WordHandler() : sTheWord(""), vAlreadyUsedLetters(0), sCurrentWord(nullptr) {}
WordHandler::~WordHandler() {}


string WordHandler::whGetWordFromDatabase()
{
	// currently returns only one word
	return "HANGMAN";
}

void WordHandler::whSetTheWord()
{
	sTheWord = whGetWordFromDatabase();
}

short WordHandler::whGetNoOfLettersInWord(string _word)
{
	return (int)_word.size();
}

bool WordHandler::whFillTheWord(char _letter)
{
	bool isFoundInWord = false;

	for (short i = 0; i < sTheWord.size(); i++)
	{
		if (_letter == sTheWord.at(i))
		{
			this->sCurrentWord->insert(i, 1, _letter);
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
	sTheWord.push_back(_letter);
}

void WordHandler::whCheckTheWord(char _letter)
{
	for (int i = 0; i < sTheWord.size(); i++)
	{
		if (_letter == sTheWord.at(i))
		{
			this->vGuessedLettersIndexes->insert(i);
		}
	}
}

void WordHandler::whPrintCurrentWord()
{
	std::cout << this->sCurrentWord;
}

void WordHandler::whFillTheWordWithDashes(size_t _size)
{
	this->sCurrentWord->append(7u, '-');
		//this->sCurrentWord->insert(i, 1, '_');
		//this->sCurrentWord->insert(i + 1, 1, ' ');	 
}
// the last character will be space
// TODO: remove last unnecessary space