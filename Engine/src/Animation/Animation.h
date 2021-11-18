#pragma once
#include "glfw3.h"
class Animation {
private:
	float minXAtlas = 0;
	float minYAtlas = 0;
	float maxXAtlas = 0;
	float maxYAtlas = 0;
	float time = 0;
	float timePerAnimation = 1;
public:
	void PlayRightAnimation(float & MinXAtlas, float & MinYAtlas, float & MaxXAtlas, float & MaxYAtlas);
	void PlayLeftAnimation(float& MinXAtlas, float& MinYAtlas, float& MaxXAtlas, float& MaxYAtlas);
	Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas);
	Animation(float MinXAtlas,float MinYAtlas, float MaxXAtlas,float MaxYAtlas,float TimePerAnimation);
	void SetMinXAtlas(float MinXAtlas);
	void SetMinYAtlas(float MinYAtlas);
	void SetMaxXAtlas(float MaxXAtlas);
	void SetMaxYAtlas(float MaxYAtlas);
	void SetTime(float Time);
	float GetMinXAtlas();
	float GetMinYAtlas();
	float GetMaxXAtlas();
	float GetMaxYAtlas();
	float GetTime();
};