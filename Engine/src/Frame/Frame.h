#pragma once
#include <vector>
#include "glm.hpp"
class Frame {
private:
	glm::vec2 uv1;
	glm::vec2 uv2;
	glm::vec2 uv3;
	glm::vec2 uv4;
public:
	Frame(glm::vec2 & vec1, glm::vec2 & vec2, glm::vec2 & vec3, glm::vec2 & vec4);
};