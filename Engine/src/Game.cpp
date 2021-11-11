#include "Game.h"
Game::Game()
{
	Init(960, 540, "Test");
	CreateShape("../res/textures/xd1.png");
	CreateShape("../res/textures/xd2.png", -75, -50, 50, 75);
	Play();
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
	GetCollisionManager()->CheckCollisions();
}