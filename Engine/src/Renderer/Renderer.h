#include "glfw3.h"
class Renderer
{
public:
	void clearColor(GLbitfield mask);
	void swapBuffers(GLFWwindow* window);
};