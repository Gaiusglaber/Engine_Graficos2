#include "Animation.h"
bool Animation::PlayAnimation(float& MinXAtlas, float& MaxXAtlas,float & MinYAtlas, float & MaxYAtlas, int textureWidth, int textureHeight)
{
	/*for (int i = 0; i < totalAnimations; i++) {
		if (frames[i] == NULL) {
			frames[i] = new Frame()
		}
	}
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
	}*/
	return true;
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, int _totalAnimations)
{
	totalAnimations = _totalAnimations;
	timer->start();
}

Animation::Animation(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas, float TimePerAnimation)
{
	timer->start();
	timePerAnimation = TimePerAnimation;
}

void Animation::SetAtlas(float MinXAtlas, float MinYAtlas, float MaxXAtlas, float MaxYAtlas)
{
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
