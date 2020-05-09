#ifndef VECTOR4
#define VECTOR4

#include <iostream>
#include "OmniMath.h"

using namespace std;

namespace Omniverse
{
	class Vector4
	{
		// Operator overloading
		friend Vector4 operator- (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend Vector4 operator+ (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend Vector4 operator* (const Vector4& vectorOne, const float number);
		friend Vector4 operator* (const float number, const Vector4& vectorOne);
		friend float operator* (const Vector4& vector, const Vector4& vectorTwo);
		friend Vector4 operator/ (const Vector4& vector, const float number);
		friend bool operator< (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend bool operator<= (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend bool operator> (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend bool operator>= (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend bool operator== (const Vector4& vectorOne, const Vector4& vectorTwo);
		friend bool operator!= (const Vector4& vvectorOne, const Vector4& vectorTwo);
		friend ostream& operator<< (ostream& outStream, const Vector4& vector);

	public:
		// Operator overloading
		Vector4& operator+= (const Vector4& vector);
		Vector4& operator-= (const Vector4& vector);
		Vector4& operator*= (const float number);
		Vector4& operator/= (const float number);
		float& operator[] (const int index);

		// Constructor's and destructor
		inline Vector4() { x = 0; y = 0; z = 0; }
		inline Vector4(const float x, const float y, const float z, const float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
		inline Vector4(const Vector4& vector) { x = vector.x; y = vector.y; z = vector.z; w = vector.w; }
		inline ~Vector4() {}

		// Functions
		float Lenght();
		void Normalize();

		// Static functions
		static float Distance(const Vector4& vectorOne, const Vector4& vectorTwo);
		static float DotProduct(const Vector4& vectorOne, const Vector4& vectorTwo);
		static Vector4 Normalize(const Vector4& vector);

		// Variables
		float x, y, z, w;

		// Default vectors
		static const Vector4 Zero;
		static const Vector4 One;
	};
}

#endif VECTOR4