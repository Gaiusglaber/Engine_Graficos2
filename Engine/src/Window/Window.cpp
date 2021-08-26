#include "Window.h"
void Window::createWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	window = glfwCreateWindow(width, height, title, monitor, share);
}
void Window::makeContextCurrent(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}
int Window::windowShouldClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}
GLFWwindow* Window::get()
{
	return window;
}