#include "stUniform.h"

void STUniform::init()
{
	//Always initialize your variables, kids.
	this->count = 0;
	this->transpose = false;
	
	this->vf1 = 0.0f;
	this->vf2 = 0.0f;
	this->vf3 = 0.0f;
	this->vf4 = 0.0f;
	
	this->vi1 = 0;
	this->vi2 = 0;
	this->vi3 = 0;
	this->vi4 = 0;
	
	this->vui1 = 0;
	this->vui2 = 0;
	this->vui3 = 0;
	this->vui4 = 0;
	
	this->v2fv = nullptr;
	this->v3fv = nullptr;
	this->v4fv = nullptr;
	
	this->v2iv = nullptr;
	this->v3iv = nullptr;
	this->v4iv = nullptr;
	
	this->v2uiv = nullptr;
	this->v3uiv = nullptr;
	this->v4uiv = nullptr;
	
	this->m22f = nullptr;
	this->m23f = nullptr;
	this->m24f = nullptr;
	this->m32f = nullptr;
	this->m33f = nullptr;
	this->m34f = nullptr;
	this->m42f = nullptr;
	this->m43f = nullptr;
	this->m44f = nullptr;
}

STUniform::STUniform(GLint location, GLfloat vf1)
{
	this->init();
	this->type = ST_UNIFORM1F;
	this->location = location;	
	this->vf1 = vf1;
}

STUniform::STUniform(GLint location, GLfloat vf1, GLfloat vf2)
{
	this->init();
	this->type = ST_UNIFORM2F;
	this->location = location;	
	this->vf1 = vf1;
	this->vf2 = vf2;
}

STUniform::STUniform(GLint location, GLfloat vf1, GLfloat vf2, GLfloat vf3)
{
	this->init();
	this->type = ST_UNIFORM3F;
	this->location = location;	
	this->vf1 = vf1;
	this->vf2 = vf2;
	this->vf3 = vf3;
}

STUniform::STUniform(GLint location, GLfloat vf1, GLfloat vf2, GLfloat vf3, GLfloat vf4)
{
	this->init();
	this->type = ST_UNIFORM4F;
	this->location = location;	
	this->vf1 = vf1;
	this->vf2 = vf2;
	this->vf3 = vf3;
	this->vf4 = vf4;
}

//Int batches
STUniform::STUniform(GLint location, GLint vi1)
{
	this->init();
	this->type = ST_UNIFORM1I;
	this->location = location;	
	this->vi1 = vi1;
}

STUniform::STUniform(GLint location, GLint vi1, GLint vi2)
{
	this->init();
	this->type = ST_UNIFORM2I;
	this->location = location;	
	this->vi1 = vi1;
	this->vi2 = vi2;
}

STUniform::STUniform(GLint location, GLint vi1, GLint vi2, GLint vi3)
{
	this->init();
	this->type = ST_UNIFORM3I;
	this->location = location;	
	this->vi1 = vi1;
	this->vi2 = vi2;
	this->vi3 = vi3;
}

STUniform::STUniform(GLint location, GLint vi1, GLint vi2, GLint vi3, GLint vi4)
{
	this->init();
	this->type = ST_UNIFORM4I;
	this->location = location;	
	this->vi1 = vi1;
	this->vi2 = vi2;
	this->vi3 = vi3;
	this->vi4 = vi4;
}


//Unsigned int batches
STUniform::STUniform(GLint location, GLuint vui1)
{
	this->init();
	this->type = ST_UNIFORM1UI;
	this->location = location;	
	this->vui1 = vui1;
}

STUniform::STUniform(GLint location, GLuint vui1, GLuint vui2)
{
	this->init();
	this->type = ST_UNIFORM2UI;
	this->location = location;	
	this->vui1 = vui1;
	this->vui2 = vui2;
}

STUniform::STUniform(GLint location, GLuint vui1, GLuint vui2, GLuint vui3)
{
	this->init();
	this->type = ST_UNIFORM3UI;
	this->location = location;	
	this->vui1 = vui1;
	this->vui2 = vui2;
	this->vui3 = vui3;
}

STUniform::STUniform(GLint location, GLuint vui1, GLuint vui2, GLuint vui3, GLuint vui4)
{
	this->init();
	this->type = ST_UNIFORM4UI;
	this->location = location;	
	this->vui1 = vui1;
	this->vui2 = vui2;
	this->vui3 = vui3;
	this->vui4 = vui4;
}


//Float vectors -- these include counts.
STUniform::STUniform(GLint location, GLsizei count, GLfloat vf1)
{
	this->init();
	this->type = ST_UNIFORM1FV;
	this->location = location;
	if(count > 1)
	{
		count = 1;
	}
	this->count = count;
	this->vf1 = vf1;
}

STUniform::STUniform(GLint location, GLsizei count, STVec2f* v2fv)
{
	this->init();
	this->type = ST_UNIFORM2FV;
	this->location = location;
	if(count > 2)
	{
		count = 2;
	}
	this->count = count;
	this->v2fv = v2fv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec3f* v3fv)
{
	this->init();
	this->type = ST_UNIFORM3FV;
	this->location = location;
	if(count > 3)
	{
		count = 3;
	}
	this->count = count;
	this->v3fv = v3fv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec4f* v4fv)
{
	this->init();
	this->type = ST_UNIFORM4FV;
	this->location = location;
	if(count > 4)
	{
		count = 5;
	}
	this->count = count;
	this->v4fv = v4fv;
}


//Int vectors
STUniform::STUniform(GLint location, GLsizei count, GLint vi1)
{
	this->init();
	this->type = ST_UNIFORM1IV;
	this->location = location;
	if(count > 1)
	{
		count = 1;
	}
	this->count = count;
	this->vi1 = vi1;
}

STUniform::STUniform(GLint location, GLsizei count, STVec2i* v2iv)
{
	this->init();
	this->type = ST_UNIFORM2IV;
	this->location = location;
	if(count > 2)
	{
		count = 2;
	}
	this->count = count;
	this->v2iv = v2iv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec3i* v3iv)
{
	this->init();
	this->type = ST_UNIFORM3IV;
	this->location = location;
	if(count > 3)
	{
		count = 3;
	}
	this->count = count;
	this->v3iv = v3iv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec4i* v4iv)
{
	this->init();
	this->type = ST_UNIFORM4IV;
	this->location = location;
	if(count > 4)
	{
		count = 4;
	}
	this->count = count;
	this->v4iv = v4iv;
}

//Unsigned int vectors
STUniform::STUniform(GLint location, GLsizei count, GLuint vui1)
{
	this->init();
	this->type = ST_UNIFORM1UIV;
	this->location = location;
	if(count > 1)
	{
		count = 1;
	}
	this->count = count;
	this->vui1 = vui1;
}

STUniform::STUniform(GLint location, GLsizei count, STVec2ui* v2uiv)
{
	this->init();
	this->type = ST_UNIFORM2UIV;
	this->location = location;
	if(count > 2)
	{
		count = 2;
	}
	this->count = count;
	this->v2uiv = v2uiv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec3ui* v3uiv)
{
	this->init();
	this->type = ST_UNIFORM3UIV;
	this->location = location;
	if(count > 3)
	{
		count = 3;
	}
	this->count = count;
	this->v3uiv = v3uiv;
}

STUniform::STUniform(GLint location, GLsizei count, STVec4ui* v4uiv)
{
	this->init();
	this->type = ST_UNIFORM4UIV;
	this->location = location;
	if(count > 4)
	{
		count = 4;
	}
	this->count = count;
	this->v4uiv = v4uiv;
}

//Matrices
STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix22f* v22m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX2FV;
	this->location = location;
	if(count > 4)
	{
		count = 4;
	}
	this->count = count;
	this->transpose = transpose;
	this->v22m = v22m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix23f* v23m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX2X3FV;
	this->location = location;
	if(count > 6)
	{
		count = 6;
	}
	this->count = count;
	this->transpose = transpose;
	this->v23m = v23m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix24f* v24m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX2X4FV;
	this->location = location;
	if(count > 8)
	{
		count = 8;
	}
	this->count = count;
	this->transpose = transpose;
	this->v24m = v24m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix32f* v32m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX3X2FV;
	this->location = location;
	if(count > 6)
	{
		count = 6;
	}
	this->count = count;
	this->transpose = transpose;
	this->v32m = v32m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix33f* v33m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX3FV;
	this->location = location;
	if(count > 9)
	{
		count = 9;
	}
	this->count = count;
	this->transpose = transpose;
	this->v33m = v33m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix34f* v34m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX3X4FV;
	this->location = location;
	if(count > 12)
	{
		count = 12;
	}
	this->count = count;
	this->transpose = transpose;
	this->v34m = v34m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix42f* v42m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX4X2FV;
	this->location = location;
	if(count > 8)
	{
		count = 8;
	}
	this->count = count;
	this->transpose = transpose;
	this->v42m = v42m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix43f* v43m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX4X3FV;
	this->location = location;
	if(count > 12)
	{
		count = 12;
	}
	this->count = count;
	this->transpose = transpose;
	this->v43m = v43m;
}

STUniform::STUniform(GLint location, GLsizei count, GLboolean transpose, STMatrix44f* v44m)
{
	this->init();
	this->type = ST_UNIFORMMATRIX4FV;
	this->location = location;
	if(count > 16)
	{
		count = 16;
	}
	this->count = count;
	this->transpose = transpose;
	this->v44m = v44m;
}
