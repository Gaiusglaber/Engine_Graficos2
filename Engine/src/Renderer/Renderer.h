#include "../Window/_window.h"
#include "../Shape/Shape.h"
#include "glfw3.h"
namespace Engine
{
	class ENGINE_API Renderer
	{
	private:
		Shape* shape;
		unsigned int shader;
		unsigned const int width = 800;
		unsigned const int height = 600;
	public:
		Renderer();
		Renderer(window* window);
		void clearColor(GLbitfield mask);
		void swapBuffers(GLFWwindow* window);
		void drawShape();
		unsigned int getShader();
		Shape* getShape();
	};
}