#pragma once
#include "Timer/timer.h"
#include "glm.hpp"
#include <vector>
#include <iostream>
#include "Frame/Frame.h"
class Animation {
private:
	Timer* timer = new Timer();
	float time = 0;
	float timePerAnimation = 0.1f;
	int totalAnimations = 0;
public:
	bool PlayAnimation(float& MinXAtlas, float& MaxXAtlas, float& MinYAtlas, float& MaxYAtlas,int textureWidth,int textureHeight);
	Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, int totalAnimations);
	Animation(float MinXAtlas,float MinYAtlas, float MaxXAtlas,float MaxYAtlas,float TimePerAnimation);
	void SetAtlas(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas);
	void SetTime(float Time);
	Timer* GetTimer();
	void SetTimePerAnimation(float TimePerAnimation);
	std::vector<Frame*> frames;
};