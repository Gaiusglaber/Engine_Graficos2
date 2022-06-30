#include "Light.h"
#include "Shader.h"

Light::Light(vec3 initPos, vec3 initDir, Shader* shad)
{
	ambient = { 0.f,0.f,0.f };
	diffuse = { 0.5f,0.5f,0.5f };
	specular = { 1.f,1.f,1.f };
	color = { 1.f,1.f,1.f };
	SetPosition(initPos);
	SetDirection(initDir);
	SetShader(shad);
	isActive = true;
}

void Light::SetPosition(vec3 newPosition)
{
	position = newPosition;
}

void Light::SetDirection(vec3 newDirection)
{
	direction = newDirection;
}

void Light::SetShader(Shader* shad)
{
	activeShader = shad;
}

void Light::SetActive(bool active)
{
	isActive = active;
}

void Light::SetColor(vec3 color)
{
	this->color = color;
	activeShader->setVec3("objectColor",color);
}

vec3 Light::GetColor()
{
	return color;
}

void Light::SetSpecular(vec3 spec)
{
	specular = spec;
}

void Light::SetAmbient(vec3 amb)
{
	ambient = amb;
}

void Light::SetDiffuse(vec3 dif)
{
	diffuse = dif;
}

void Light::Update()
{
	
}
