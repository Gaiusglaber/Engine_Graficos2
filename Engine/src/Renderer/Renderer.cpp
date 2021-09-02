#include "Renderer.h"
std::string vertexShader =
"#version 330 core\n"
"\n"
"layout(location = 0) in vec4 position;\n"
"void main()\n"
"{\n"
"	gl_Position = position\n"
"}\n";
std::string fragmentShader =
"#version 330 core\n"
"\n"
"layout(location = 0) out vec4 color;\n"
"void main()\n"
"{\n"
"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\n";
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
		char* message = (char*)alloca(lenght * sizeof(char));
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
Renderer::Renderer()
{

}
Renderer::Renderer(window* window)
{
	float positions[6] = {
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);
}
void Renderer::clearColor(GLbitfield mask)
{
	glClear(mask);
}
void Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}