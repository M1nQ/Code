#include <Object.h>

#define GetError if (errorCheck.CHECKERROR()) _CrtDbgBreak();
#define PI 3.141592653589793238462643383279502884f

Object::Object()
{

}
Object::Object(const GLuint program, const string objectPath, const string texturePath)
{
	errorCheck = ErrorChecker();
	LoadObject(objectPath);
	InitializeModel();
	InitializeTexture(texturePath);
	InitializeVariables(program);
}
Object::~Object()
{
	glDeleteBuffers(1, &buffer);
	glDeleteVertexArrays(1, &vertexArrayObject);
	glDeleteTextures(1, &texture);
	delete[] vertexData;
}

void Object::Draw()
{
	glBindVertexArray(vertexArrayObject);
	GetError;
	glBindTexture(GL_TEXTURE_2D, texture);
	GetError;

	worldTransform = translate(position) * rotation;
	glUniformMatrix4fv(worldTransformIndex, 1, GL_FALSE, value_ptr(worldTransform));
	GetError;

	glDrawArrays(GL_TRIANGLES, 0, vertexDataLenght);
	GetError;

	glBindVertexArray(0);
	GetError;
	glBindTexture(GL_TEXTURE_2D, 0);
	GetError;
}
void Object::Move(const vec3 offset)
{
	position += offset;
}
void Object::Rotate(const float radians, const vec3 axis)
{
	rotation *= rotate(radians, axis);
}

void Object::LoadObject(const string objectPath)
{
	// Opens the file and initializes variables used while reading the file.

	ifstream file;
	file.open(objectPath, ios::in);
	assert(file);

	string line = "";
	vector<GLfloat> vertices = vector<GLfloat>();
	vector<GLfloat> textureCoords = vector<GLfloat>();
	vector<GLfloat> outputData = vector<GLfloat>();

	int lineIndex = 0;

	string number = "";
	bool isVertex = true;
	int convertedNumber = 0;

	while (getline(file, line))
	{
		number.clear();

		// Reads vertices into a vector.

		if (line[0] == 'v' && line[1] == ' ')
		{
			for (lineIndex = 3; lineIndex < line.length(); ++lineIndex)
			{
				if (line[lineIndex] != ' ' && lineIndex != line.length() - 1)
				{
					number += line[lineIndex];
				}
				else
				{
					if (lineIndex == line.length() - 1)
						number += line[lineIndex];

					vertices.push_back(atof(number.c_str()));
					number.clear();
				}
			}
		}

		// Reads texture coordinates into a vector.

		else if (line[0] == 'v' && line[1] == 't')
		{
			for (lineIndex = 3; lineIndex < line.length(); ++lineIndex)
			{
				if (line[lineIndex] != ' ' && lineIndex != line.length() - 1)
				{
					number += line[lineIndex];
				}
				else
				{
					if (lineIndex == line.length() - 1)
						number += line[lineIndex];

					textureCoords.push_back(atof(number.c_str()));
					number.clear();
				}
			}
		}

		// Creates a vector of both vertices and texture coordinates accordingly.

		else if (line[0] == 'f' && line[1] == ' ')
		{
			for (lineIndex = 2; lineIndex < line.length(); ++lineIndex)
			{
				if (line[lineIndex] == ' ' || line[lineIndex] == '/' || lineIndex >= line.length() - 1)
				{
					if (lineIndex >= line.length() - 1 && line[lineIndex] != ' ')
						number += line[lineIndex];

					convertedNumber = atoi(number.c_str());

					if (isVertex)
					{
						for (int i = 0; i < 3; ++i)
						{
							outputData.push_back(vertices[((convertedNumber - 1) * 3) + i]);
						}
					}
					else
					{
						for (int i = 0; i < 3; ++i)
						{
							outputData.push_back(textureCoords[((convertedNumber - 1) * 3) + i]);
						}
					}

					isVertex = !isVertex;
					number.clear();
				}
				else
				{
					number += line[lineIndex];
				}
			}

			isVertex = true;
		}
	}

	// Closes file and puts the final data into the object's vertexData array.

	file.close();
	vertexDataLenght = outputData.size();
	vertexData = new GLfloat[vertexDataLenght];

	for (int i = 0; i < vertexDataLenght; ++i)
	{
		vertexData[i] = outputData[i];
	}
}
void Object::InitializeModel()
{
	// Initializes vertices and buffer

	glGenVertexArrays(1, &vertexArrayObject);
	GetError;
	glBindVertexArray(vertexArrayObject);
	GetError;

	glGenBuffers(1, &buffer);
	GetError;
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	GetError;

	glBufferData(GL_ARRAY_BUFFER, (vertexDataLenght * sizeof(GLfloat)), vertexData, GL_STATIC_DRAW);
	GetError;

	glEnableVertexAttribArray(0);
	GetError;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);
	GetError;

	glEnableVertexAttribArray(1);
	GetError;
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat)* 3));
	GetError;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	GetError;
	glBindVertexArray(0);
	GetError;
}
void Object::InitializeTexture(const string texturePath)
{
	glGenTextures(1, &texture);
	GetError;

	glActiveTexture(GL_TEXTURE0);
	GetError;

	glBindTexture(GL_TEXTURE_2D, texture);
	GetError;

	unsigned int imageWidth;
	unsigned int imageHeight;
	vector<unsigned char> imageData;
	unsigned int result = lodepng::decode(imageData, imageWidth, imageHeight, texturePath);
	assert(result == 0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());
	GetError;

	glGenerateMipmap(GL_TEXTURE_2D);
	GetError;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GetError;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	GetError;
}
void Object::InitializeVariables(const GLuint program)
{
	worldTransform = glm::mat4();
	worldTransformIndex = glGetUniformLocation(program, "unifWorld");
	GetError;

	position = vec3(0.f, 0.f, 0.f);
	rotation = glm::mat4();
}