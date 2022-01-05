#pragma once
#pragma once

/*
Interface for WordHanlder class.

Created by: gwozdziu
Date: 05.01.2022
*/

#include <string>

typedef std::string string;

class IWordHandler
{
public:
	IWordHandler() {};
	~IWordHandler() {};
protected:
	virtual string whGetWordFromDatabase() = 0;
	virtual short whGetNoOfLettersInWord(string _word) = 0;
	virtual bool whFillTheWord(char _letter) = 0;
	virtual bool whIsLetterAlreadyUsed(char _letter) = 0;
	virtual void whShowLetterAtGivenIndex(short _index) = 0;
	virtual void whPutLetterIntoUsedLetters(char _letter) = 0;
	virtual void whCheckTheWord(char _letter) = 0;
	virtual void whPrintCurrentWord() = 0;
	virtual void whFillTheWordWithDashes(size_t _size) = 0;
	virtual void whSetTheWord() = 0;
private:
};