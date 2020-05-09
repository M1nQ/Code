#pragma once

#include <iostream>
#include <GL/glew.h>

using namespace std;

class ErrorChecker
{
public:
	inline ErrorChecker() {}
	inline ~ErrorChecker() {}

	inline bool CHECKERROR()
	{
		GLenum error = glGetError();

		switch (error)
		{
		case GL_NO_ERROR: return false;
		case GL_INVALID_ENUM: cout << "Invalid enum " << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl; return true;
		case GL_INVALID_VALUE: cout << "Invalid value " << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl; return true;
		case GL_INVALID_OPERATION: cout << "Invalid operation " << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl; return true;
		case GL_INVALID_FRAMEBUFFER_OPERATION: cout << "Invalid frambuffer operation " << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl; return true;
		case GL_OUT_OF_MEMORY: cout << "Out of memory " << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl; return true;
		default: cout << "Unknown error" << endl; return true;
		}
	}
};