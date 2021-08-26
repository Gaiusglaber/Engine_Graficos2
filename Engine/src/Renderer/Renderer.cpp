#include "Renderer.h"
void Renderer::clearColor(GLbitfield mask)
{
	glClear(mask);
}
void Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}