#pragma once

#include "ShaderManager.h"
#include "IListener.h"

namespace Managers
{
	class SceneManager : public Core::IListener
	{
		public:
			SceneManager();
			~SceneManager();

			virtual void notifyBeginFrame();
			virtual void notifyDisplayFrame();
			virtual void notifyEndFrame();
			virtual void notifyReshape(int width,
									   int height,
									   int previousWidth,
									   int previousHeight);

		private:
			ShaderManager* shaderManager;
	};
}

