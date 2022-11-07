#include "../include/GameHandler.h"
#include <memory>

int main()
{
	std::unique_ptr<GameHandler> gamePtr = std::make_unique<GameHandler>();
	if(!gamePtr->run())
		EXIT_SUCCESS;
	

	return 0;
}