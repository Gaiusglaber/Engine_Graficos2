#include "Renderer/Renderer.h"
#include "glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
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

		unsigned int transformLoc = glGetUniformLocation(myRenderer->getShader(), "transform");
		glm::mat4 trans = glm::mat4(1.0f);
		trans = glm::translate(trans, glm::vec3(0, 0, 0.0f));
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		myRenderer->drawShape(shape);
		
		/* Swap front and back buffers */
		myRenderer->swapBuffers(myWindow->get());
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}