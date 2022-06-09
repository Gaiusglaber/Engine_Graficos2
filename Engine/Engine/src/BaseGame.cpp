#include "BaseGame.h"
#include "Input.h"


double BaseGame::currentFrame = 0.0f;
double BaseGame::lastFrame = 0.0f;
double BaseGame::deltaTime = 0.0f;

BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {
}
bool BaseGame::Start(int h, int w, char* name) {
	cout << "GameBase::Start()" << endl;

	window = new Window();
	if (!window->Start(w, h, name))
		return false;
	 
	render = new Renderer();
	if (!render->Start(window))
		return false;
	render->setClearScreenColor(1.0f, 0.0f, 1.0f, 0.0f);
	render->ClearScreen();

	Input::SetWindow(window);

	cam = render->GetCam();

	glfwSetInputMode(window->GetGLFWWindowPtr(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	lastFrame = 0.0f;

	return OnStart();
}

void BaseGame::Loop() {
	loop = true;
	while (loop && !window->ShouldClose()) {
		//------------------------------
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		//------------------------------
		loop = OnUpdate();
		render->ClearScreen();
		OnDraw();
		render->SwapBuffer();
		window->PollEvents();
	}
}

float BaseGame::GetDeltaTime() {

	return deltaTime;
}

bool BaseGame::Stop() {
	cout << "GameBase::Stop()" << endl;
	OnStop();
	render->Stop();
	window->Stop();

	delete render;
	delete window;
	return true;
}


