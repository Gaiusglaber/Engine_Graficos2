#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DLLEXPORT DirectionalLight : public Light
{
private:
	float att;
public:
	DirectionalLight(vec3 initPos, vec3 initDir, Shader* shad);
	void Update() override;
	void SetAtt(float Att);
};

#endif
