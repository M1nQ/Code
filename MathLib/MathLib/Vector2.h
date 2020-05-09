#ifndef VECTOR2
#define VECTOR2

#include <iostream>
#include "OmniMath.h"

using namespace std;

namespace Omniverse
{
	class Vector2
	{
		// Operator overloading
		friend Vector2 operator+ (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend Vector2 operator- (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend Vector2 operator* (const Vector2& vectorOne, const float number);
		friend Vector2 operator* (const float number, const Vector2& vectorOne);
		friend float operator* (const Vector2& vector, const Vector2& vectorTwo);
		friend Vector2 operator/ (const Vector2& vector, const float number);
		friend bool operator< (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend bool operator<= (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend bool operator> (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend bool operator>= (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend bool operator== (const Vector2& vectorOne, const Vector2& vectorTwo);
		friend bool operator!= (const Vector2& vvectorOne, const Vector2& vectorTwo);
		friend ostream& operator<< (ostream& outStream, const Vector2& vector);

	public:
		// Operator overloading
		Vector2& operator+= (const Vector2& vector);
		Vector2& operator-= (const Vector2& vector);
		Vector2& operator*= (const float number);
		Vector2& operator/= (const float number);
		float& operator[] (const int row);

		// Constructor's and destructor
		inline Vector2 () { x = 0; y = 0; }
		inline Vector2 (const float x, const float y) { this->x = x; this->y = y; }
		inline Vector2 (const Vector2& vector) { x = vector.x; y = vector.y; }
		inline ~Vector2() {}

		// Functions
		float Lenght();
		void Normalize();

		// Static functions
		static float Distance(const Vector2& vectorOne, const Vector2& vectorTwo);
		static float DotProduct(const Vector2& vectorOne, const Vector2& vectorTwo);
		static Vector2 Normalize(const Vector2& vector);

		// Variables
		float x, y;

		// Default vectors
		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Up;
		static const Vector2 Right;
		static const Vector2 Down;
		static const Vector2 Left;
	};
}

#endif VECTOR2