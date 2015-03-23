
#include "GL\glew.h"
#include "GL\freeglut.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "ShaderManager.h"
#include "GameModels.h"
#include "InitGlut.h"

using namespace std;

using namespace Core;
using namespace Init;

Models::GameModels* gameModels;
Managers::ShaderManager* sl;
GLuint program;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.5, 0.5, 0.0);

	glBindVertexArray(gameModels->GetModel("triangle1"));
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

void closeCallback()
{
	cout << "GLUT: \t Finished" << endl;
	glutLeaveMainLoop();
}

void Init()
{
	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	sl = new Managers::ShaderManager();
	sl->CreateProgram("colorShader", "Shaders\\VertexShader.glsl", "Shaders\\FragmentShader.glsl");
	program = sl->GetShader("colorShader");
}

int main(int argc, char **argv)
{
	WindowInfo window(std::string("Sphere"),
					  500, 250,
					  800, 600,
					  true);

	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	InitGlut::init(window, context, frameBufferInfo);

	InitGlut::run();

	return 0;
}