#include "Timer.h"

void Timer::Update()
{
	lastTime = glfwGetTime();
	actualTime += (glfwGetTime()-resetTime)/10;
}

double Timer::GetTime()
{
	return actualTime;
}

void Timer::Reset()
{
	resetTime = glfwGetTime();
}
