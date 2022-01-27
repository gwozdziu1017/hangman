#include "WordHandler.h"


WordHandler::WordHandler() : theWord(""),
							vectorAlreadyUsedLetters(),
							setGuessedLettersIndexes(),
							vectorCorrectIndexes(),
							currentWord("")
{ }

string WordHandler::whGetWordFromDatabase()
{
	// currently returns only one word
	return "HANGMAN";
}

void WordHandler::setTheWord()
{
	this->theWord.assign(this->whGetWordFromDatabase());
}

string WordHandler::getTheWord()
{
	return this->theWord;
}

string WordHandler::getCurrentWord()
{
	return this->currentWord;
}

int WordHandler::whGetNoOfLettersInTheWord()
{
	return this->theWord.length();
}

bool WordHandler::whIsLetterAlreadyUsed(char _letter)
{
	if (vectorAlreadyUsedLetters.empty())
		return false;

	if (std::find(vectorAlreadyUsedLetters.begin(), vectorAlreadyUsedLetters.end(), _letter) != vectorAlreadyUsedLetters.end())
		return true;
	else
		return false;
}

void WordHandler::whPutLetterIntoUsedLetters(char _letter)
{
	vectorAlreadyUsedLetters.push_back(_letter);
}

void WordHandler::fillCurrentWordWithDashesOnly(short _noOfLetters)
{
	for (short i = 0; i++; i < _noOfLetters)
	{
		currentWord.append("_"); // pusty current word
	}
}

void WordHandler::fillCurrentWordWithGuessedLetters()
{
	for (auto i : vectorCorrectIndexes)
	{
		currentWord.insert(i, 1, theWord[i]);
	}
}

bool WordHandler::isLetterInTheWord(char _letter)
{
	for (auto letterInTheWord : theWord)
	{
		if (letterInTheWord == _letter)
			return true;
	}
	return false;
}

void WordHandler::setTheCorrectIndexes(char _letter)
{
	short tempIndex = 0;
	for (auto letterInTheWord : theWord)
	{
		if (_letter == letterInTheWord)
		{
			vectorCorrectIndexes.push_back(tempIndex);
		}
		tempIndex++;
	}
	std::sort(vectorCorrectIndexes.begin(), vectorCorrectIndexes.end());
}

std::vector<int> WordHandler::getTheCorrectIndexes()
{
	return this->vectorCorrectIndexes;
}

bool WordHandler::isWholeWordGuessed()
{
	if (currentWord == theWord)
		return true;
	else
		return false;
}

