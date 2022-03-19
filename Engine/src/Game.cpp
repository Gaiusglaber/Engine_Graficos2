#include "Game.h"
Game::Game(int Width, int Height) : base_game(Width, Height)
{
	Width = 960;
	Height = 540;
	camera->UpdatePosition(glm::vec3(-300, -100, -800));
	camera->UpdateRotation(glm::vec3(0, 90, 0));
	int zPos = 100;
	Init(Width, Height, "Test");
	CreateShape("../res/textures/background.png", glm::vec3(Width / 2, Height / 2, 0), false);
	CreateShape("../res/textures/guybush.png", glm::vec3(0, Height / 2, 0), 3, 6, 14, true);
	CreateShape("../res/textures/lechuck.png", glm::vec3(770, 200, 0), true);
	CreateShape("../res/textures/murray.png", glm::vec3(200, 300, 0), false);
	
	GetShapeByIndex(0)->SetScale(glm::vec3(9.6f, 5.4f, 1));
	GetShapeByIndex(1)->SetTime(0.3f);
	Play();
}
Game::~Game()
{
}
void Game::Update()
{
	if (GetShapeByIndex(2)->GetPos().x < 500) {
		turn = true;
	}
	else if (GetShapeByIndex(2)->GetPos().x > 770) {
		turn = false;
	}
	if (turn) {
		glm::vec3 nextPos = GetShapeByIndex(2)->GetPos();
		nextPos.x += 1;
		UpdateShapePos(2, nextPos);
	}
	else {
		glm::vec3 nextPos = GetShapeByIndex(2)->GetPos();
		nextPos.x -= 1;
		UpdateShapePos(2, nextPos);
	}
	int state = glfwGetKey(myWindow->get(), GLFW_KEY_D);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.x += 1;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(0,5);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_A);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.x -= 1;
		UpdateShapePos(1, nextPos);
		GetShapeByIndex(1)->Animate(1,5);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_W);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.y += 1;
		UpdateShapePos(1, nextPos);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_S);
	if (state == GLFW_PRESS)
	{
		glm::vec3 nextPos = GetShapeByIndex(1)->GetPos();
		nextPos.y -= 1;
		UpdateShapePos(1, nextPos);
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_ESCAPE);
	if (state == GLFW_PRESS)
	{
		running = false;
	}
}