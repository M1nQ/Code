#include "Vector3.h"

namespace Omniverse
{
	// Operator overloading
	Vector3 operator+ (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		Vector3 result;
		result.x = vectorOne.x + vectorTwo.x;
		result.y = vectorOne.y + vectorTwo.y;
		result.z = vectorOne.z + vectorTwo.z;
		return result;
	}
	Vector3 operator- (const Vector3&  vectorOne, const Vector3& vectorTwo)
	{
		Vector3 result;
		result.x = vectorOne.x - vectorTwo.x;
		result.y = vectorOne.y - vectorTwo.y;
		result.z = vectorOne.z - vectorTwo.z;
		return result;
	}
	Vector3 operator* (const Vector3&  vector, float number)
	{
		Vector3 result;
		result.x = vector.x * number;
		result.y = vector.y * number;
		result.z = vector.z * number;
		return result;
	}
	Vector3 operator* (float number, const Vector3&  vector)
	{
		return vector * number;
	}
	float operator* (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		Vector3 result;
		result.x = vectorOne.x * vectorTwo.x;
		result.y = vectorOne.y * vectorTwo.y;
		result.z = vectorOne.z * vectorTwo.z;
		return result.x + result.y + result.z;
	}
	Vector3 operator/ (const Vector3& vector, float number)
	{
		if (number == 0)
			perror("Divided by zero");

		Vector3 result;
		result.x = vector.x / number;
		result.y = vector.y / number;
		result.z = vector.z / number;
		return result;
	}
	bool operator< (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f)) < SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f))) return true;
		else return false;
	}
	bool operator<= (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f)) <= SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f))) return true;
		else return false;
	}
	bool operator> (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f)) > SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f))) return true;
		else return false;
	}
	bool operator>= (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f)) >= SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f))) return true;
		else return false;
	}
	bool operator== (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y && vectorOne.z == vectorTwo.z) return true;
		else return false;
	}
	bool operator!= (const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		if (vectorOne.x != vectorTwo.x || vectorOne.y != vectorTwo.y || vectorOne.z != vectorTwo.z) return true;
		else return false;
	}
	ostream& operator<< (ostream& outStream, const Vector3 &vector)
	{
		outStream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return outStream;
	}

	Vector3& Vector3::operator+= (const Vector3& vector)
	{
		x = x + vector.x;
		y = y + vector.y;
		z = z + vector.z;
		return *this;
	}
	Vector3& Vector3::operator-= (const Vector3& vector)
	{
		x = x - vector.x;
		y = y - vector.y;
		z = z - vector.z;
		return *this;
	}
	Vector3& Vector3::operator*= (const float number)
	{
		x = x * number;
		y = y * number;
		z = z * number;
		return *this;
	}
	Vector3& Vector3::operator/= (const float number)
	{
		x = x / number;
		y = y / number;
		z = z / number;
		return *this;
	}
	float& Vector3::operator[] (const int index)
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		default: perror("Index out of bounds"); break;
		}
	}

	// Functions
	float Vector3::Lenght()
	{
		return SquareRoot(Power(x, 2.f) + Power(y, 2.f) + Power(z, 2.f));
	}
	void Vector3::Normalize()
	{
		if (x == 0 && y == 0 && z == 0)
			perror("Cannot normalize zero vector.");

		*this = *this / this->Lenght();
	}

	// Static Functions
	float Vector3::Distance(const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		return SquareRoot(Power(Absolute(vectorOne.x - vectorTwo.x), 2.f) + 
			Power(Absolute(vectorOne.y - vectorTwo.y), 2.f) + 
			Power(Absolute(vectorOne.z - vectorTwo.z), 2.f));
	}
	float Vector3::DotProduct(const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		return (vectorOne.x * vectorTwo.x) + (vectorOne.y * vectorTwo.y) + (vectorOne.z * vectorTwo.z);
	}
	Vector3 Vector3::CrossProduct(const Vector3& vectorOne, const Vector3& vectorTwo)
	{
		Vector3 result;
		result.x = vectorOne.y * vectorTwo.z - vectorTwo.y * vectorOne.z;
		result.y = vectorTwo.x * vectorOne.z - vectorOne.x * vectorTwo.z;
		result.z = vectorOne.x * vectorTwo.y - vectorOne.y * vectorTwo.x;
		return result;
	}
	Vector3 Vector3::Normalize(const Vector3& vector)
	{
		Vector3 result = Vector3(vector);
		result.Normalize();
		return result;
	}

	// Default vectors
	const Vector3 Vector3::Zero = Vector3(0, 0, 0);
	const Vector3 Vector3::One = Vector3(1, 1, 1);
	const Vector3 Vector3::Up = Vector3(0, 1, 0);
	const Vector3 Vector3::Right = Vector3(1, 0, 0);
	const Vector3 Vector3::Down = Vector3(0, -1, 0);
	const Vector3 Vector3::Left = Vector3(-1, 0, 0);
	const Vector3 Vector3::Forward = Vector3(0, 0, 1);
	const Vector3 Vector3::Backward = Vector3(0, 0, -1);
}