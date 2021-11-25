#include "Game.h"
Game::Game()
{
	int width = 960;
	int height = 540;
	Init(width, height, "Test");
	CreateShape("../res/textures/background.png", glm::vec3(width / 2, height / 2, 0), false);
	CreateShape("../res/textures/guybush.png",glm::vec3(0,0,0),0,0.16667f,0.32f,0.64,true);
	//CreateShape("../res/textures/xd2.png", glm::vec3(250, 250, 0),true);
	GetShapeByIndex(0)->SetScale(glm::vec3(9.6f, 5.4f, 1));
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
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.x += 10;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(0.68f, 1);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_A);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.x -= 10;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(0.35f, 0.66f);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_W);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.y += 10;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(0.68f, 1);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_S);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.y -= 10;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(0.35f, 0.66f);
	}
}