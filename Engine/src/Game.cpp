#include "Game.h"
Game::Game()
{
	Init(960, 540, "Test");
	CreateShape("../res/textures/guybush.png",glm::vec3(0,0,0),0,0.16667f,0.32f,0.64,true);
	CreateShape("../res/textures/xd2.png", glm::vec3(250, 250, 0),true);
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
		GetShapeByIndex(0)->Animate(0.68f, 1);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_A);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(0)->GetPos();
		nextPos.x -= 1;
		UpdateShapePos(0, nextPos);
		GetShapeByIndex(0)->Animate(0.35f, 0.67f);
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