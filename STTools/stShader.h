#ifndef __ST_SHADER_H__
#define __ST_SHADER_H__

//I still haven't figured out why I'm using the 'st' prefix. Reference to my middle name, Stephan? And yes, BTW, that's how the nurse who wrote it down spelled it.
//(Still haven't gotten over that)

class STShaderManager
{
	/*So what's needed in a shader manager?
	  Well, it needs to take strings, which contain the shader 'programs' for a fragment shader and a vertex shader.
	  It should store those strings, to be honest, but building a library of shaders seems to be the one thing Richard S. Wright never figured out.
	  Or, possibly, from certain readings of the code, something a student didn't properly work out before code lock. So..there's a goal.
	  Keeping a 'standard shader library' is also handy, as they demonstrate.
	  Of course, loading a custom shader with variables means using varargs(varrrrgh), so that'll be fun. Necessary, and a good learning experience, but...
	  Can't say I ever *trusted* varargs. Way too much leeway to shoot oneself in the foot, damn their usefulness.
	  
	  So the GLTools version has a basic stock shader pipeline that goes something like this:
	  1)Initialize the stock shaders. This uses the included shader loading function to load 'pointers' (read GLuints) into an array. I suppose it's actually not that much data.
	  2)Get a stock shader. Pass in the enum value for the stock shader tou want, and it'll give you the pointer for the fragment-vertex shader pair.
	  3)Use the stock shader. This loads all the necessary data in, and runs the shader.
	  
	  There are also some support methods(some already mentioned).
	  1)Non-attribute-enabled 'loadShaderPair' and 'loadShaderPairSrc' methods which take either the code itself or a filename to look for the code.
	  2)vararg-based attribute-enabled 'loadShaderPairWithAttributes' and 'loadShaderPairSrcWithAttributes'(these names are getting long...)
	  3)lookupShader, which looks for a shader based on its code? I guess to see if it's already loaded. Not implemented.
	  
	  What can we learn from this?
	  Well, first, it looks VERY much like they're using loadShaderPairSrcWithAttributes wrong. I have no damn idea HOW, in fact, they're using it.
	  It takes a base of three const char* variables, and they pass in two and an int....
	  Ok, well that answers THAT question. Those methods AREN'T EVEN USED. It uses gltLoadShaderPairSrcWithAttributes! In GLTools! 
	  Ayayay.
	  So there's that. Let's put the working functions IN HERE, maybe.
	  ...I wonder if these issues were solved in future releases? Probably, I'd imagine, but they use versions of OpenGL I can't run atm.
	 */
};


#endif //__ST_SHADER_H__
