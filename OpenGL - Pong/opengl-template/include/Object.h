#pragma once

#include <GLM.h>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <lodepng.h>
#include <Error.h>

using namespace std;
using namespace glm;

class Object
{
public:
	Object();
	Object(const GLuint program, const string objectPath, const string texturePath);
	~Object();

	void Draw();
	void Move(const vec3 offset);
	void Rotate(const float radians, const vec3 axis);

	vec3 position;

private:
	void LoadObject(const string objectPath);
	void InitializeModel();
	void InitializeTexture(const string texturePath);
	void InitializeVariables(const GLuint program);

	GLfloat* vertexData;
	GLint vertexDataLenght;
	GLuint buffer;
	GLuint vertexArrayObject;
	GLuint texture;
	GLint worldTransformIndex;
	mat4 worldTransform;
	mat4 rotation;

	ErrorChecker errorCheck;
};