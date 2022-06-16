#include "Game.h"
#include "Shape.h"
#include "Input.h"
#include "Sprite.h"
#include "CollisionManager.h"
#include "Model.h"
#include "Shader.h"
#include "Entity3D.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

Sprite* sq;
Sprite* spr;

Entity3D* ground;
Entity3D* barracks;
Entity3D* m;
Shader* shad;

DirectionalLight* directionalLight;
PointLight* pointLight;
SpotLight* spotLight;

list<Light*>* lightsList;

Entity3D* m2;

vec3 plpos = { 3.f,0.f,0.f };

bool Game::OnStart()
{
	render->setClearScreenColor(0.f, 0.5f, 0.7f,1.f);
	
	sq = new Sprite(render, 1, 1, 1);
	Material* sqmat = new Material();
	sqmat->LoadShaders("src/TextureVertexShader.txt", "src/TextureFragmentShader.txt");
	sq->SetMaterial(sqmat);
	sq->LoadMaterial("res/megaman.png", false);
	sq->SetPos(5.0f, 0.0f, -10.0f);

	spr = new Sprite(render,2,1,2);
	Material* sprmat = new Material();
	sprmat->LoadShaders("src/TextureVertexShader.txt", "src/TextureFragmentShader.txt");
	spr->SetMaterial(sprmat);
	spr->LoadMaterial("res/Diffuse.png",true);
	spr->SetPos(-10.0f, 0.0f, -10.0f);

	shad = new Shader("src/3DVertexShader.txt", "src/3DFragmentShader.txt");

	shad->setVec3("viewPosition", cam->GetCameraPosition());
	shad->setVec3("viewDirection", cam->GetCameraDirection());

	glm::vec3 dir = { 0.f, 0.f, -1.f };
	glm::vec3 ambient = { 0.1f, 0.1f, 0.1f };
	glm::vec3 diffuse = { 0.5f, 0.5f, 0.5f };
	glm::vec3 specular = { 0.5f,1.f,1.f };

	cam->SetCameraSpeed(2.5f);

	m = new Entity3D("res/Blade.obj");
	m->SetRot(vec3(-30.0f, 0, 0.0f));
	m->SetPos(vec3(0.0f, 0, 2.0f));
	ground = new Entity3D("res/ground.dae");
	//ground->SetScale({ 5,5,5 });
	ground->SetRot(vec3(30.0f, 0, 0.0f));
	ground->SetPos(vec3(0.0f, 0, -5.0f));
	//ground->SetScale(vec3(0.1f, 0.1f, 0.1f));
	lightsList = new list<Light*>();
	
	vec3 lightPos = { 0.f,0.f,0.f };

	directionalLight = new DirectionalLight(lightPos, dir, shad);
	pointLight = new PointLight(plpos, dir, shad);
	spotLight = new SpotLight(cam->GetCameraPosition(), cam->GetCameraDirection(), shad);
	
	lightsList->push_front(directionalLight);
	lightsList->push_front(pointLight);
	lightsList->push_front(spotLight);

	for(list<Light*>::iterator iB = lightsList->begin(); iB != lightsList->end(); ++iB)
	{
		(*iB)->SetAmbient(ambient);
		(*iB)->SetDiffuse(diffuse);
		(*iB)->SetSpecular(specular);
	}
	//m->SetScale({ 0.1f,0.1f,0.1f });
	return true;
}

vec2 prevPos;


float xPos = 0.0f;
float yRot = 0.0f;

float at = 1.0f;
bool ambientIntens =false;
bool pointsIntens = false;
bool spotIntens = false;
bool Game::OnUpdate()
{
	shad->setVec3("viewPosition", cam->GetCameraPosition());
	shad->setVec3("viewDirection", glm::normalize(cam->GetCameraDirection()));
	

	glm::vec3 objColor = { 1.0f,1.0f,1.0f };

	pointLight->SetAttenuation(at);
	
	pointLight->SetPosition(plpos);

	spotLight->SetPosition(cam->GetCameraPosition());
	spotLight->SetDirection(cam->GetCameraDirection());
	
	for (list<Light*>::iterator iB = lightsList->begin(); iB != lightsList->end(); ++iB)
	{
		(*iB)->Update();
	}
	
	shad->setVec3("objectColor", objColor);
	
	m->SetScale(vec3(1.0f, 1.0f, 1.0f));
	cam->UpdateCamera();
	
	//point directionalLight input
	if(Input::GetKeyPressed(GLFW_KEY_I))
	{
		plpos.z += BaseGame::GetDeltaTime() * 10.0f;
	}
	if (Input::GetKeyPressed(GLFW_KEY_K))
	{
		plpos.z -= BaseGame::GetDeltaTime() * 10.0f;
	}
	if (Input::GetKeyPressed(GLFW_KEY_J))
	{
		plpos.x -= BaseGame::GetDeltaTime() * 10.0f;
	}
	if (Input::GetKeyPressed(GLFW_KEY_L))
	{
		plpos.x += BaseGame::GetDeltaTime() * 10.0f;
	}
	if (Input::GetKeyPressed(GLFW_KEY_4))
	{
		at--;
	}
	if (Input::GetKeyPressed(GLFW_KEY_5))
	{
		at++;
	}
	if (Input::GetKeyPressed(GLFW_KEY_1))
	{
		if (ambientIntens) {
			pointLight->SetDiffuse({ 0.5f,0.5f,0.5f });
			ambientIntens = false;
		}
		else
		{
			pointLight->SetDiffuse({ 0.0f,0.0f,0.0f });
			ambientIntens = true;
		}
	}
	if (Input::GetKeyPressed(GLFW_KEY_F))
	{
		if (spotIntens) {
			spotIntens = false;
			spotLight->SetDiffuse({ 0.5f,0.5f,0.5f });
		}
		else
		{
			spotLight->SetDiffuse({ 0.0f,0.0f,0.0f});
			spotIntens = true;
		}
	}
	if (Input::GetKeyPressed(GLFW_KEY_3))
	{
		if (pointsIntens) {
			directionalLight->SetDiffuse({ 0.5f,0.5f,0.5f });
			pointsIntens = false;
		}
		else
		{
			directionalLight->SetDiffuse({ 0.0f,0.0f,0.0f });
			pointsIntens = true;
		}
	}
	
	//model translation
	if (Input::GetKeyPressed(GLFW_KEY_RIGHT))
	{
		/*if (!CollisionManager::CheckCollision(spr, sq))
		{
			prevPos = spr->GetPos();
			spr->Translate(0.01f, 0.0f, 0.0f);
		}
		else
			spr->SetPos(prevPos.x,prevPos.y, spr->GetPos().z);

		spr->UpdAnim(1);*/

		if (yRot < 0.0f)
			yRot = 0.0f;
		
		yRot = 10.0f * BaseGame::GetDeltaTime();
		m->SetRot(vec3(0.0f, yRot, 0.0f));
	}
	/*else
	{
		spr->UpdAnim(0);
	}*/
	if (Input::GetKeyPressed(GLFW_KEY_LEFT))
	{
		/*if (!CollisionManager::CheckCollision(spr, sq))
		{
			prevPos = spr->GetPos();
			spr->Translate(-0.01f, 0.0f, 0.0f);
		}
		else
			spr->SetPos(prevPos.x, prevPos.y, spr->GetPos().z);*/

		if(yRot>0.0f)
			yRot = 0.0f;
		
		yRot = -10.0f * BaseGame::GetDeltaTime();
		m->SetRot(vec3(0.0f, yRot, 0.0f));
	}

	
	/*if (Input::GetKeyPressed(GLFW_KEY_UP))
	{
		if (!CollisionManager::CheckCollision(spr, sq))
		{
			prevPos = spr->GetPos();
			spr->Translate(0.0f, 0.01f, 0.0f);

		}

		else
			spr->SetPos(prevPos.x, prevPos.y, spr->GetPos().z);
	}
	if (Input::GetKeyPressed(GLFW_KEY_DOWN))
	{
		if (!CollisionManager::CheckCollision(spr, sq))
		{
			prevPos = spr->GetPos();
			spr->Translate(0.0f, -0.01f, 0.0f);
		}
		else
			spr->SetPos(prevPos.x, prevPos.y, spr->GetPos().z);
	}*/
	
	if (Input::GetKeyPressed(GLFW_KEY_ESCAPE))
	{
		return false;
	}

	return true;
}

void Game::OnDraw()
{
	sq->Draw();
	spr->Draw();
	m->Draw(*shad);
	ground->Draw(*shad);
	//m2->Draw(*shad);
}

bool Game::OnStop()
{
	delete spr;
	delete sq;

	delete lightsList;

	delete m;
	delete m2;
	
	return true;
}