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