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
	GLuint result = 0;
	
	return result;
}

GLuint STShaderManager::loadShaderPairSrc(std::string vertexShaderSrc, std::string fragShaderSrc)
{
	GLuint programHandle = 0;
	//Goal for 5-5-17.
	//So what do I need to do to load a shader pair?
	//I have strings(which I can get c-strings from) of the source code for both shaders.
	//This should be the simplest -- and probably least(if ever) used -- of the functions, but it'll serve as a basis.
	
	//So...this is awkward. Not because I messed up, it's just that...following RSW's source code, I've made all my plans
	//with *single string* sources in mind. TBH, I can *barely* see the usefulness of multi-stringing it, mostly because that
	//kind of thing is so far ahead of where I'm at it's just barely visible. If you wanted to make a *run-time modifiable*
	//shader, that would be the way to go, with each instruction being its own string. There might be other reasons, but
	//I'm not aware of them.
	
	//In any case, it'll be getting one big honking string with the whole shader file, but it's expecting:
	//1)an array of c-strings
	//2)the number of strings in the array
	//3)another array with the lengths of the strings in the array.
	//And with just one string, I have to create a new GLchar pointer -- an array with ONE element -- and if I want to specify
	//a length, I also have to create a size 1 array of GLint(s?) and pass that along as well. So...WTF, I might as well.
	
	//Guess you don't really have to malloc these...
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
