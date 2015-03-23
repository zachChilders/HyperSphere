#pragma once
#include "..\Core\ContextInfo.h"
#include "FramebufferInfo.h"
#include "..\Core\WindowInfo.h"
#include <iostream>
#include "InitGlew.h"
#include "..\Managers\IListener.h"

namespace Core
{
	namespace Init
	{
		class InitGlut
		{
			public:

				static void init(const Core::WindowInfo& window,
								 const Core::ContextInfo& context,
								 const Core::FramebufferInfo& framebufferInfo);

			public:
				static void run();
				static void close();
				void enterFullScreen();
				void exitFullScreen();

				static void printOpenGLInfo(const Core::WindowInfo& windowInfo,
											const Core::ContextInfo& context);

			private:
				static Core::IListener* listener;
				static Core::WindowInfo windowInformation;

				static void idleCallback(void);
				static void displayCallback(void);
				static void reshapeCallback(int width, int height);
				static void closeCallback();

			public:
				static void setListener(Core::IListener*& iListener);

		};
	}
}


