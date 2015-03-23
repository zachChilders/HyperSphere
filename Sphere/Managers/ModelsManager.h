#pragma once
#include <map>
#include "ShaderManager.h"
#include "..\Rendering\IGameObject.h"
#include "..\Rendering\Triangle.h"
#include "..\Rendering\\Quad.h"

using namespace Rendering;
namespace Managers
{
	class ModelsManager
	{
		public:
			ModelsManager();
			~ModelsManager();

			void Draw();
			void Update();
			void DeleteModel(const std::string& gameModelName);
			const IGameObject& GetModel(const std::string& gameModelName);

		private:
			std::map<std::string, IGameObject*> gameModelList;

	};
}