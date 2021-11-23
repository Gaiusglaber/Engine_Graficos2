#include "Animation.h"

bool Animation::PlayAnimation(float& MinXAtlas, float& MaxXAtlas)
{
	timer->Update();
	std::cout << timer->GetTime()<<std::endl;
	if (timer->GetTime() < timePerAnimation) {
		return false;
	}
	else {
		if (MaxXAtlas > 1) {
			MaxXAtlas = initialMaxXAtlas;
			MinXAtlas = initialMinXAtlas;
		}
		else {
			MaxXAtlas += initialMaxXAtlas;
			MinXAtlas += initialMaxXAtlas;
		}
		return true;
	}
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas)
{
	initialMaxXAtlas = MaxXAtlas;
	initialMinXAtlas = MinXAtlas;
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, float TimePerAnimation)
{
	initialMaxXAtlas = MaxXAtlas;
	initialMinXAtlas = MinXAtlas;
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
	timePerAnimation = TimePerAnimation;
}

void Animation::SetTime(float Time)
{
	time = Time;
}

float Animation::GetTime()
{
	return time;
}
