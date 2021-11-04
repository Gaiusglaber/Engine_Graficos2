#include "Game.h"
Game::Game()
{
	CreateShape("../res/textures/xd.png");
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
		m_TranslationA.x += 1;
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_A);
	if (state == GLFW_PRESS)
	{
		m_TranslationA.x -= 1;
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_W);
	if (state == GLFW_PRESS)
	{
		m_TranslationA.y += 1;
	}
	state = glfwGetKey(myWindow->get(), GLFW_KEY_S);
	if (state == GLFW_PRESS)
	{
		m_TranslationA.y -= 1;
	}
}