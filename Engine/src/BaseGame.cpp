#include "glfw3.h"
#include "Window/Window.h"
#include "Renderer/Renderer.h"
int main(void)
{
	Window myWindow;
	Renderer myRenderer;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	myWindow.createWindow(640, 480, "Hello World", NULL, NULL);
	
	if (!myWindow.get())
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	myWindow.makeContextCurrent(myWindow.get());
	
	/* Loop until the user closes the window */
	while(!myWindow.windowShouldClose(myWindow.get()))
	{
		/* Render here */
		myRenderer.clearColor(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		myRenderer.swapBuffers(myWindow.get());
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}