#version 450 core

layout(location = 0) in vec4 inPosition;
layout(location = 1) in vec4 inColor;

out vec4 color;

void main(void)
{
	color = inColor;
	gl_Position = inPosition;
}