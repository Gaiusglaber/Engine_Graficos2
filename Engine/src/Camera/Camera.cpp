#include "Camera.h"

Camera::Camera(glm::vec3 Position, glm::mat4 Perspective, glm::mat4 View)
{
	perspective = Perspective;
	view = View;
	position = Position;
}

