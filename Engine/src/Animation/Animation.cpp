#include "Animation.h"

void Animation::PlayRightAnimation(float& MinXAtlas, float& MinYAtlas, float& MaxXAtlas, float& MaxYAtlas)
{
	glfwGetTime();//retorna el tiempo
	if (time < timePerAnimation) {
	}
}

void Animation::PlayLeftAnimation(float& MinXAtlas, float& MinYAtlas, float& MaxXAtlas, float& MaxYAtlas)
{

}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas)
{
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, float TimePerAnimation)
{
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
	timePerAnimation = TimePerAnimation;
}

void Animation::SetMinXAtlas(float MinXAtlas)
{
	minXAtlas = MinXAtlas;
}

void Animation::SetMinYAtlas(float MinYAtlas)
{
	minYAtlas = MinYAtlas;
}

void Animation::SetMaxXAtlas(float MaxXAtlas)
{
	maxXAtlas = MaxXAtlas;
}

void Animation::SetMaxYAtlas(float MaxYAtlas)
{
	maxYAtlas = MaxYAtlas;
}

void Animation::SetTime(float Time)
{
	time = Time;
}

float Animation::GetMinXAtlas()
{
	return minXAtlas;
}

float Animation::GetMinYAtlas()
{
	return minYAtlas;
}

float Animation::GetMaxXAtlas()
{
	return maxXAtlas;
}

float Animation::GetMaxYAtlas()
{
	return maxYAtlas;
}

float Animation::GetTime()
{
	return time;
}
