#include "BaseGame.h"

#include <GL/glew.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer/Renderer.h"
#include "Window/_window.h"

#include "VertexBuffer/VertexBuffer.h"
#include "VertexBufferLayout/VertexBufferLayout.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"
#include "Texture/Texture.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
namespace Engine
{
	Engine::base_game::base_game()
		: m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
	{
		std::cout << "umu" << std::endl;
	}
	void base_game::Init(int Width, int Height, const char* name)
	{
		/* Initialize the library */
		width = Width;
		height = Height;
		if (!glfwInit())
			glfwTerminate();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		/* Create a windowed mode _window and its OpenGL context */
		myWindow = new window(Width, Height, name, NULL, NULL);

		if (!myWindow->get())
		{
			glfwTerminate();
		}

		/* Make the _window's context current */
		myWindow->makeContextCurrent(myWindow->get());

		glfwSwapInterval(1);

		std::cout << glGetString(GL_VERSION) << std::endl;

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		//-----------------------------------------------------------------
		
		m_Shader = std::make_unique<Shader>("../res/shaders/Basic.shader");

		for (std::list<Shape*>::iterator it = shapeList.begin(); it != shapeList.end(); ++it)
		{
			(*it)->SetTexturePath();
		}
	}
	void base_game::Draw()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

		{
			for (std::list<Shape*>::iterator it = shapeList.begin(); it != shapeList.end(); ++it)
			{
				(*it)->Draw();
				glm::mat4 model = glm::translate(glm::mat4(1.0f), (*it)->GetPos());
				glm::mat4 mvp = m_Proj * m_View * model;
				m_Shader->Bind();
				m_Shader->SetUniformMat4f("u_MVP", mvp);
				renderer.Draw(*(*it)->m_VAO, *(*it)->m_IndexBuffer, *m_Shader);
			}
		}
	}
	void base_game::CreateShape(std::string Path)
	{
		Shape* shape = new Shape(-50,-50,50,50);
		shape->SetPos(glm::vec3(200,200,0));
		shape->SetPath(Path);
		shape->SetTexturePath();
		shapeList.push_back(shape);
	}
	void base_game::CreateShape(std::string Path, float minX, float minY, float maxX, float maxY)
	{
		Shape* shape = new Shape(minX, minY, maxX, maxY);
		shape->SetPos(glm::vec3(200, 200, 0));
		shape->SetPath(Path);
		shape->SetTexturePath();
		shapeList.push_back(shape);
	}
	void base_game::CreateShape(std::string Path, glm::vec3 m_Translation)
	{
		Shape* shape = new Shape(-50, -50, 50, 50);
		shape->SetPos(m_Translation);
		shape->SetPath(Path);
		shapeList.push_back(shape);
	}
	void base_game::CreateShape(std::string Path, glm::vec3 m_Translation, float minXAtlas,float maxXAtlas,float minYAtlas,float maxYAtlas)
	{
		Shape* shape = new Shape(-50, -50, 50, 50);
		shape->SetPos(m_Translation);
		shape->SetPath(Path);
		shape->SetMinXAtlas(minXAtlas);
		shape->SetMaxXAtlas(maxXAtlas);
		shape->SetMinXAtlas(minXAtlas);
		shape->SetMinYAtlas(minYAtlas);
		shapeList.push_back(shape);
	}
	void base_game::UpdateShapePos(int index, glm::vec3 m_Translation)
	{
		std::list<Shape*>::iterator it = shapeList.begin();
		std::advance(it, index);
		(*it)->SetPos(m_Translation);
	}
	Shape* base_game::GetShapeByIndex(int index)
	{
		std::list<Shape*>::iterator it = shapeList.begin();
		std::advance(it, index);
		return *it;
	}
	CollisionManager* base_game::GetCollisionManager()
	{
		return collisionManager;
	}
	void base_game::Play()
	{
		collisionManager->SetShapeList(shapeList);
		Renderer myRenderer;
		while (!glfwWindowShouldClose(myWindow->get()))
		{
			GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
			myRenderer.Clear();
			Update();
			Draw();
			glfwSwapBuffers(myWindow->get());
			glfwPollEvents();
		}
		glfwTerminate();
	}
}