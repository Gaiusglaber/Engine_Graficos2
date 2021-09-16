#ifndef RENDERER_H
#define RENDERER_H


#include "../Window/_window.h"
#include "../Shape/Shape.h"
#include "glfw3.h"
class Renderer
{
private:
	unsigned int shader;
public:
	Renderer();
	Renderer(window* window);
	void clearColor(GLbitfield mask);
	void swapBuffers(GLFWwindow* window);
	void drawShape(Shape* shape);
	unsigned int getShader();
};
#endif // !RENDERER_H