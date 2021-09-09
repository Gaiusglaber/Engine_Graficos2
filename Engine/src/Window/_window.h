#ifndef _WINDOW_H
#define _WINDOW_H


#include "GL/glew.h"
#include "glfw3.h"
#include <iostream>
class window
{
	GLFWwindow* _window;
public:
	window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void makeContextCurrent(GLFWwindow* window);
	int windowShouldClose(GLFWwindow* window);
	GLFWwindow* get();
};
#endif // !_WINDOW_H