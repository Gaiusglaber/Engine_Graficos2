#include "Animation.h"
bool Animation::PlayAnimation(float& MinXAtlas, float& MaxXAtlas)
{
	if (timer->getTime() <= timePerAnimation) {
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
		timer->reset();
	}
	return true;
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, int _totalAnimations)
{
	totalAnimations = _totalAnimations;
	timer->start();
	initialMaxXAtlas = MaxXAtlas;
	initialMinXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxYAtlas = MaxYAtlas;
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, float TimePerAnimation)
{
	timer->start();
	initialMaxXAtlas = MaxXAtlas;
	initialMinXAtlas = MinXAtlas;
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
	timePerAnimation = TimePerAnimation;
}

void Animation::SetAtlas(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas)
{
	initialMaxXAtlas = MaxXAtlas;
	initialMinXAtlas = MinXAtlas;
	minXAtlas = MinXAtlas;
	minYAtlas = MinYAtlas;
	maxXAtlas = MaxXAtlas;
	maxYAtlas = MaxYAtlas;
}

void Animation::SetTime(float Time)
{
	time = Time;
}

Timer* Animation::GetTimer()
{
	return timer;
}

void Animation::SetTimePerAnimation(float TimePerAnimation)
{
	timePerAnimation = TimePerAnimation;
}
