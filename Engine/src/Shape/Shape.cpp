#include <GL/glew.h>
#include "Shape.h"
void Shape::draw()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}