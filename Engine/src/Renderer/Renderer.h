#ifndef RENDERER_H
#define RENDERER_H


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
#endif // !RENDERER_H