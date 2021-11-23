#pragma once
#include "glfw3.h"
class Timer {
private:
	double actualTime = 0;
	double lastTime = 0;
	double resetTime = 0;
public:
	void Update();
	double GetTime();
	void Reset();
};