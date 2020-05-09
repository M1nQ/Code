/**
 * @file Application.cpp
 *
 * OpenGL Template
 * Copyright 2015 Eetu 'Devenec' Oinasmaa
 *
 * OpenGL Template is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Application.h>

#define GetError if (errorCheck.CHECKERROR()) _CrtDbgBreak();
#define PI 3.141592653589793238462643383279502884f

// Public

Application::Application()
{
	// Initialisation

	errorCheck = ErrorChecker();
	program = glCreateProgram();
	GetError;

	InitializeShaders();
	InitializeProgram();
	InitializeTransform();
	InitializeObjects();

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}
Application::~Application()
{
	// Deinitialisation

	glUseProgram(0);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteProgram(program);

	delete ball;
	delete playerOne;
	delete playerTwo;
}

void Application::Update(const float deltaTime)
{
	// Updating and drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GetError;

	UpdatePlayerMovement(deltaTime);
	UpdateBallMovement(deltaTime);

	playerOne->Draw();
	playerTwo->Draw();
	ball->Draw();
}

void Application::InitializeShaders()
{
	string vertexSource;
	assert(ShaderSource::load("assets/shaders/vertex.glsl", vertexSource));
	const char* VERTEX_SOURCE = vertexSource.c_str();
	string fragmentSource;
	assert(ShaderSource::load("assets/shaders/fragment.glsl", fragmentSource));
	const char* FRAGMENT_SOURCE = fragmentSource.c_str();

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	GetError;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GetError;

	GLint lenght = strlen(FRAGMENT_SOURCE);
	glShaderSource(fragmentShader, 1, &FRAGMENT_SOURCE, &lenght);
	GetError;

	lenght = strlen(VERTEX_SOURCE);
	glShaderSource(vertexShader, 1, &VERTEX_SOURCE, &lenght);
	GetError;

	glCompileShader(fragmentShader);
	GetError;

	glCompileShader(vertexShader);
	GetError;

	glAttachShader(program, fragmentShader);
	GetError;

	glAttachShader(program, vertexShader);
	GetError;
}
void Application::InitializeProgram()
{
	glLinkProgram(program);
	GetError;

	glUseProgram(program);
	GetError;
}
void Application::InitializeTransform()
{
	// Initializes and sets projection and view matrices.

	mat4 projectionTransform = perspective(radians(60.0f), static_cast<float>(WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 2000.0f);
	float* pointerToFloat = value_ptr(projectionTransform);

	GLint projectionLocation;
	projectionLocation = glGetUniformLocation(program, "projectionMatrix");
	GetError;
	assert(projectionLocation != -1);

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, pointerToFloat);
	GetError;

	mat4 viewTransform = inverse(translate(vec3(0.f, 0.f, 600.f)));
	pointerToFloat = value_ptr(viewTransform);

	GLint viewTransformLocation;
	viewTransformLocation = glGetUniformLocation(program, "viewTransformMatrix");
	GetError;
	assert(viewTransformLocation != -1);

	glUniformMatrix4fv(viewTransformLocation, 1, GL_FALSE, pointerToFloat);
	GetError;
}
void Application::InitializeObjects()
{
	playerOne = new Object(program, "assets/Objects/Bar.obj", "assets/Textures/Blue.png");
	playerTwo = new Object(program, "assets/Objects/Bar.obj", "assets/Textures/Red.png");
	ball = new Object(program, "assets/Objects/Ball.obj", "assets/Textures/White.png");

	playerOne->Move(vec3(-500.f, 0.f, 0.f));
	playerTwo->Move(vec3(500.f, 0.f, 0.f));
	ResetBall();
}
void Application::ResetBall()
{
	ball->position = vec3(0.f, 0.f, 0.f);
	ballDirection = vec3(-1.f, 0.f, 0.f);
	ballVelocity = 5.f;
}
void Application::UpdateBallMovement(const float deltaTime)
{
	ballVelocity += 0.1f * deltaTime;
	float distanceTravelled = 0.f;

	while (distanceTravelled <= ballVelocity * deltaTime)
	{
		// Collisions with players

		if (CheckCollisionWithPlayer(playerOne))
		{
			vec3 newDirection = ball->position - playerOne->position;
			newDirection = newDirection / GetLenght(newDirection);
			newDirection.z = 0.0f;
			ballDirection = newDirection;
		}
		else if (CheckCollisionWithPlayer(playerTwo))
		{
			vec3 newDirection = ball->position - playerTwo->position;
			newDirection = newDirection / GetLenght(newDirection);
			newDirection.z = 0.0f;
			ballDirection = newDirection;
		}

		// Collisions with bounds

		if (CheckCollisionWithBounds())
			ballDirection.y *= -1.f;

		// Checks for a goal

		if (CheckIfBallOutsideBounds())
		{
			ResetBall();
			break;
		}

		// Moves the ball 1 / 100 of the whole frame's distance to ensure collisions

		ball->Move(ballDirection * 0.01f * ballVelocity);
		distanceTravelled += 0.01f * ballVelocity;
	}
}
bool Application::CheckCollisionWithPlayer(Object* player)
{
	// Finds thep oint closest to ball's position inside the "box collider". (Box Width = 10, height = 50)

	vec3 closestPoint = ball->position - player->position;

	if (closestPoint.x > 5.f)
		closestPoint.x = 5.f;
	else if (closestPoint.x < -5.f)
		closestPoint.x = -5.f;

	if (closestPoint.y > 25.f)
		closestPoint.y = 25.f;
	else if (closestPoint.y < -25.f)
		closestPoint.y = -25.f;

	// Check if that point is inside the ball. (Ball radius = 10)

	vec3 distance = ball->position - (closestPoint + player->position);

	if (GetLenght(distance) <= 10.f)
	{
		ball->position += distance / GetLenght(distance) * (10.f - GetLenght(distance)); // Prevents the ball from going inside the player.
		return true;
	}
	else
		return false;
}
bool Application::CheckCollisionWithBounds()
{
	// Bound aprox. = 333
	if (abs(ball->position.y) > 333.f)
		return true;
	else
		return false;
}
bool Application::CheckIfBallOutsideBounds()
{
	if (abs(ball->position.x) > 650.f)
		return true;
	else
		return false;
}
float Application::GetLenght(vec3 vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}
void Application::UpdatePlayerMovement(const float deltaTime)
{
	// Bound approx. = 318

	// PlayerOne movement

	if (GetAsyncKeyState(0x57) != 0)										// W
		playerOne->Move(vec3(0.f, 1.f, 0.f) * 400.f * deltaTime);
	else if (GetAsyncKeyState(0x53) != 0)									// S
		playerOne->Move(vec3(0.f, -1.f, 0.f) * 400.f * deltaTime);

	if (playerOne->position.y > 318.f)
		playerOne->position.y = 318.f;
	else if (playerOne->position.y < -318.f)
		playerOne->position.y = -318.f;

	// PlayerTwo movement

	if (GetAsyncKeyState(0x26) != 0)										// Up
		playerTwo->Move(vec3(0.f, 1.f, 0.f) * 400.f * deltaTime);
	else if (GetAsyncKeyState(0x28) != 0)									// Down
		playerTwo->Move(vec3(0.f, -1.f, 0.f) * 400.f * deltaTime);

	if (playerTwo->position.y > 318.f)
		playerTwo->position.y = 318.f;
	else if (playerTwo->position.y < -318.f)
		playerTwo->position.y = -318.f;
}
