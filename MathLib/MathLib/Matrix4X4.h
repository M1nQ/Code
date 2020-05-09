#ifndef MATRIX4X4
#define MATRIX4X4

#include <iostream>
#include "Vector3.h"

namespace Omniverse
{
	class Matrix4X4
	{
		// Operator overloading
		friend Matrix4X4 operator+ (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo);
		friend Matrix4X4 operator- (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo);
		friend Matrix4X4 operator* (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo);
		friend Matrix4X4 operator* (const Matrix4X4& matrix, const float number);
		friend Matrix4X4 operator* (const float number, const Matrix4X4& matrix);
		friend Vector3 operator* (const Matrix4X4& matrix, const Vector3& vector);
		friend ostream& operator<< (ostream& outStream, const Matrix4X4& matrix);

	public:
		// Operator overloading
		Matrix4X4& operator+= (const Matrix4X4 matrix);
		Matrix4X4& operator-= (const Matrix4X4 matrix);
		Matrix4X4& operator*= (const Matrix4X4 matrix);
		Matrix4X4& operator*= (const float number);
		float* operator[] (const int row);

		// Constructors and destructor
		inline Matrix4X4();
		inline Matrix4X4(const Matrix4X4& matrix);
		inline Matrix4X4(const float y1x1, const float y1x2, const float y1x3, const float y1x4, const float y2x1, const float y2x2, const float y2x3, const float y2x4, const float y3x1, const float y3x2, const float y3x3, const float y3x4, const float y4x1, const float y4x2, const float y4x3, const float y4x4);
		inline ~Matrix4X4() {}

		// Functions
		void Cofactor();
		void Invert();
		void Transpose();

		// Static functions
		static float Determinant(const Matrix4X4& matrix);
		static Matrix4X4 Cofactor(const Matrix4X4& matrix);
		static Matrix4X4 Transpose(const Matrix4X4& matrix);
		static Matrix4X4 Invert(const Matrix4X4& matrix);

		// Variables
		float data[4][4];

		// Default matrices
		const static Matrix4X4 Identity;
		const static Matrix4X4 Zero;
	};

	// Constructors
	Matrix4X4::Matrix4X4()
	{
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = 0;
	}
	Matrix4X4::Matrix4X4(const Matrix4X4& matrix)
	{
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = matrix.data[y][x];
	}
	Matrix4X4::Matrix4X4(const float y1x1, const float y1x2, const float y1x3, const float y1x4, const float y2x1, const float y2x2, const float y2x3, const float y2x4, const float y3x1, const float y3x2, const float y3x3, const float y3x4, const float y4x1, const float y4x2, const float y4x3, const float y4x4)
	{
		data[0][0] = y1x1;
		data[0][1] = y1x2;
		data[0][2] = y1x3;
		data[0][3] = y1x4;

		data[1][0] = y2x1;
		data[1][1] = y2x2;
		data[1][2] = y2x3;
		data[1][3] = y2x4;

		data[2][0] = y3x1;
		data[2][1] = y3x2;
		data[2][2] = y3x3;
		data[2][3] = y3x4;

		data[3][0] = y4x1;
		data[3][1] = y4x2;
		data[3][2] = y4x3;
		data[3][3] = y4x4;
	}
}

#endif MATRIX4X4