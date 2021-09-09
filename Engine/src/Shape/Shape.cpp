#include "Shape.h"

void Shape::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
