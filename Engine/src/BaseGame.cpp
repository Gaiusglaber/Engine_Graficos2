#include "Renderer/Renderer.h"
#include "glfw3.h"
int main(void)
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode _window and its OpenGL context */
	window* myWindow = new window(640, 480, "Hello World", NULL, NULL);
	
	if (!myWindow->get())
	{
		glfwTerminate();
		return -1;
	}

	/* Make the _window's context current */
	myWindow->makeContextCurrent(myWindow->get());
	
	Renderer* myRenderer = new Renderer(myWindow);
	Shape* shape = new Shape();
	
	/* Loop until the user closes the _window */
	while (!myWindow->windowShouldClose(myWindow->get()))
	{
		/* Render here */
		myRenderer->clearColor(GL_COLOR_BUFFER_BIT);

		myRenderer->drawShape(shape);
		
		/* Swap front and back buffers */
		myRenderer->swapBuffers(myWindow->get());
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}