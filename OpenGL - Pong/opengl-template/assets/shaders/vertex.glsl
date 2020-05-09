/**
 * @file assets/shaders/vertex.glsl
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

#version 330

out vec2 texCoords;
uniform mat4 projectionMatrix;
uniform mat4 viewTransformMatrix;
uniform mat4 unifWorld;

layout(location = 0) in vec4 inPosition;
layout(location = 1) in vec2 textureCoordinates;

void main()
{
	gl_Position = projectionMatrix * viewTransformMatrix * unifWorld * inPosition;
	texCoords = textureCoordinates;
}
