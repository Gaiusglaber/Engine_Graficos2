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
#include "Frustum.h"

Sprite* sq;
Sprite* spr;
Shader* shad;

DirectionalLight* directionalLight;
PointLight* pointLight;
SpotLight* spotLight;

list<Light*>* lightsList;
list<Light*>* lightsToShowList;

vec3 arthaspos = { 0.f,0.f,0.f };
vec3 sylvanaspos = { 0.f,0.f,0.f };
vec3 crownpos = { 0.f,0.f,0.f };



bool Game::OnStart()
{	
	render->setClearScreenColor(0.39f, 0.39f, 1.0f,0.07f);
	
	shad = new Shader("src/3DVertexShader.txt", "src/3DFragmentShader.txt");

	shad->setVec3("viewPosition", cam->GetCameraPosition());
	shad->setVec3("viewDirection", cam->GetCameraDirection());

	glm::vec3 dir = { 0.f, 0.f, -1.f };
	glm::vec3 ambient = { 0.1f, 0.1f, 0.1f };
	glm::vec3 diffuse = { 0.5f, 0.5f, 0.5f };
	glm::vec3 specular = { 1.f,1.f,1.f };

	cam->SetCameraSpeed(2.5f);
	
	arthas = new Model("res/arthas.obj",false);

	bolvar_chained = new Model("res/bolvarchained.obj",false);

	helm = new Model("res/helm.obj",false);

	building_0 = new Model("res/ground.obj", false);

	building_1 = new Model("res/spikes.obj", false);

	building_2 = new Model("res/spikes_fortress.obj", false);

	building_3 = new Model("res/spikes_fortress.obj", false);

	sylvanas = new Model("res/sylvanas.obj", false);

	arthas->SetPos(vec3(0.f, 0.f, -15.f));

	sylvanas->SetPos(vec3(0.f, 0.f, -12.f));

	bolvar_chained->SetPos(vec3(-5.0f, 0.f, -15.f));

	helm->SetScale(vec3(0.7f, 0.7f, 0.7f));
	helm->SetPos(vec3(0.f, 2.5f, -21.4f));
	crownpos = helm->GetPos();

	building_0->SetScale(vec3(0.3f, 0.3f, 0.3f));
	building_0->SetPos(vec3(0.f, 0.f, -45.f));

	building_1->SetPos(vec3(-15.f, 0.f, -10.f));

	building_2->SetRot(70, vec3(0.0f, 1.0f, 0.0f));
	building_2->SetPos(vec3(2.0f, 0.0f, 0.0f));

	building_3->SetPos(vec3(-10.0f, 0.0f, -25.0f));
	building_3->SetRot(-70, vec3(0.0f, 1.0f, 0.0f));

	lightsList = new list<Light*>();
	
	vec3 lightPos = { 0.f,0.f,-15.f };

	directionalLight = new DirectionalLight(lightPos, dir, shad, true);
	pointLight = new PointLight(vec3(0.0f,0.0f,0.0f), dir, shad, true);
	spotLight = new SpotLight(cam->GetCameraPosition(), cam->GetCameraDirection(), shad, false);

	shad->setInt("lightsAmount", PointLight::GetPointLightCount());
	
	lightsList->push_front(directionalLight);
	lightsList->push_front(pointLight);
	lightsList->push_front(spotLight);

	for(list<Light*>::iterator iB = lightsList->begin(); iB != lightsList->end(); ++iB)
	{
		(*iB)->SetAmbient(ambient);
		(*iB)->SetDiffuse(diffuse);
		(*iB)->SetSpecular(specular);
	}
	
	return true;
}

vec2 prevPos;

float pos = 0.0f;

float at = 1.0f;

float speed = 0.03f;

vec3 newscale = { 1.f,1.f,1.f };
float gameDeltaTime = 0;

bool Game::OnUpdate()
{
	shad->use();
	shad->setVec3("viewPosition", cam->GetCameraPosition());
	shad->setVec3("viewDirection", glm::normalize(cam->GetCameraDirection()));
	
	gameDeltaTime += BaseGame::GetDeltaTime();
	glm::vec3 objColor = {1.0f,1.0f,1.0f};

	pointLight->SetAttenuation(at);
	
	//m->SetPos(plpos);

	spotLight->SetPosition(cam->GetCameraPosition());
	spotLight->SetDirection(cam->GetCameraDirection());

	shad->use();
	shad->setInt("lightsAmount", PointLight::GetPointLightCount());
	shad->setVec3("objectColor", objColor);

	pointLight->SetDiffuse(vec3(1.f, 0.f, 0.f));

	for (list<Light*>::iterator iB = lightsList->begin(); iB != lightsList->end(); ++iB)
	{
		(*iB)->Update();
	}
	
	cam->UpdateCamera();
	
	if(Input::GetKeyPressed(GLFW_KEY_I))
	{
		pos = 10.0f * BaseGame::GetDeltaTime();
		arthas->SetPos(vec3(0.f, 0.f, pos));
	}
	if (Input::GetKeyPressed(GLFW_KEY_K))
	{
		pos = -10.0f * BaseGame::GetDeltaTime();
		arthas->SetPos(vec3(0.f, 0.f, pos));
	}
	if (Input::GetKeyPressed(GLFW_KEY_L))
	{
		pos = 10.0f * BaseGame::GetDeltaTime();
		arthas->SetPos(vec3(pos, 0.f, 0.f));
	}
	if (Input::GetKeyPressed(GLFW_KEY_J))
	{
		pos = -10.0f * BaseGame::GetDeltaTime();
		arthas->SetPos(vec3(pos, 0.f, 0.f));
	}


	if (Input::GetKeyPressed(GLFW_KEY_T))
	{
		pos = 10.0f * BaseGame::GetDeltaTime();
		sylvanas->SetPos(vec3(0.f, 0.f, pos));
	}
	if (Input::GetKeyPressed(GLFW_KEY_G))
	{
		pos = -10.0f * BaseGame::GetDeltaTime();
		sylvanas->SetPos(vec3(0.f, 0.f, pos));
	}
	if (Input::GetKeyPressed(GLFW_KEY_F))
	{
		pos = 10.0f * BaseGame::GetDeltaTime();
		sylvanas->SetPos(vec3(pos, 0.f, 0.f));
	}
	if (Input::GetKeyPressed(GLFW_KEY_H))
	{
		pos = 10.0f * BaseGame::GetDeltaTime();
		sylvanas->SetPos(vec3(pos, 0.f, 0.f));
	}

	if (Input::GetKeyPressedOnce(GLFW_KEY_Q)) 
	{
		if (arthas->GetChild(helm->GetName())==nullptr) 
		{
			helm->SetParent(arthas);
		}
		else
		{
			helm->SetParent(BaseGame::GetRootEntity());
		}
	}

	if (Input::GetKeyPressedOnce(GLFW_KEY_E))
	{
		if (sylvanas->GetChild(helm->GetName())==nullptr)
		{
			helm->SetParent(sylvanas);
		}
		else
		{
			helm->SetParent(BaseGame::GetRootEntity());
		}
	}


	if (Input::GetKeyPressed(GLFW_KEY_ESCAPE))
	{
		return false;
	}

	return true;
}

void Game::OnDraw()
{
	render->CheckPlanes();
	render->CheckFrustumCulling(BaseGame::GetRootEntity());
	BaseGame::GetRootEntity()->Draw(*shad);
}

bool Game::OnStop()
{
	delete spr;
	delete sq;

	delete lightsList;
	
	return true;
}