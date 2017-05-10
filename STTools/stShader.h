#ifndef __ST_SHADER_H__
#define __ST_SHADER_H__

#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>
#include <string>
#include <fstream>

#include "stUtil.h"

#define SHADER_ERROR 0

enum ST_SHADER_ATTRIBUTE {ST_ATTRIBUTE_VERTEX = 0, ST_ATTRIBUTE_COLOR, ST_ATTRIBUTE_NORMAL, ST_ATTRIBUTE_TEXTURE0, 
                          ST_ATTRIBUTE_TEXTURE1, ST_ATTRIBUTE_TEXTURE2, ST_ATTRIBUTE_TEXTURE3, ST_ATTRIBUTE_LAST};


enum ST_UNIFORM_TYPE {ST_UNIFORM1F = 0, ST_UNIFORM2F, ST_UNIFORM3F, ST_UNIFORM4F, ST_UNIFORM1I, ST_UNIFORM2I, ST_UNIFORM3I, ST_UNIFORM4I,
                      ST_UNIFORM1UI, ST_UNIFORM2UI, ST_UNIFORM3UI, ST_UNIFORM4UI, ST_UNIFORM1FV, ST_UNIFORM2FV, ST_UNIFORM3FV, ST_UNIFORM4FV,
                      ST_UNIFORM1IV, ST_UNIFORM2IV, ST_UNIFORM3IV, ST_UNIFORM4IV, ST_UNIFORM1UIV, ST_UNIFORM2UIV, ST_UNIFORM3UIV, ST_UNIFORM4UIV,
                      ST_UNIFORMMATRIX2FV, ST_UNIFORMMATRIX3FV, ST_UNIFORMMATRIX4FV, ST_UNIFORMMATRIX2X3V, ST_UNIFORMMATRIX3X2FV, ST_UNIFORMMATRIX2X4FV,
                      ST_UNIFORMMATRIX3X4FV, ST_UNIFORMMATRIX4X3FV}

enum ST_STOCK_SHADER {ST_IDENTITY = 0};	//Yeah, just this one for now.

class STShaderManager
{
private:
	//What do I need in here? a vector of the 'names' of the shaders...
	std::vector<GLuint> activeShaderPointers;
	
	//Okay, so I've decided on a 'set uniform' private function. It's going to take a pointer to the data it needs, the type of data,
	//the name of the uniform, the number of elements in the array. Really starting to think a uniform *class* might also be in order.
	void setUniform

public:
	STShaderManager();		//I think we can safely initialize the full shader library(which will be fairly small to start, but I'll keep adding to it) in the constructor.
	~STShaderManager();
	
	GLuint getShader(GLuint index) {return this->activeShaderPointers[index];};
	GLuint getStockShader(ST_STOCK_SHADER shader) : getShader((GLuint)shader) {};	//All of the custom shaders will be added AFTER the stock shaders, so the stock shader indices are valid.
	
	void runShader(GLuint shaderPointer, ...);
	
	bool loadShaderSrc(std::string shaderSoource, GLuint shaderHandle);
	
	//Continuing my STL translation of the old code, we'll be using strings, not c-strings. Pretty much standard(and often best) practice in C++ now.
	//Successfully reduced loadShaderPair to a single in-header return.
	GLuint loadShaderPair(std::string vertexShaderFile, std::string fragShaderFile) {return this->loadShaderPairSrc(fileToString(vertexShaderFile), fileToString(fragShaderFile));};
	GLuint loadShaderPairSrc(std::string vertexShaderSrc, std::string fragShaderSrc);
	
	GLuint loadShaderPairWithAttributes(std::string vertexShaderFile, std::string fragShaderFile, ...);
	GLuint loadShaderPairSrcWithAttributes(std::string vertexShaderSrc, std::string fragShaderSrc, ...);
};


#endif //__ST_SHADER_H__
