#include "Matrix3X3.h"

namespace Omniverse
{
	// Operator overloading
	Matrix3X3 operator+ (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo)
	{
		Matrix3X3 result;

		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				result[y][x] = matrixOne.data[y][x] + matrixTwo.data[y][x];

		return result;
	}
	Matrix3X3 operator- (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo)
	{
		Matrix3X3 result;

		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				result[y][x] = matrixOne.data[y][x] - matrixTwo.data[y][x];

		return result;
	}
	Matrix3X3 operator* (const Matrix3X3& matrixOne, const Matrix3X3& matrixTwo)
	{
		Matrix3X3 result;

		result[0][0] = matrixOne.data[0][0] * matrixTwo.data[0][0] + matrixOne.data[0][1] * matrixTwo.data[1][0] + matrixOne.data[0][2] * matrixTwo.data[2][0];
		result[0][1] = matrixOne.data[0][0] * matrixTwo.data[0][1] + matrixOne.data[0][1] * matrixTwo.data[1][1] + matrixOne.data[0][2] * matrixTwo.data[2][1];
		result[0][2] = matrixOne.data[0][0] * matrixTwo.data[0][2] + matrixOne.data[0][1] * matrixTwo.data[1][2] + matrixOne.data[0][2] * matrixTwo.data[2][2];

		result[1][0] = matrixOne.data[1][0] * matrixTwo.data[0][0] + matrixOne.data[1][1] * matrixTwo.data[1][0] + matrixOne.data[1][2] * matrixTwo.data[2][0];
		result[1][1] = matrixOne.data[1][0] * matrixTwo.data[0][1] + matrixOne.data[1][1] * matrixTwo.data[1][1] + matrixOne.data[1][2] * matrixTwo.data[2][1];
		result[1][2] = matrixOne.data[1][0] * matrixTwo.data[0][2] + matrixOne.data[1][1] * matrixTwo.data[1][2] + matrixOne.data[1][2] * matrixTwo.data[2][2];

		result[2][0] = matrixOne.data[2][0] * matrixTwo.data[0][0] + matrixOne.data[2][1] * matrixTwo.data[1][0] + matrixOne.data[2][2] * matrixTwo.data[2][0];
		result[2][1] = matrixOne.data[2][0] * matrixTwo.data[0][1] + matrixOne.data[2][1] * matrixTwo.data[1][1] + matrixOne.data[2][2] * matrixTwo.data[2][1];
		result[2][2] = matrixOne.data[2][0] * matrixTwo.data[0][2] + matrixOne.data[2][1] * matrixTwo.data[1][2] + matrixOne.data[2][2] * matrixTwo.data[2][2];

		return result;
	}
	Matrix3X3 operator* (const Matrix3X3& matrix, const float number)
	{
		Matrix3X3 result;

		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				result[y][x] = matrix.data[y][x] * number;

		return result;
	}
	Matrix3X3 operator* (const float number, const Matrix3X3& matrix)
	{
		return matrix * number;
	}
	Vector3 operator* (const Matrix3X3& matrix, const Vector3& vector)
	{
		Vector3 result;

		for (int i = 0; i < 3; ++i)
			result[i] = matrix.data[i][0] * vector.x + matrix.data[i][1] * vector.y + matrix.data[i][2] * vector.z;

		return result;
	}
	ostream& operator<< (ostream& outStream, const Matrix3X3& matrix)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
				outStream << matrix.data[y][x] << " ";

			outStream << endl;
		}

		return outStream;
	}

	// Operator overloading
	Matrix3X3& Matrix3X3::operator+= (const Matrix3X3 matrix)
	{
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = data[y][x] + matrix.data[y][x];

		return *this;
	}
	Matrix3X3& Matrix3X3::operator-= (const Matrix3X3 matrix)
	{
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = data[y][x] - matrix.data[y][x];

		return *this;
	}
	Matrix3X3& Matrix3X3::operator*= (const Matrix3X3 matrix)
	{
		Matrix3X3 temp = Matrix3X3(*this);

		data[0][0] = temp.data[0][0] * matrix.data[0][0] + temp.data[0][1] * matrix.data[1][0] + temp.data[0][2] * matrix.data[2][0];
		data[0][1] = temp.data[0][0] * matrix.data[0][1] + temp.data[0][1] * matrix.data[1][1] + temp.data[0][2] * matrix.data[2][1];
		data[0][2] = temp.data[0][0] * matrix.data[0][2] + temp.data[0][1] * matrix.data[1][2] + temp.data[0][2] * matrix.data[2][2];

		data[1][0] = temp.data[1][0] * matrix.data[0][0] + temp.data[1][1] * matrix.data[1][0] + temp.data[1][2] * matrix.data[2][0];
		data[1][1] = temp.data[1][0] * matrix.data[0][1] + temp.data[1][1] * matrix.data[1][1] + temp.data[1][2] * matrix.data[2][1];
		data[1][2] = temp.data[1][0] * matrix.data[0][2] + temp.data[1][1] * matrix.data[1][2] + temp.data[1][2] * matrix.data[2][2];

		data[2][0] = temp.data[2][0] * matrix.data[0][0] + temp.data[2][1] * matrix.data[1][0] + temp.data[2][2] * matrix.data[2][0];
		data[2][1] = temp.data[2][0] * matrix.data[0][1] + temp.data[2][1] * matrix.data[1][1] + temp.data[2][2] * matrix.data[2][1];
		data[2][2] = temp.data[2][0] * matrix.data[0][2] + temp.data[2][1] * matrix.data[1][2] + temp.data[2][2] * matrix.data[2][2];

		return *this;
	}
	Matrix3X3& Matrix3X3::operator*= (const float number)
	{
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = data[y][x] * number;

		return *this;
	}
	float* Matrix3X3::operator[] (const int row)
	{
		return data[row];
	}

	// Functions
	void Matrix3X3::Cofactor()
	{
		Matrix3X3 temp = Matrix3X3(*this);

		data[0][0] = temp[1][1] * temp[2][2] - temp[1][2] * temp[2][1];
		data[0][1] = temp[1][2] * temp[2][0] - temp[1][0] * temp[2][2];
		data[0][2] = temp[1][0] * temp[2][1] - temp[1][1] * temp[2][0];

		data[1][0] = temp[0][2] * temp[2][1] - temp[0][1] * temp[2][2];
		data[1][1] = temp[0][0] * temp[2][2] - temp[0][2] * temp[2][0];
		data[1][2] = temp[0][1] * temp[2][0] - temp[0][0] * temp[2][1];

		data[2][0] = temp[0][1] * temp[1][2] - temp[0][2] * temp[1][1];
		data[2][1] = temp[0][2] * temp[1][0] - temp[0][0] * temp[1][2];
		data[2][2] = temp[0][0] * temp[1][1] - temp[0][1] * temp[1][0];
	}
	void Matrix3X3::Invert()
	{
		if (Determinant(*this) != 0)
		{
			Matrix3X3 temp = Matrix3X3(*this);
			temp.Cofactor();
			temp.Transpose();
			temp *= (1.f / Determinant(*this));

			for (int y = 0; y < 3; ++y)
				for (int x = 0; x < 3; ++x)
					data[y][x] = temp.data[y][x];
		}
	}
	void Matrix3X3::Orientation(const Quaternion& quaternion)
	{
		data[0][0] = 1 - 2 * Power(quaternion.x, 2.f) - Power(quaternion.y, 2.f);
		data[0][1] = 2 * quaternion.w * quaternion.x - 2 * quaternion.y * quaternion.z;
		data[0][2] = 2 * quaternion.w * quaternion.y + 2 * quaternion.x * quaternion.z;

		data[1][0] = 2 * quaternion.w * quaternion.x + 2 * quaternion.y * quaternion.z;
		data[1][1] = 1 - 2 * Power(quaternion.w, 2.f) - 2 * Power(quaternion.y, 2.f);
		data[1][2] = 2 * quaternion.x * quaternion.y - 2 * quaternion.w * quaternion.z;

		data[2][0] = 2 * quaternion.w * quaternion.y - 2 * quaternion.x * quaternion.z;
		data[2][1] = 2 * quaternion.x * quaternion.y + 2 * quaternion.w * quaternion.z;
		data[2][2] = 1 - 2 * Power(quaternion.w, 2.f) - 2 * Power(quaternion.x, 2.f);
	}
	void Matrix3X3::Transpose()
	{
		Matrix3X3 temp = Matrix3X3(*this);

		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				data[y][x] = temp.data[x][y];
	}

	// Static functions
	float Matrix3X3::Determinant(const Matrix3X3& matrix)
	{
		return (matrix.data[1][1] * matrix.data[2][2] - matrix.data[1][2] * matrix.data[2][1]) * matrix.data[0][0] +
			   (matrix.data[1][2] * matrix.data[2][0] - matrix.data[1][0] * matrix.data[2][2]) * matrix.data[0][1] +
			   (matrix.data[1][0] * matrix.data[2][1] - matrix.data[1][1] * matrix.data[2][0]) * matrix.data[0][2];
	}
	Matrix3X3 Matrix3X3::Cofactor(const Matrix3X3& matrix)
	{
		Matrix3X3 result = Matrix3X3(matrix);
		result.Cofactor();
		return result;
	}
	Matrix3X3 Matrix3X3::Transpose(const Matrix3X3& matrix)
	{
		Matrix3X3 result = Matrix3X3(matrix);
		result.Transpose();
		return result;
	}
	Matrix3X3 Matrix3X3::Invert(const Matrix3X3& matrix)
	{
		Matrix3X3 result = Matrix3X3(matrix);
		result.Invert();
		return result;
	}

	// Default matrices
	const Matrix3X3 Matrix3X3::Identity = Matrix3X3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	const Matrix3X3 Matrix3X3::Zero = Matrix3X3(0, 0, 0, 0, 0, 0, 0, 0, 0);
}