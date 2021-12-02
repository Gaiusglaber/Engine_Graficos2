#pragma once
#include "Timer/timer.h"
#include <iostream>;
class Animation {
private:
	Timer* timer = new Timer();
	float initialMinXAtlas = 0;
	float initialMaxXAtlas = 0;
	float minXAtlas = 0;
	float minYAtlas = 0;
	float maxXAtlas = 0;
	float maxYAtlas = 0;
	float time = 0;
	float timePerAnimation = 0.1f;
public:
	bool PlayAnimation(float& MinXAtlas, float& MaxXAtlas);
	Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas);
	Animation(float MinXAtlas,float MinYAtlas, float MaxXAtlas,float MaxYAtlas,float TimePerAnimation);
	void SetAtlas(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas);
	void SetTime(float Time);
	Timer* GetTimer();
	void SetTimePerAnimation(float TimePerAnimation);
};