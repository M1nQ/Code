#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include <iostream>
#include "Vector3.h"
#include "Quaternion.h"

namespace Omniverse
{
	class Matrix3X3
	{
		// Operator overloading
		friend Matrix3X3 operator+ (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo);
		friend Matrix3X3 operator- (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo);
		friend Matrix3X3 operator* (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo);
		friend Matrix3X3 operator* (const Matrix3X3& matrix, const float number);
		friend Matrix3X3 operator* (const float number, const Matrix3X3& matrix);
		friend Vector3 operator* (const Matrix3X3& matrix, const Vector3& vector);
		friend ostream& operator<< (ostream& outStream, const Matrix3X3& matrix);

	public:
		// Operator overloading
		Matrix3X3& operator+= (const Matrix3X3 matrix);
		Matrix3X3& operator-= (const Matrix3X3 matrix);
		Matrix3X3& operator*= (const Matrix3X3 matrix);
		Matrix3X3& operator*= (const float number);
		float* operator[] (const int row);

		// Constructors and destructor
		inline Matrix3X3();
		inline Matrix3X3(const Matrix3X3& matrix);
		inline Matrix3X3(const float y1x1, const float y1x2, const float y1x3, const float y2x1, const float y2x2, const float y2x3, const float y3x1, const float y3x2, const float y3x3);
		inline ~Matrix3X3() {}

		// Functions
		void Cofactor();
		void Invert();
		void Orientation(const Quaternion& quaternion);
		void Transpose();

		// Static functions
		static float Determinant(const Matrix3X3& matrix);
		static Matrix3X3 Cofactor(const Matrix3X3& matrix);
		static Matrix3X3 Transpose(const Matrix3X3& matrix);
		static Matrix3X3 Invert(const Matrix3X3& matrix);

		// Variables
		float data[3][3];

		// Default matrices
		const static Matrix3X3 Identity;
		const static Matrix3X3 Zero;
	};

	// Constructors
	Matrix3X3::Matrix3X3()
	{
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = 0;
	}
	Matrix3X3::Matrix3X3(const Matrix3X3& matrix)
	{
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = matrix.data[y][x];
	}
	Matrix3X3::Matrix3X3(const float y1x1, const float y1x2, const float y1x3, const float y2x1, const float y2x2, const float y2x3, const float y3x1, const float y3x2, const float y3x3)
	{
		data[0][0] = y1x1;
		data[0][1] = y1x2;
		data[0][2] = y1x3;

		data[1][0] = y2x1;
		data[1][1] = y2x2;
		data[1][2] = y2x3;

		data[2][0] = y3x1;
		data[2][1] = y3x2;
		data[2][2] = y3x3;
	}
}

#endif MATRIX3X3_H