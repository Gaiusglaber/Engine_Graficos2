#pragma once
#include "Entity/Entity.h"
#include "glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
namespace Engine
{
	class ENGINE_API Shape : IEntity {
	private:
		glm::mat4 model = glm::mat4(1.0f);
		glm::vec3 m_translation;
		glm::vec4 m_rotation;
		glm::vec3 m_scale;
		float maxXAtlas = 0;
		float maxYAtlas = 0;
		float minXAtlas = 0;
		float minYAtlas = 0;
	public:
		glm::mat4 GetModel();
		void SetModel(glm::mat4 _model);
		void SetPos(glm::vec3 m_Translation);
		void Draw();
		void SetPos(glm::vec3 pos);
		void SetRot(glm::vec3 rot);
		void SetScale(glm::vec3 scale);
		void SetMinXAtlas(float MinXAtlas);
		void SetMinYAtlas(float MinYAtlas);
		void SetMaxXAtlas(float MaxXAtlas);
		void SetMaxYAtlas(float MaxYAtlas);
	};
}