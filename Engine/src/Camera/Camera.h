#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Camera
{
private:

public:
	Camera(glm::vec3 Position, glm::mat4 Perspective, glm::mat4 View);
	glm::mat4 perspective;
	glm::mat4 view;
	glm::vec3 cameraFront;
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec4 rotation = glm::vec4(1, 0, 0, 0);
	void UpdatePosition(glm::vec3 Position) {
		view = glm::translate(view, Position);
	}
	void UpdateRotation(glm::vec3 rotation,float angle) {
		view = glm::rotate(view, glm::radians(angle), rotation);
	}
	void SetFront(glm::vec3 front) {
		cameraFront = front;
		view = glm::lookAt(position, front + position, glm::vec3(0, 1, 0));
	}
	glm::vec3 GetFront() {
		return cameraFront;
	}
};