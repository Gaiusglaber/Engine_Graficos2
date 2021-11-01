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
	public:
		glm::mat4 GetModel();
		void SetModel(glm::mat4 _model);
		void Draw();
		void SetPos(glm::vec3 pos);
		void SetRot(glm::vec3 rot);
		void SetScale(glm::vec3 scale);
	};
}