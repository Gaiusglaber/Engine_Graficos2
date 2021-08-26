#include "glfw3.h"
class Window
{
	GLFWwindow* window;
public:
	void createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void makeContextCurrent(GLFWwindow* window);
	int windowShouldClose(GLFWwindow* window);
	GLFWwindow* get();
};