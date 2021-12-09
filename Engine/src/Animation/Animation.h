#pragma once
#include "Timer/timer.h"
#include "glm.hpp"
#include <vector>
#include <iostream>
class Animation {
private:
	Timer* timer = new Timer();
	float initialMinXAtlas = 0;
	float initialMaxXAtlas = 0;
	
	float minYAtlas = 0;
	
	float maxYAtlas = 0;
	float time = 0;
	float timePerAnimation = 0.1f;
	int totalAnimations = 0;
public:
	bool PlayAnimation(float& MinXAtlas, float& MaxXAtlas);
	Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, int totalAnimations);
	Animation(float MinXAtlas,float MinYAtlas, float MaxXAtlas,float MaxYAtlas,float TimePerAnimation);
	void SetAtlas(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas);
	void SetTime(float Time);
	Timer* GetTimer();
	void SetTimePerAnimation(float TimePerAnimation);
	std::vector<glm::vec2> frames;
};