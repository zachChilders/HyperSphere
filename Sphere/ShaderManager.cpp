#include "ShaderManager.h"

using namespace Managers;

std::map<std::string, GLuint> ShaderManager::programs;

std::string Managers::ShaderManager::ReadShader(const std::string& filename)
{
	std::string shaderCode;
	std::ifstream file(filename.c_str());

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}

GLuint Managers::ShaderManager::CreateShader(GLenum shaderType, const std::string& src, const std::string& shaderName)
{
	int compileResult = 0;

	GLuint shader = glCreateShader(shaderType);
	const char *shaderCodePtr = src.c_str();
	const int shaderCodeSize = src.size();
	glShaderSource(shader, 1, &shaderCodePtr, &shaderCodeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> shaderLog(infoLogLength);
		glGetShaderInfoLog(shader, infoLogLength, NULL, &shaderLog[0]);
		std::cout << "ERROR compiling shader: " << shaderName.c_str() << std::endl << &shaderLog[0] << std::endl;
		return 0;
	}
	return shader;

}

Managers::ShaderManager::ShaderManager(void)
{
}

Managers::ShaderManager::~ShaderManager(void)
{
	std::map<std::string, GLuint>::iterator it;
	for (it = programs.begin(); it != programs.end(); ++it)
	{
		GLuint pr = it->second;
		glDeleteProgram(pr);
	}
	programs.clear();

}

void Managers::ShaderManager::CreateProgram(const std::string& shaderName, const std::string& VertexShaderFilename, const std::string& FragmentShaderFilename)
{
	//read the shader files and save the code
	std::string vertex_shader_code = ReadShader(VertexShaderFilename);
	std::string fragment_shader_code = ReadShader(FragmentShaderFilename);

	GLuint vertex_shader = CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;
	//create the program handle, attatch the shaders and link it
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);
	//check for link errors
	if (link_result == GL_FALSE)
	{

		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader Loader : LINK ERROR" << std::endl << &program_log[0] << std::endl;
	}
	programs[shaderName] = program;
}

const GLuint Managers::ShaderManager::GetShader(const std::string & shaderName)
{
	return programs.at(shaderName);
}
