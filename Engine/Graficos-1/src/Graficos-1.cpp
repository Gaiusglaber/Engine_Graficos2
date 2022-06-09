#include "Game.h"
#include <iostream>

void main()
{
	Game* g = new Game();
	

	if (g->Start(1920, 1280, (char*) "Engine"))
	{
		g->Loop();
	}
	
	g->Stop();

	delete g;

	std::cin.get();
}