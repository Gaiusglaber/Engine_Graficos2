#include <GL/glew.h>
#include "Shape.h"
namespace Engine
{
	Shape::Shape(float minX, float minY,float maxX, float maxY)
	{
		positions[0] = minX;
		positions[1] = minY;
		positions[2] = minXAtlas;					//izquierda-arriba
		positions[3] = minYAtlas;

		positions[4] = maxX;
		positions[5] = minY;					//derecha-arriba
		positions[6] = maxXAtlas;
		positions[7] = minYAtlas;

		positions[8] = maxX;
		positions[9] = maxY;					//derecha-abajo
		positions[10] = maxXAtlas;
		positions[11] = maxYAtlas;

		positions[12] = minX;
		positions[13] = maxY;					//izquierda-abajo
		positions[14] = minXAtlas;
		positions[15] = maxYAtlas;

		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;

		indices[3] = 2;
		indices[4] = 3;
		indices[5] = 0;

		height = maxY - minY;
		width = maxX - minX;
		UpdateBuffer();
	}
	glm::mat4 Shape::GetModel()
	{
		return model;
	}
	void Shape::UpdateBuffer()
	{
		m_VAO = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VertexBuffer, layout);

		m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);
	}
	void Shape::SetModel(glm::mat4 _model)
	{
		model = _model;
	}
	bool Shape::IsAnimationRunning() 
	{
		return animationactive;
	}
	void Shape::Animate(float MinYAtlas, float MaxYAtlas)
	{
		minYAtlas = MinYAtlas;
		maxYAtlas = MaxYAtlas;
		positions[3] = minYAtlas;
		positions[7] = minYAtlas;
		positions[15] = maxYAtlas;
		positions[11] = maxYAtlas;
		if (animation == NULL) {
			animation = new Animation(minXAtlas, minYAtlas, maxXAtlas, maxYAtlas);
		}
		if (animation->PlayAnimation(minXAtlas,maxXAtlas)) {
			positions[14] = minXAtlas;
			positions[2] = minXAtlas;
			positions[10] = maxXAtlas;
			positions[6] = maxXAtlas;
		}
		UpdateBuffer();
	}
	void Shape::Draw()
	{
		if (!animationactive) {
			m_Texture->Bind();
		}
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
		positions[14] = minXAtlas;
		positions[2] = minXAtlas;
		UpdateBuffer();
	}
	void Shape::SetMinYAtlas(float MinYAtlas)
	{
		minYAtlas = MinYAtlas;
		positions[3] = minYAtlas;
		positions[7] = minYAtlas;
		UpdateBuffer();
	}
	void Shape::SetMaxXAtlas(float MaxXAtlas)
	{
		maxXAtlas = MaxXAtlas;
		positions[10] = maxXAtlas;
		positions[6] = maxXAtlas;
		UpdateBuffer();
	}
	void Shape::SetMaxYAtlas(float MaxYAtlas)
	{
		maxYAtlas = MaxYAtlas;
		positions[15] = maxYAtlas;
		positions[11] = maxYAtlas;
		UpdateBuffer();
	}
	void Shape::SetTime(float Time)
	{
		time = Time;
	}
	void Shape::SetTexture(std::unique_ptr<Texture> m_Texture)
	{
	}
	void Shape::SetRigidBody(bool RigidBody)
	{
		rigidbody = RigidBody;
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
	float Shape::GetWidth()
	{
		return width;
	}
	float Shape::GetHeight()
	{
		return height;
	}
	bool Shape::GetRigidBody()
	{
		return rigidbody;
	}
}