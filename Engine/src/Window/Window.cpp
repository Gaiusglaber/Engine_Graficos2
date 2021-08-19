#include "Window.h"
void Window::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwCreateWindow(width, height, title, monitor, share);	
}
void Window::MakeContextCurrent(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}
int Window::WindowShouldClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}