#ifndef GAME_H
#define GAME_H

#include "BaseGame.h"

class Game : public BaseGame
{
private:
	Entity3D* arthas;
	Entity3D* bolvar_chained;
	Entity3D* helm;
	Entity3D* building_0;
	Entity3D* building_1;
	Entity3D* building_2;
	Entity3D* building_3;
	Entity3D* sylvanas;
public:
	bool OnStart();
	bool OnStop();
	bool OnUpdate();
	void OnDraw();
};

#endif
