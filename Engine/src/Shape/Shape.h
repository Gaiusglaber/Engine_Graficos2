#ifndef SHAPE_H
#define SHAPE_H
#include  "../Entity/Entity.h"
#include "glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
class Shape : IEntity {
private:
	glm::mat4 model = glm::mat4(1.0f);
public:
	glm::mat4 getModel();
	void setModel(glm::mat4 _model);
	void draw();
	void setPos(glm::vec3 pos);
	void setRot(glm::vec3 rot);
	void setScale(glm::vec3 scale);

};
#endif // !SHAPE_H

