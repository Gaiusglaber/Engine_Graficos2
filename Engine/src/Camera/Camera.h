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
		view = glm::translate(glm::mat4(1.0f), Position);
	}
	void UpdateRotation(glm::vec3 rotation) {
		view = glm::rotate(view, 20.0f, rotation);
	}
	void SetFront(glm::vec3 front) {
		cameraFront = front;
	}
	glm::vec3 GetFront() {
		return cameraFront;
	}
};