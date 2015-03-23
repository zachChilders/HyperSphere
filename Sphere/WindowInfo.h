#pragma once
#include <string>

namespace Core
{
	struct WindowInfo
	{
		std::string name;
		int width, height;
		int positionX, positionY;
		bool isReshapable;

		WindowInfo()
		{
			name = "Sphere";
			width = 800;
			height = 600;
			positionX = 500;
			positionY = 250;
			isReshapable = true;
		}

		WindowInfo(std::string name,
				   int startPositionX, int startPositionY,
				   int width, int height,
				   bool isReshapable)
		{
			this->name = name;
			this->positionX = startPositionX;
			this->positionY = startPositionY;
			this->width = width;
			this->height = height;
			this->isReshapable = isReshapable;
		}

		//copy constructor
		WindowInfo(const WindowInfo& windowInfo)
		{
			name = windowInfo.name;
			positionX = windowInfo.positionX;
			positionY = windowInfo.positionY;
			width = windowInfo.width;
			height = windowInfo.height;
			isReshapable = windowInfo.isReshapable;
		}

		void operator=(const WindowInfo& windowInfo)
		{
			name = windowInfo.name;
			positionX = windowInfo.positionX;
			positionY = windowInfo.positionY;
			width = windowInfo.width;
			height = windowInfo.height;
			isReshapable = windowInfo.isReshapable;
		}

	};
}