#include "Vector2.h"

namespace Omniverse
{
	// Operator overloading
	Vector2 operator+ (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		Vector2 result;
		result.x = vectorOne.x + vectorTwo.x;
		result.y = vectorOne.y + vectorTwo.y;
		return result;
	}
	Vector2 operator- (const Vector2&  vectorOne, const Vector2& vectorTwo)
	{
		Vector2 result;
		result.x = vectorOne.x - vectorTwo.x;
		result.y = vectorOne.y - vectorTwo.y;
		return result;
	}
	Vector2 operator* (const Vector2&  vector, float number)
	{
		Vector2 result;
		result.x = vector.x * number;
		result.y = vector.y * number;
		return result;
	}
	Vector2 operator* (float number, const Vector2&  vector)
	{
		return vector * number;
	}
	float operator* (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		Vector2 result;
		result.x = vectorOne.x * vectorTwo.x;
		result.y = vectorOne.y * vectorTwo.y;
		return result.x + result.y;
	}
	Vector2 operator/ (const Vector2& vector, float number)
	{
		if (number == 0)
			perror("Divided by zero");

		Vector2 result;
		result.x = vector.x / number;
		result.y = vector.y / number;
		return result;
	}
	bool operator< (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f)) < SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f))) return true;
		else return false;
	}
	bool operator<= (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f)) <= SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f))) return true;
		else return false;
	}
	bool operator> (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f)) > SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f))) return true;
		else return false;
	}
	bool operator>= (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (SquareRoot(Power(vectorOne.x, 2.f) + Power(vectorOne.y, 2.f)) >= SquareRoot(Power(vectorTwo.x, 2.f) + Power(vectorTwo.y, 2.f))) return true;
		else return false;
	}
	bool operator== (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y) return true;
		else return false;
	}
	bool operator!= (const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		if (vectorOne.x != vectorTwo.x || vectorOne.y != vectorTwo.y) return true;
		else return false;
	}
	ostream& operator<< (ostream& outStream, const Vector2 &vector)
	{
		outStream << "(" << vector.x << ", " << vector.y << ")";
		return outStream;
	}

	Vector2& Vector2::operator+= (const Vector2& vector)
	{
		x = x + vector.x;
		y = y + vector.y;
		return *this;
	}
	Vector2& Vector2::operator-= (const Vector2& vector)
	{
		x = x - vector.x;
		y = y - vector.y;
		return *this;
	}
	Vector2& Vector2::operator*= (const float number)
	{
		x = x * number;
		y = y * number;
		return *this;
	}
	Vector2& Vector2::operator/= (const float number)
	{
		x = x / number;
		y = y / number;
		return *this;
	}
	float& Vector2::operator[] (const int index)
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;
		default: perror("Index out of bounds"); break;
		}
	}

	// Functions
	float Vector2::Lenght()
	{
		return SquareRoot(Power(x, 2.f) + Power(y, 2.f));
	}
	void Vector2::Normalize()
	{
		if (x == 0 && y == 0) 
			perror("Cannot normalize zero vector.");

		*this = *this / this->Lenght();
	}

	// Static Functions
	float Vector2::Distance(const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		return SquareRoot(Power(Absolute(vectorOne.x - vectorTwo.x), 2.f) + 
			Power(Absolute(vectorOne.y - vectorTwo.y), 2.f));
	}
	float Vector2::DotProduct(const Vector2& vectorOne, const Vector2& vectorTwo)
	{
		return (vectorOne.x * vectorTwo.x) + (vectorOne.y * vectorTwo.y);
	}
	Vector2 Vector2::Normalize(const Vector2& vector)
	{
		Vector2 result = Vector2(vector);
		result.Normalize();
		return result;
	}

	// Default vectors
	const Vector2 Vector2::Zero = Vector2(0, 0);
	const Vector2 Vector2::One = Vector2(1, 1);
	const Vector2 Vector2::Up = Vector2(0, 1);
	const Vector2 Vector2::Right = Vector2(1, 0);
	const Vector2 Vector2::Down = Vector2(0, -1);
	const Vector2 Vector2::Left = Vector2(-1, 0);
}