#include <GL/glew.h>
#include "Shape.h"
namespace Engine
{
	glm::mat4 Shape::GetModel()
	{
		return model;
	}
	void Shape::SetModel(glm::mat4 _model)
	{
		model = _model;
	}
	void Shape::Draw()
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
	void Shape::SetPos(glm::vec3 pos)
	{
		model = glm::translate(model, pos);
	}
	void Shape::SetRot(glm::vec3 rot)
	{
		model = glm::rotate(model, (float)glfwGetTime(), rot);
	}
	void Shape::SetScale(glm::vec3 scale)
	{
		model = glm::scale(model, scale);
	}
	void Shape::SetMinXAtlas(float MinXAtlas)
	{
		minXAtlas = MinXAtlas;
	}
	void Shape::SetMinYAtlas(float MinYAtlas)
	{
		minYAtlas = MinYAtlas;
	}
	void Shape::SetMaxXAtlas(float MaxXAtlas)
	{
		maxXAtlas = MaxXAtlas;
	}
	void Shape::SetMaxYAtlas(float MaxYAtlas)
	{
		maxYAtlas = MaxYAtlas;
	}
}