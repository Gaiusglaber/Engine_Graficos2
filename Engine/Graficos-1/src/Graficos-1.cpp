#include "Game.h"
#include <iostream>

void main()
{
	Game* g = new Game();
	

	if (g->Start(800, 1280, (char*) "	Warcraft 3.exe"))
	{
		g->Loop();
	}
	
	g->Stop();

	delete g;

	std::cin.get();
}