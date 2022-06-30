#include "DirectionalLight.h"

#include "Shader.h"

DirectionalLight::DirectionalLight(vec3 initPos, vec3 initDir, Shader* shad) : Light(initPos, initDir, shad)
{
	
}


void DirectionalLight::Update()
{
	if (isActive) {
		activeShader->setVec3("lightAmbient", ambient);
		activeShader->setVec3("lightDiffuse", diffuse);
		activeShader->setVec3("lightSpecular", specular);
	}
	else
	{
		activeShader->setVec3("lightAmbient", { 0.f,0.f,0.f });
		activeShader->setVec3("lightDiffuse", { 0.f,0.f,0.f });
		activeShader->setVec3("lightSpecular", { 0.f,0.f,0.f });
	}
}
