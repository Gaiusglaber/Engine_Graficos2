#include "Renderer.h"
#include "fstream"
#include "string"
#include <sstream>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <iostream>
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};
static ShaderProgramSource ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(),ss[1].str() };
}
static unsigned int compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)_malloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}
static int createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}
Engine::Renderer::Renderer()
{

}
Engine::Renderer::Renderer(window* window)
{
	float positions[] = {
		-0.5f, -0.5f,//0
		0.5f, -0.5f, //1
		0.5f, 0.5f,  //2
		-0.5f,0.5f,  //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	//glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

	
	ShaderProgramSource source = ParseShader("../res/shaders/Basic.shader");

	shader = createShader(source.VertexSource, source.FragmentSource);
	
	glUseProgram(shader);
	
}
void Engine::Renderer::clearColor(GLbitfield mask)
{
	glClear(mask);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Engine::Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}
void Engine::Renderer::drawShape()
{
	shape->draw();//en este caso hay solo 1 shape pero en el caso siguiente seria:
	/*for (int i=0;i<cantShape;i++)
	{
		shape[i]->draw();
	}*/
}

unsigned int Engine::Renderer::getShader()
{
	return shader;
}

Engine::Shape* Engine::Renderer::getShape()
{
	return shape;
}
