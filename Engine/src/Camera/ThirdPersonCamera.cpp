#include "ThirdPersonCamera.h"

namespace Engine
{
	void ThirdPersonCamera::UpdatePosition(glm::vec3 Position) {
		view = glm::translate(view, Position);
	}
	void ThirdPersonCamera::UpdateRotation(glm::vec3 rotation, float angle) {
		view = glm::rotate(view, glm::radians(angle), rotation);
	}
	void ThirdPersonCamera::SetFront(glm::vec3 front) {
		cameraFront = front;
		view = glm::lookAt(position, front + position, up);
	}
}