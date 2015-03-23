
#include "GL\glew.h"
#include "GL\freeglut.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "Managers\ShaderManager.h"
#include "Core\InitGlut.h"
#include "Managers\SceneManager.h"

using namespace std;

using namespace Core;
using namespace Init;

Managers::ShaderManager* sl;
GLuint program;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("Sphere"),
					  500, 250,
					  800, 600,
					  true);

	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	InitGlut::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::SceneManager();
	Init::InitGlut::setListener(scene);

	InitGlut::run();
	
	delete scene;
	return 0;
}