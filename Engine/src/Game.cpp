#include "Game.h"
Game::Game()
{
	CreateShape("../res/textures/xd1.png");
	CreateShape("../res/textures/xd2.png");
	Play(960, 540, "Test");
}
Game::~Game()
{
}
void Game::Update()
{
	int state = glfwGetKey(myWindow->get(), GLFW_KEY_D);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(0)->GetPos();
		nextPos.x += 1;
		UpdateShapePos(0, nextPos);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_A);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(0)->GetPos();
		nextPos.x -= 1;
		UpdateShapePos(0, nextPos);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_W);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(0)->GetPos();
		nextPos.y += 1;
		UpdateShapePos(0, nextPos);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_S);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(0)->GetPos();
		nextPos.y -= 1;
		UpdateShapePos(0, nextPos);
	}
}