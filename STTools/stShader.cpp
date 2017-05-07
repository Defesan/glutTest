#include "stShader.h"

STShaderManager::STShaderManager()
{
	//Initialize the shader manager
	//no need to set the entries in the table to 0, since it's a vector. But we will be loading the stock shaders in here...once we have some stock shaders.
}

STShaderManager::~STShaderManager()
{
	std::vector<GLuint>::iterator iter = this->activeShaderPointers.begin();
	for(; iter < this->activeShaderPointers.size(); iter++)
	{
		glDeleteProgram(*iter);
	}
}

void STShaderManager::runShader(GLuint shaderPointer)
{
	//Run the shader at shaderPointer

}

GLuint STShaderManager::loadShaderPair(std::string vertexShaderFile, std::string fragShaderFile)
{
	//GLuint programHandle = 0;
	//A utility to return the string representation of a file would be useful, but not today. STUtil is going to have to wait for another day.
	size_t fileSize;
	
	//Load the vertex shader into a string
	std::ifstream vertexFS(vertexShaderFile);
	
	vertexFS.seekg(0, vertexFS.end);
	fileSize = vertexFS.tellg();
	vertexFS.seekg(0, vertexFS.beg);
	
	std::string vertexShaderSrc(fileSize, ' ');
	vertexFS.read(&vertexShaderSrc[0], fileSize);
	
	//...and the fragment shader.
	std::ifstream fragmentFS(fragShaderFile);
	
	fragmentFS.seekg(0, fragmentFS.end);
	fileSize = fragmentFS.tellg();
	fragmentFS.seekg(0, fragmentFS.beg);
	
	std::string fragShaderSrc(fileSize, ' ');
	fragmentFS.read(&fragShaderSrc[0], fileSize);
	
	//And...well, we've actually now reached the initial condition of the loadShaderPairSrc function, so...
	
	return this->loadShaderPairSrc(vertexShaderSrc, fragShaderSrc);
}

GLuint STShaderManager::loadShaderPairSrc(std::string vertexShaderSrc, std::string fragShaderSrc)
{
	GLuint programHandle = 0;
	GLchar* stringPtr[1];
	GLint* lengthPtr[1];
	GLuint vertShaderHandle;
	GLuint fragShaderHandle;
	GLint fragTest;
	GLint vertTest;
	GLint progTest;
	
	//Create the shaders' handles
	vertShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	fragShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	
	//Load the vertex shader's attributes:
	stringPtr[0] = (GLchar*)vertexShaderSrc.c_str();
	lengthPtr[0] = (GLint)vertexShaderSrc.size();
	
	//Load in the source code.
	glShaderSource(vertShaderHandle, 1, (const GLchar**)stringPtr, (const GLint*)lengthPtr);
	
	//Load the fragment shader's attributes:
	stringPtr[0] = (GLchar*)fragShaderSrc.c_str();
	lengthPtr[0] = (GLint)fragShaderSrc.size();
	
	//Load in the other source code.
	glShaderSource(fragShaderHandle, 1, (const GLchar**)stringPtr, (const GLint*)lengthPtr);
	
	//Okay, so the code is loaded. Next step:compile it.
	glCompileShader(vertShaderHandle);
	glCompileShader(fragShaderHandle);
	
	//Check to make sure it compiled
	glGetShaderiv(vertShaderHandle, GL_COMPILE_STATUS, &vertTest);
	glGetShaderiv(fragShaderHandel, GL_COMPILE_STATUS, &fragTest);
	
	if(vertTest == GL_FALSE || fragTest == GL_FALSE)
	{
		//Compile failed
		std::cerr << "Shaders failed to compile." << std::endl;
		glDeleteShader(vertShaderHandle);
		glDeleteShader(fragShaderHandle);
		return SHADER_ERROR;	
	}
	//Looks like the comile was a success. Time to link.
	
	programHandle = glCreateProgram();
	glAttachShader(programHandle, vertShaderHandle);
	glAttachShader(programHandle, fragShaderHandle);
	glLinkProgram(programHandle);
	
	//One way or another, these are superfluous now.
	glDeleteShader(vertShaderHandle);
	glDeleteShader(fragShaderHandle);
	
	glGetProgramiv(programHandle, GL_LINK_STATUS, &progTest);
	if(progTest == GL_FALSE)
	{
		std::cerr << "Program link failed." << std::endl;
		glDeleteProgram(programHandle);
		return SHADER_ERROR	
	}
	
	//All is well.
	return programHandle;
}


GLuint STShaderManager::loadShaderPairWithAttributes(std::string vertexShaderFile, std::string fragShaderFile, ...)
{
	GLuint result = 0;
	
	return result;
}

GLuint STShaderManager::loadShaderPairSrcWithAttributes(std::string vertexShaderSrc, std::string fragShaderSrc, ...)
{
	GLuint result = 0;
	
	return result;
}
