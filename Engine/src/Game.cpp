#include "Game.h"

const float cameraSpeed = 1.0f; // adjust accordingly
glm::vec3 pos = glm::vec3(0, 0, 0);

Game::Game(int Width, int Height) : base_game(Width, Height)
{
	Width = 960;
	Height = 540;
	speed = 0.1f;
	firstPersonCamera->UpdatePosition(glm::vec3(0, 0, 0));
	firstPersonCamera->UpdateRotation(glm::vec3(0, 90, 0), 40);
	int zPos = 100;
	Init(Width, Height, "Test");
	int index = 0;
	for (int i = -1000; i < 0; i += 50) {
		for (int j = -100; j < 500; j += 50) {
			CreateShape("../res/textures/wood.png", glm::vec3(i, j, 0), false);
			index++;
		}
	}
	for (int i = -1000; i < 0; i += 50) {
		for (int j = -100; j < 500; j += 50) {
			CreateShape("../res/textures/wood.png", glm::vec3(0, j, i), false);
			GetShapeByIndex(index)->SetRot(glm::vec3(0, 1, 0), glm::radians(90.0f));
			index++;
		}
	}
	for (int i = -1000; i < 0; i += 50) {
		for (int j = -1000; j < 0; j += 50) {
			CreateShape("../res/textures/wood.png", glm::vec3(i, -100, j), false);
			GetShapeByIndex(index)->SetRot(glm::vec3(90, 0, 0), glm::radians(90.0f));
			index++;
		}
	}
	//CreateShape("../res/textures/lechuck.png", glm::vec3(770, 200, -50), true);
	//GetShapeByIndex(1)->SetTime(0.3f);
	Play();
}
Game::~Game()
{
}
void Game::Update()
{
	for (int i=0;i<500;i++)
	{
		GetShapeByIndex(i)->SetRot(glm::vec3(90, 0, 0), glm::radians(glfwGetTime())*speed);
	}
	/*if (GetShapeByIndex(2)->GetPos().x < 500) {
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
	}*/
	speed = 0.01f;
	//GetShapeByIndex(0)->SetRot(glm::vec3(0.0f, 0.0f, 1.0f), (float)glfwGetTime()*speed);
	if (glfwGetKey(myWindow->get(), GLFW_KEY_W) == GLFW_PRESS)
		pos -= cameraSpeed * firstPersonCamera->GetFront();
	if (glfwGetKey(myWindow->get(), GLFW_KEY_S) == GLFW_PRESS)
		pos += cameraSpeed * firstPersonCamera->GetFront();
	if (glfwGetKey(myWindow->get(), GLFW_KEY_A) == GLFW_PRESS)
		pos += glm::normalize(glm::cross(firstPersonCamera->GetFront(), firstPersonCamera->GetUp())) * cameraSpeed;
	if (glfwGetKey(myWindow->get(), GLFW_KEY_D) == GLFW_PRESS)
		pos -= glm::normalize(glm::cross(firstPersonCamera->GetFront(), firstPersonCamera->GetUp())) * cameraSpeed;

	firstPersonCamera->UpdatePosition(pos);

	if (glfwGetKey(myWindow->get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		running = false;
}