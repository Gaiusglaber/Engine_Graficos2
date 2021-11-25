#include "Timer.h"
void Timer::Update()
{
	actualTime = glfwGetTime();
	deltaTime = actualTime - lastTime;
	lastTime = glfwGetTime();
}

double Timer::GetTime()
{
	return deltaTime;
}

void Timer::Reset()
{
	deltaTime = 0;
	actualTime = 0;
	lastTime = 0;
}
