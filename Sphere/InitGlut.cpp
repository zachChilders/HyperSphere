#include "InitGlut.h"

using namespace Core::Init;

void InitGlut::init(const Core::WindowInfo& windowInfo,
					const Core::ContextInfo& contextInfo,
					const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char *fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	windowInformation = windowInfo;

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}

	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.positionX, windowInfo.positionY);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;

	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	Init::InitGlew::Init();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	printOpenGLInfo(windowInfo, contextInfo);

}

void InitGlut::run()
{
	std::cout << "GLUT:\tStart Running " << std::endl;
	glutMainLoop();
}

void InitGlut::close()
{
	std::cout << "GLUT:\tFinished" << std::endl;
	glutLeaveMainLoop();
}

void Core::Init::InitGlut::idleCallback(void)
{
	glutPostRedisplay();
}

void Core::Init::InitGlut::displayCallback(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();
}

void Core::Init::InitGlut::reshapeCallback(int width, int height)
{
}

void Core::Init::InitGlut::closeCallback()
{
	close();
}

void Core::Init::InitGlut::enterFullScreen()
{
	glutFullScreen();
}

void Core::Init::InitGlut::exitFullScreen()
{
	glutLeaveFullScreen();
}

void Core::Init::InitGlut::printOpenGLInfo(const Core::WindowInfo & windowInfo, const Core::ContextInfo & context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "\n************************\n************************" << std::endl;
	std::cout << "GLUT:\tInitialise" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;

}
