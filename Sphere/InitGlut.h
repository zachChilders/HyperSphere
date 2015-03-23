#pragma once
#include "ContextInfo.h"
#include "FramebufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "InitGlew.h"
#include "IListener.h"

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

				static void run();
				static void close();

				void enterFullScreen();
				void exitFullScreen();

				static void printOpenGLInfo(const Core::WindowInfo& windowInfo,
											const Core::ContextInfo& context);

				static void setListener(IListener*& iListener);

			private:
				static IListener* listener;
				static WindowInfo windowInformation;

				static void idleCallback(void);
				static void displayCallback(void);
				static void reshapeCallback(int width, int height);
				static void closeCallback();

		};
	}
}


