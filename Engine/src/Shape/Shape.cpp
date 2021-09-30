#include <GL/glew.h>
#include "Shape.h"
glm::mat4 Shape::getModel()
{
	return model;
}
void Shape::setModel(glm::mat4 _model)
{
	model = _model;
}
void Shape::draw()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Shape::setPos(glm::vec3 pos)
{
	model = glm::translate(model, pos);
}
void Shape::setRot(glm::vec3 rot)
{
	model = glm::rotate(model, (float)glfwGetTime(), rot);
}
void Shape::setScale(glm::vec3 scale)
{
	model = glm::scale(model, scale);
}
