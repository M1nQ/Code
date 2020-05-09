#ifndef VECTOR3
#define VECTOR3

#include <iostream>
#include "OmniMath.h"

using namespace std;

namespace Omniverse
{
	class Vector3
	{
		// Operator overloading
		friend Vector3 operator+ (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend Vector3 operator- (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend Vector3 operator* (const Vector3& vectorOne, const float number);
		friend Vector3 operator* (const float number, const Vector3& vectorOne);
		friend float operator* (const Vector3& vector, const Vector3& vectorTwo);
		friend Vector3 operator/ (const Vector3& vector, const float number);
		friend bool operator< (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend bool operator<= (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend bool operator> (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend bool operator>= (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend bool operator== (const Vector3& vectorOne, const Vector3& vectorTwo);
		friend bool operator!= (const Vector3& vvectorOne, const Vector3& vectorTwo);
		friend ostream& operator<< (ostream& outStream, const Vector3& vector);

	public:
		// Operator overloading
		Vector3& operator+= (const Vector3& vector);
		Vector3& operator-= (const Vector3& vector);
		Vector3& operator*= (const float number);
		Vector3& operator/= (const float number);
		float& operator[] (const int index);

		// Constructor's and destructor
		inline Vector3() { x = 0; y = 0; z = 0; }
		inline Vector3(const float x, const float y, const float z) { this->x = x; this->y = y; this->z = z; }
		inline Vector3(const Vector3& vector) { x = vector.x; y = vector.y; z = vector.z; }
		inline ~Vector3() {}

		// Functions
		float Lenght();
		void Normalize();

		// Static functions
		static float Distance(const Vector3& vectorOne, const Vector3& vectorTwo);
		static float DotProduct(const Vector3& vectorOne, const Vector3& vectorTwo);
		static Vector3 CrossProduct(const Vector3& vectorOne, const Vector3& vectorTwo);
		static Vector3 Normalize(const Vector3& vector);

		// Variables
		float x, y, z;

		// Default vectors
		static const Vector3 Zero;
		static const Vector3 One;
		static const Vector3 Up;
		static const Vector3 Right;
		static const Vector3 Down;
		static const Vector3 Left;
		static const Vector3 Forward;
		static const Vector3 Backward;
	};
}

#endif VECTOR3