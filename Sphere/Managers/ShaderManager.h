#pragma once

#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

namespace Managers
{
	class ShaderManager
	{
		private:
			std::string ReadShader(const std::string& fname);
			GLuint CreateShader(GLenum shaderType, const std::string& src, const std::string& shaderName);

			static std::map<std::string, GLuint> programs;

		public:
			ShaderManager(void);
			~ShaderManager(void);
			void CreateProgram(const std::string& shaderName, const std::string& VertexShaderFileName, const std::string& FragmentShaderFilename);

			static const GLuint GetShader(const std::string& shaderName);

	};
}