#include "../Window/_window.h"
#include "glfw3.h"
class Renderer
{
	
public:
	Renderer();
	Renderer(window* window);
	void clearColor(GLbitfield mask);
	void swapBuffers(GLFWwindow* window);
};
