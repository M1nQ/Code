#include <vector>
#include "Matrix4X4.h"
#include "Matrix3X3.h"
#include "Vector4.h"

namespace Omniverse
{
	// Operator overloading
	Matrix4X4 operator+ (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo)
	{
		Matrix4X4 result;

		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				result[y][x] = matrixOne.data[y][x] + matrixTwo.data[y][x];

		return result;
	}
	Matrix4X4 operator- (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo)
	{
		Matrix4X4 result;

		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				result[y][x] = matrixOne.data[y][x] - matrixTwo.data[y][x];

		return result;
	}
	Matrix4X4 operator* (const Matrix4X4& matrixOne, const Matrix4X4& matrixTwo)
	{
		Matrix4X4 result;

		result[0][0] = matrixOne.data[0][0] * matrixTwo.data[0][0] + matrixOne.data[0][1] * matrixTwo.data[1][0] + matrixOne.data[0][2] * matrixTwo.data[2][0] + matrixOne.data[0][3] * matrixTwo.data[3][0];
		result[0][1] = matrixOne.data[0][0] * matrixTwo.data[0][1] + matrixOne.data[0][1] * matrixTwo.data[1][1] + matrixOne.data[0][2] * matrixTwo.data[2][1] + matrixOne.data[0][3] * matrixTwo.data[3][1];
		result[0][2] = matrixOne.data[0][0] * matrixTwo.data[0][2] + matrixOne.data[0][1] * matrixTwo.data[1][2] + matrixOne.data[0][2] * matrixTwo.data[2][2] + matrixOne.data[0][3] * matrixTwo.data[3][2];
		result[0][3] = matrixOne.data[0][0] * matrixTwo.data[0][3] + matrixOne.data[0][1] * matrixTwo.data[1][3] + matrixOne.data[0][2] * matrixTwo.data[2][3] + matrixOne.data[0][3] * matrixTwo.data[3][3];
																																															  
		result[1][0] = matrixOne.data[1][0] * matrixTwo.data[0][0] + matrixOne.data[1][1] * matrixTwo.data[1][0] + matrixOne.data[1][2] * matrixTwo.data[2][0] + matrixOne.data[1][3] * matrixTwo.data[3][0];
		result[1][1] = matrixOne.data[1][0] * matrixTwo.data[0][1] + matrixOne.data[1][1] * matrixTwo.data[1][1] + matrixOne.data[1][2] * matrixTwo.data[2][1] + matrixOne.data[1][3] * matrixTwo.data[3][1];
		result[1][2] = matrixOne.data[1][0] * matrixTwo.data[0][2] + matrixOne.data[1][1] * matrixTwo.data[1][2] + matrixOne.data[1][2] * matrixTwo.data[2][2] + matrixOne.data[1][3] * matrixTwo.data[3][2];
		result[1][3] = matrixOne.data[1][0] * matrixTwo.data[0][3] + matrixOne.data[1][1] * matrixTwo.data[1][3] + matrixOne.data[1][2] * matrixTwo.data[2][3] + matrixOne.data[1][3] * matrixTwo.data[3][3];
																																															  
		result[2][0] = matrixOne.data[2][0] * matrixTwo.data[0][0] + matrixOne.data[2][1] * matrixTwo.data[1][0] + matrixOne.data[2][2] * matrixTwo.data[2][0] + matrixOne.data[2][3] * matrixTwo.data[3][0];
		result[2][1] = matrixOne.data[2][0] * matrixTwo.data[0][1] + matrixOne.data[2][1] * matrixTwo.data[1][1] + matrixOne.data[2][2] * matrixTwo.data[2][1] + matrixOne.data[2][3] * matrixTwo.data[3][1];
		result[2][2] = matrixOne.data[2][0] * matrixTwo.data[0][2] + matrixOne.data[2][1] * matrixTwo.data[1][2] + matrixOne.data[2][2] * matrixTwo.data[2][2] + matrixOne.data[2][3] * matrixTwo.data[3][2];
		result[2][3] = matrixOne.data[2][0] * matrixTwo.data[0][3] + matrixOne.data[2][1] * matrixTwo.data[1][3] + matrixOne.data[2][2] * matrixTwo.data[2][3] + matrixOne.data[2][3] * matrixTwo.data[3][3];
																																															  
		result[3][0] = matrixOne.data[3][0] * matrixTwo.data[0][0] + matrixOne.data[3][1] * matrixTwo.data[1][0] + matrixOne.data[3][2] * matrixTwo.data[2][0] + matrixOne.data[3][3] * matrixTwo.data[3][0];
		result[3][1] = matrixOne.data[3][0] * matrixTwo.data[0][1] + matrixOne.data[3][1] * matrixTwo.data[1][1] + matrixOne.data[3][2] * matrixTwo.data[2][1] + matrixOne.data[3][3] * matrixTwo.data[3][1];
		result[3][2] = matrixOne.data[3][0] * matrixTwo.data[0][2] + matrixOne.data[3][1] * matrixTwo.data[1][2] + matrixOne.data[3][2] * matrixTwo.data[2][2] + matrixOne.data[3][3] * matrixTwo.data[3][2];
		result[3][3] = matrixOne.data[3][0] * matrixTwo.data[0][3] + matrixOne.data[3][1] * matrixTwo.data[1][3] + matrixOne.data[3][2] * matrixTwo.data[2][3] + matrixOne.data[3][3] * matrixTwo.data[3][3];

		return result;
	}
	Matrix4X4 operator* (const Matrix4X4& matrix, const float number)
	{
		Matrix4X4 result;

		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				result[y][x] = matrix.data[y][x] * number;

		return result;
	}
	Matrix4X4 operator* (const float number, const Matrix4X4& matrix)
	{
		return matrix * number;
	}
	Vector3 operator* (const Matrix4X4& matrix, const Vector3& vector)
	{
		Vector4 result = Vector4(vector.x, vector.y, vector.z, 1.f);

		for (int i = 0; i < 4; ++i)
			result[i] = matrix.data[i][0] * vector.x + matrix.data[i][1] * vector.y + matrix.data[i][2] * vector.z + matrix.data[i][3] * 1;

		return Vector3(result.x, result.y, result.z);
	}
	ostream& operator<< (ostream& outStream, const Matrix4X4& matrix)
	{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				outStream << matrix.data[y][x] << " ";

			outStream << endl;
		}

		return outStream;
	}

	// Operator overloading
	Matrix4X4& Matrix4X4::operator+= (const Matrix4X4 matrix)
	{
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = data[y][x] + matrix.data[y][x];

		return *this;
	}
	Matrix4X4& Matrix4X4::operator-= (const Matrix4X4 matrix)
	{
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = data[y][x] - matrix.data[y][x];

		return *this;
	}
	Matrix4X4& Matrix4X4::operator*= (const Matrix4X4 matrix)
	{
		Matrix4X4 temp = Matrix4X4(*this);

		data[0][0] = temp.data[0][0] * matrix.data[0][0] + temp.data[0][1] * matrix.data[1][0] + temp.data[0][2] * matrix.data[2][0] + temp.data[0][3] * matrix.data[3][0];
		data[0][1] = temp.data[0][0] * matrix.data[0][1] + temp.data[0][1] * matrix.data[1][1] + temp.data[0][2] * matrix.data[2][1] + temp.data[0][3] * matrix.data[3][1];
		data[0][2] = temp.data[0][0] * matrix.data[0][2] + temp.data[0][1] * matrix.data[1][2] + temp.data[0][2] * matrix.data[2][2] + temp.data[0][3] * matrix.data[3][2];
		data[0][3] = temp.data[0][0] * matrix.data[0][3] + temp.data[0][1] * matrix.data[1][3] + temp.data[0][2] * matrix.data[2][3] + temp.data[0][3] * matrix.data[3][3];
					 																												   
		data[1][0] = temp.data[1][0] * matrix.data[0][0] + temp.data[1][1] * matrix.data[1][0] + temp.data[1][2] * matrix.data[2][0] + temp.data[1][3] * matrix.data[3][0];
		data[1][1] = temp.data[1][0] * matrix.data[0][1] + temp.data[1][1] * matrix.data[1][1] + temp.data[1][2] * matrix.data[2][1] + temp.data[1][3] * matrix.data[3][1];
		data[1][2] = temp.data[1][0] * matrix.data[0][2] + temp.data[1][1] * matrix.data[1][2] + temp.data[1][2] * matrix.data[2][2] + temp.data[1][3] * matrix.data[3][2];
		data[1][3] = temp.data[1][0] * matrix.data[0][3] + temp.data[1][1] * matrix.data[1][3] + temp.data[1][2] * matrix.data[2][3] + temp.data[1][3] * matrix.data[3][3];
					 																												   
		data[2][0] = temp.data[2][0] * matrix.data[0][0] + temp.data[2][1] * matrix.data[1][0] + temp.data[2][2] * matrix.data[2][0] + temp.data[2][3] * matrix.data[3][0];
		data[2][1] = temp.data[2][0] * matrix.data[0][1] + temp.data[2][1] * matrix.data[1][1] + temp.data[2][2] * matrix.data[2][1] + temp.data[2][3] * matrix.data[3][1];
		data[2][2] = temp.data[2][0] * matrix.data[0][2] + temp.data[2][1] * matrix.data[1][2] + temp.data[2][2] * matrix.data[2][2] + temp.data[2][3] * matrix.data[3][2];
		data[2][3] = temp.data[2][0] * matrix.data[0][3] + temp.data[2][1] * matrix.data[1][3] + temp.data[2][2] * matrix.data[2][3] + temp.data[2][3] * matrix.data[3][3];
																																	   
		data[3][0] = temp.data[3][0] * matrix.data[0][0] + temp.data[3][1] * matrix.data[1][0] + temp.data[3][2] * matrix.data[2][0] + temp.data[3][3] * matrix.data[3][0];
		data[3][1] = temp.data[3][0] * matrix.data[0][1] + temp.data[3][1] * matrix.data[1][1] + temp.data[3][2] * matrix.data[2][1] + temp.data[3][3] * matrix.data[3][1];
		data[3][2] = temp.data[3][0] * matrix.data[0][2] + temp.data[3][1] * matrix.data[1][2] + temp.data[3][2] * matrix.data[2][2] + temp.data[3][3] * matrix.data[3][2];
		data[3][3] = temp.data[3][0] * matrix.data[0][3] + temp.data[3][1] * matrix.data[1][3] + temp.data[3][2] * matrix.data[2][3] + temp.data[3][3] * matrix.data[3][3];

		return *this;
	}
	Matrix4X4& Matrix4X4::operator*= (const float number)
	{
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = data[y][x] * number;

		return *this;
	}
	float* Matrix4X4::operator[] (const int row)
	{
		return data[row];
	}

	// Functions
	void Matrix4X4::Cofactor()
	{
		Matrix4X4 temp4 = Matrix4X4(*this);
		Matrix3X3 temp3;
		vector<float> tempV;
		int count = 0;

		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				for (int j = 0; j < 4; ++j)
					for (int i = 0; i < 4; ++i)
						if (y != j && x != i)
							tempV.push_back(temp4[j][i]);

				for (int j = 0; j < 3; ++j)
					for (int i = 0; i < 3; ++i)
						temp3[j][i] = tempV[count++];

				data[y][x] = Matrix3X3::Determinant(temp3) * Power(-1.f, x + y + 2);
				tempV.clear();
				count = 0;
			}
		}
	}
	void Matrix4X4::Invert()
	{
		if (Determinant(*this) != 0)
		{
			Matrix4X4 temp = Matrix4X4(*this);
			temp.Cofactor();
			temp.Transpose();
			temp *= (1.f / Determinant(*this));

			for (int y = 0; y < 4; ++y)
				for (int x = 0; x < 4; ++x)
					data[y][x] = temp.data[y][x];
		}
	}
	void Matrix4X4::Transpose()
	{
		Matrix4X4 temp = Matrix4X4(*this);

		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				data[y][x] = temp.data[x][y];
	}

	// Static functions
	float Matrix4X4::Determinant(const Matrix4X4& matrix)
	{
		Matrix3X3 temp3;
		vector<float> tempV;
		float result = 0;
		int count = 0;

		for (int x = 0; x < 4; ++x)
		{
			for (int j = 0; j < 4; ++j)
				for (int i = 0; i < 4; ++i)
					if (0 != j && x != i)
						tempV.push_back(matrix.data[j][i]);

			for (int j = 0; j < 3; ++j)
				for (int i = 0; i < 3; ++i)
					temp3[j][i] = tempV[count++];

			result += Matrix3X3::Determinant(temp3) * (matrix.data[0][x] * Power(-1.f, x + 2));
			tempV.clear();
			count = 0;
		}

		return result;
	}
	Matrix4X4 Matrix4X4::Cofactor(const Matrix4X4& matrix)
	{
		Matrix4X4 result = Matrix4X4(matrix);
		result.Cofactor();
		return result;
	}
	Matrix4X4 Matrix4X4::Transpose(const Matrix4X4& matrix)
	{
		Matrix4X4 result = Matrix4X4(matrix);
		result.Transpose();
		return result;
	}
	Matrix4X4 Matrix4X4::Invert(const Matrix4X4& matrix)
	{
		Matrix4X4 result = Matrix4X4(matrix);
		result.Invert();
		return result;
	}

	// Default matrices
	const Matrix4X4 Matrix4X4::Identity = Matrix4X4(1, 0, 0, 0, 0, 1, 0, 0,	0, 0, 1, 0,	0, 0, 0, 1);
	const Matrix4X4 Matrix4X4::Zero = Matrix4X4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}