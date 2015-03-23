#include "InitGlew.h"

using namespace Core;
using namespace Core::Init;

void Core::Init::InitGlew::Init()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: Initialized" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << "GLEW version is 4.5\n ";
	}
	else
	{
		std::cout << " GLEW 4.5 not supported\n ";
	}

}
