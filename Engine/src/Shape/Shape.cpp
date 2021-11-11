#include <GL/glew.h>
#include "Shape.h"
namespace Engine
{
	Shape::Shape()
	{
		positions[0] = -50.0f;
		positions[1] = -50.0f;
		positions[2] = 0.0f;
		positions[3] = 0.0f;

		positions[4] = 50.0f;
		positions[5] = -50.0f;
		positions[6] = 1.0f;
		positions[7] = 0.0f;

		positions[8] = 50.0f;
		positions[9] = 50.0f;
		positions[10] = 1.0f;
		positions[11] = 1.0f;

		positions[12] = -50.0f;
		positions[13] = 50.0f;
		positions[14] = 0.0f;
		positions[15] = 1.0f;

		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;

		indices[3] = 2;
		indices[4] = 3;
		indices[5] = 0;
	}
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
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		m_Texture->Bind();
	}
	void Shape::SetPos(glm::vec3 pos)
	{
		m_translation = pos;
		model = glm::translate(model, pos);
	}
	void Shape::SetPath(std::string Path)
	{
		path = Path;
	}
	void Shape::SetTexturePath()
	{
		m_Texture = std::make_unique<Texture>(path);
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
	void Shape::SetTime(float Time)
	{
		time = Time;
	}
	void Shape::SetTexture(std::unique_ptr<Texture> m_Texture)
	{
	}
	glm::vec3 Shape::GetPos()
	{
		return m_translation;
	}
	std::string Shape::GetPath()
	{
		return path;
	}
	glm::vec4 Shape::GetRot()
	{
		return m_rotation;
	}
	glm::vec3 Shape::GetScale()
	{
		return m_scale;
	}
	float Shape::GetMinXAtlas()
	{
		return minXAtlas;
	}
	float Shape::GetMinYAtlas()
	{
		return minYAtlas;
	}
	float Shape::GetMaxXAtlas()
	{
		return maxXAtlas;
	}
	float Shape::GetMaxYAtlas()
	{
		return maxYAtlas;
	}
	float Shape::GetTime()
	{
		return time;
	}
}