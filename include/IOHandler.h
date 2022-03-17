#pragma once
#include <iostream>
#include <string>
#include <vector>

class IOHandler
{
public:
	IOHandler() { };
	~IOHandler() { };

	template <typename T> static T getFromConsole();
	template<typename T> static void sendToConsole(const T _output);
	static void sendToConsole(const std::vector<char> _output);
};


template<typename T>
inline T IOHandler::getFromConsole()
{
	T tempValue;
	std::cin >> tempValue;
	return tempValue;
}

template<typename T>
inline void IOHandler::sendToConsole(T _output)
{
	std::cout << _output;
}

inline void IOHandler::sendToConsole(std::vector<char> _output)
{
	for (auto i : _output)
		std::cout << i;
}

/*
	I have generic solution like this below but I don't know why it's not working
	Error in else
*/
//template<typename T>
//inline void IOHandler::sendToConsole(T _output)
//{
//	if(std::is_same<std::vector<char>, decltype(_output)>::value)
//	{
//		// logic for vector printing
//		for (auto i : _output)
//			std::cout << i;
//	}
//	//--- Why there's an error ??
//	//else
//	//{
//	//	std::cout << _output;
//	//}
//}