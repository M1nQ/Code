/**
 * @file Application.h
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

#pragma once

#include <GLM.h>
#include <GL/glew.h>
#include <ShaderSource.h>
#include <Object.h>
#include <Error.h>
#include <Windows.h>

namespace Config
{
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	const int MULTISAMPLING_SAMPLES = 16; // 0 = disabled
}

using namespace glm;
using namespace Config;

class Application
{
public:

	Application();
	~Application();

	void Update(const float deltaTime);

private:
	void InitializeShaders();
	void InitializeProgram();
	void InitializeTransform();
	void InitializeObjects();
	void ResetBall();
	void UpdateBallMovement(const float deltaTime);
	bool CheckCollisionWithPlayer(Object* player);
	bool CheckCollisionWithBounds();
	bool CheckIfBallOutsideBounds();
	float GetLenght(vec3 vector);
	void UpdatePlayerMovement(const float deltaTime);

	GLint program;
	GLint vertexShader;
	GLint fragmentShader;

	Object* playerOne;
	Object* playerTwo;

	Object* ball;
	vec3 ballDirection;
	float ballVelocity;

	ErrorChecker errorCheck;
};
