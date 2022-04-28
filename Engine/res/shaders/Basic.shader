#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 TexCoords;

out vec2 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * position;
	v_TexCoord = TexCoords;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D TexCoords;

void main()
{
	vec4 texColor = texture(TexCoords, v_TexCoord);
	color = texColor;
};