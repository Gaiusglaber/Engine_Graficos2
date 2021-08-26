#include "glfw3.h"
class Window
{
public:
	void CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void MakeContextCurrent(GLFWwindow* window);
	int WindowShouldClose(GLFWwindow* window);
};