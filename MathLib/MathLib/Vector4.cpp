#include "Vector4.h"

namespace Omniverse
{
	// Operator overloading
	Vector4 operator+ (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		Vector4 result;
		result.x = vectorOne.x + vectorTwo.x;
		result.y = vectorOne.y + vectorTwo.y;
		result.z = vectorOne.z + vectorTwo.z;
		result.w = vectorOne.w + vectorTwo.w;
		return result;
	}
	Vector4 operator- (const Vector4&  vectorOne, const Vector4& vectorTwo)
	{
		Vector4 result;
		result.x = vectorOne.x - vectorTwo.x;
		result.y = vectorOne.y - vectorTwo.y;
		result.z = vectorOne.z - vectorTwo.z;
		result.w = vectorOne.w - vectorTwo.w;
		return result;
	}
	Vector4 operator* (const Vector4&  vector, float number)
	{
		Vector4 result;
		result.x = vector.x * number;
		result.y = vector.y * number;
		result.z = vector.z * number;
		result.w = vector.w * number;
		return result;
	}
	Vector4 operator* (float number, const Vector4&  vector)
	{
		return vector * number;
	}
	float operator* (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		Vector4 result;
		result.x = vectorOne.x * vectorTwo.x;
		result.y = vectorOne.y * vectorTwo.y;
		result.z = vectorOne.z * vectorTwo.z;
		result.w = vectorOne.w * vectorTwo.w;
		return result.x + result.y + result.z + result.w;
	}
	Vector4 operator/ (const Vector4& vector, float number)
	{
		if (number == 0)
			perror("Divided by zero");

		Vector4 result;
		result.x = vector.x / number;
		result.y = vector.y / number;
		result.z = vector.z / number;
		result.w = vector.w / number;
		return result;
	}
	bool operator< (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f) + Power(vectorOne.w, 2.f)) <
			SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f) + Power(vectorTwo.w, 2.f))) return true;
		else return false;
	}
	bool operator<= (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f) + Power(vectorOne.w, 2.f)) <=
			SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f) + Power(vectorTwo.w, 2.f))) return true;
		else return false;
	}
	bool operator> (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f) + Power(vectorOne.w, 2.f)) >
			SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f) + Power(vectorTwo.w, 2.f))) return true;
		else return false;
	}
	bool operator>= (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f) + Power(vectorOne.z, 2.f) + Power(vectorOne.w, 2.f)) >=
			SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f) + Power(vectorTwo.z, 2.f) + Power(vectorTwo.w, 2.f))) return true;
		else return false;
	}
	bool operator== (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y && vectorOne.z == vectorTwo.z && vectorOne.w == vectorTwo.w) return true;
		else return false;
	}
	bool operator!= (const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		if (vectorOne.x != vectorTwo.x || vectorOne.y != vectorTwo.y || vectorOne.z != vectorTwo.z || vectorOne.w != vectorTwo.w) return true;
		else return false;
	}
	ostream& operator<< (ostream& outStream, const Vector4& vector)
	{
		outStream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return outStream;
	}

	Vector4& Vector4::operator+= (const Vector4& vector)
	{
		x = x + vector.x;
		y = y + vector.y;
		z = z + vector.z;
		w = w + vector.w;
		return *this;
	}
	Vector4& Vector4::operator-= (const Vector4& vector)
	{
		x = x - vector.x;
		y = y - vector.y;
		z = z - vector.z;
		w = w - vector.w;
		return *this;
	}
	Vector4& Vector4::operator*= (const float number)
	{
		x = x * number;
		y = y * number;
		z = z * number;
		w = w * number;
		return *this;
	}
	Vector4& Vector4::operator/= (const float number)
	{
		x = x / number;
		y = y / number;
		z = z / number;
		w = w / number;
		return *this;
	}
	float& Vector4::operator[] (const int index)
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		default: perror("Index out of bounds"); break;
		}
	}

	// Functions
	float Vector4::Lenght()
	{
		return SquareRoot(Power(x, 2.f) + Power(y, 2.f) + Power(z, 2.f) + Power(w, 2.f));
	}
	void Vector4::Normalize()
	{
		if (x == 0 && y == 0 && z == 0 && w == 0)
			perror("Cannot normalize zero vector.");

		*this = *this / this->Lenght();
	}

	// Static Functions
	float Vector4::Distance(const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		return SquareRoot(Power(Absolute(vectorOne.x - vectorTwo.x), 2.f) +
			Power(Absolute(vectorOne.y - vectorTwo.y), 2.f) +
			Power(Absolute(vectorOne.z - vectorTwo.z), 2.f) +
			Power(Absolute(vectorOne.w - vectorTwo.w), 2.f));
	}
	float Vector4::DotProduct(const Vector4& vectorOne, const Vector4& vectorTwo)
	{
		return (vectorOne.x * vectorTwo.x) + (vectorOne.y * vectorTwo.y) + (vectorOne.z * vectorTwo.z) + (vectorOne.w * vectorTwo.w);
	}
	Vector4 Vector4::Normalize(const Vector4& vector)
	{
		Vector4 result = Vector4(vector);
		result.Normalize();
		return result;
	}

	// Default vectors
	const Vector4 Vector4::Zero = Vector4(0, 0, 0, 0);
	const Vector4 Vector4::One = Vector4(1, 1, 1, 1);
}