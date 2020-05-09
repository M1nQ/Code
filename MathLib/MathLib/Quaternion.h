#ifndef QUATERNION
#define QUATERNION

#include "Vector3.h"

namespace Omniverse
{
	class Quaternion
	{
		// Operator overloading
		friend Quaternion operator+ (const Quaternion& quaternionOne, const Quaternion& quaternionTwo);
		friend Quaternion operator- (const Quaternion& quaternionOne, const Quaternion& quaternionTwo);
		friend Quaternion operator* (const Quaternion& quaternionOne, const Quaternion& quaternionTwo);
		friend Quaternion operator* (const Quaternion& quaternion, const float number);
		friend Quaternion operator* (const float number, const Quaternion& quaternion);
		friend Vector3 operator* (const Quaternion& quaternion, const Vector3& vector);
		friend ostream& operator<< (ostream& outStream, const Quaternion& quaternion);

	public:
		// Operator overloading
		Quaternion& operator+= (const Quaternion quaternion);
		Quaternion& operator-= (const Quaternion quaternion);
		Quaternion& operator*= (const Quaternion quaternion);
		Quaternion& operator*= (const float number);

		// Constructors and destructor
		inline Quaternion() { w = 0; x = 0; y = 0; z = 0; }
		inline Quaternion(const Quaternion& quaternion) { w = quaternion.w; x = quaternion.x; y = quaternion.y; z = quaternion.z; }
		inline Quaternion(const float w, const float x, const float y, const float z) { this->w = w; this->x = x; this->y = y; this->z = z; }
		inline ~Quaternion() {}

		// Functions
		void Conjugate();
		void Normalize();

		// Static functions
		static Quaternion Conjugate(const Quaternion& quaternion);
		static Quaternion Normalize(const Quaternion& quaternion);

		// Variables
		float w, x, y, z;

		// Default quaternions
		const static Quaternion Identity;
	};
}

#endif QUATERNION