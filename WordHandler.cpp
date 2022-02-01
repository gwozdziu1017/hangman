#include "WordHandler.h"


WordHandler::WordHandler() : theWord(""),
							vectorAlreadyUsedLetters(),
							setGuessedLettersIndexes(),
							vectorCorrectIndexes(),
							vCurrentWord()
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

std::vector<char> WordHandler::getCurrentWord()
{
	return this->vCurrentWord;
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
	for (short i = 0; i < _noOfLetters; i++)
	{
		vCurrentWord.push_back('_');
	}
}

void WordHandler::fillCurrentWordWithGuessedLetters()
{
	for (std::set<short>::iterator it = setGuessedLettersIndexes.begin();
		it != setGuessedLettersIndexes.end();
		it++)
	{
		vCurrentWord.at(*it) = theWord[*it];
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
	for (auto it = 0; it < vCurrentWord.size(); it++)
	{
		if (vCurrentWord.at(it) != theWord[it])
		{
			return false;
		}
	}

	return true;
}

int WordHandler::getIndexOfGivenLetterInTheWord(char _letter)
{
	auto it = std::find(theWord.begin(), theWord.end(), _letter);
	if (it != theWord.end()) // if element was found
	{
		int index = it - theWord.begin();
		return index;
	}

	return -1;	// not found
}

void WordHandler::fillGuessedLettersIndexes(char _letter)
{
	for (auto it = 0; it < theWord.length(); it++)
	{
		if (theWord[it] == _letter)
			setGuessedLettersIndexes.insert(it);
	}

}

