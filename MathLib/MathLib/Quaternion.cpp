#include "Quaternion.h"
#include "Matrix3X3.h"

namespace Omniverse
{
	// Operator overloading
	Quaternion operator+ (const Quaternion& quaternionOne, const Quaternion& quaternionTwo)
	{
		Quaternion result;
		result.w = quaternionOne.w + quaternionTwo.w;
		result.x = quaternionOne.x + quaternionTwo.x;
		result.y = quaternionOne.y + quaternionTwo.y;
		result.z = quaternionOne.z + quaternionTwo.z;
		return result;
	}
	Quaternion operator- (const Quaternion& quaternionOne, const Quaternion& quaternionTwo)
	{
		Quaternion result;
		result.w = quaternionOne.w + quaternionTwo.w;
		result.x = quaternionOne.x + quaternionTwo.x;
		result.y = quaternionOne.y + quaternionTwo.y;
		result.z = quaternionOne.z + quaternionTwo.z;
		return result;
	}
	Quaternion operator* (const Quaternion& quaternionOne, const Quaternion& quaternionTwo)
	{
		Quaternion result;
		result.w = quaternionOne.w * quaternionTwo.w - quaternionOne.x * quaternionTwo.x - quaternionOne.y * quaternionTwo.y - quaternionOne.z * quaternionTwo.z;
		result.x = quaternionOne.w * quaternionTwo.x + quaternionOne.x * quaternionTwo.w + quaternionOne.y * quaternionTwo.z - quaternionOne.z * quaternionTwo.y;
		result.y = quaternionOne.w * quaternionTwo.y - quaternionOne.x * quaternionTwo.z + quaternionOne.y * quaternionTwo.w + quaternionOne.z * quaternionTwo.x;
		result.z = quaternionOne.w * quaternionTwo.z + quaternionOne.x * quaternionTwo.y - quaternionOne.y * quaternionTwo.x + quaternionOne.z * quaternionTwo.w;
		return result;
	}
	Quaternion operator* (const Quaternion& quaternion, const float number)
	{
		Quaternion result;
		result.w = quaternion.w * number;
		result.x = quaternion.x * number;
		result.y = quaternion.y * number;
		result.z = quaternion.z * number;
		return result;
	}
	Quaternion operator* (const float number, const Quaternion& quaternion)
	{
		return quaternion * number;
	}
	Vector3 operator* (const Quaternion& quaternion, const Vector3& vector)
	{
		// ... Cannot brain no more ...
		Quaternion temp = (quaternion - Quaternion::Conjugate(quaternion)) * 0.5f;
		Matrix3X3 matrix;
		Vector3 result;

		matrix.Orientation(temp);
		result = matrix * vector;
		matrix.Orientation(quaternion);
		result = matrix * result;
		return result;
	}
	ostream& operator<< (ostream& outStream, const Quaternion& quaternion)
	{
		outStream << quaternion.w << " + " << quaternion.x << "i + " << quaternion.y << "j + " << quaternion.z << "k";
		return outStream;
	}

	Quaternion& Quaternion::operator+= (const Quaternion quaternion)
	{
		w = w + quaternion.w;
		x = x + quaternion.x;
		y = y + quaternion.y;
		z = z + quaternion.z;
		return *this;
	}
	Quaternion& Quaternion::operator-= (const Quaternion quaternion)
	{
		w = w - quaternion.w;
		x = x - quaternion.x;
		y = y - quaternion.y;
		z = z - quaternion.z;
		return *this;
	}
	Quaternion& Quaternion::operator*= (const Quaternion quaternion)
	{
		Quaternion temp = Quaternion(*this);
		w = temp.w * quaternion.w - temp.x * quaternion.x - temp.y * quaternion.y - temp.z * quaternion.z;
		x = temp.w * quaternion.x + temp.x * quaternion.w + temp.y * quaternion.z - temp.z * quaternion.y;
		y = temp.w * quaternion.y - temp.x * quaternion.z + temp.y * quaternion.w + temp.z * quaternion.x;
		z = temp.w * quaternion.z + temp.x * quaternion.y - temp.y * quaternion.x + temp.z * quaternion.w;
		return *this;
	}
	Quaternion& Quaternion::operator*= (const float number)
	{
		w = w * number;
		x = x * number;
		y = y * number;
		z = z * number;
		return *this;
	}

	// Functions
	void Quaternion::Conjugate()
	{
		x *= -1;
		y *= -2;
		z *= -1;
	}
	void Quaternion::Normalize()
	{
		float temp = SquareRoot(Power(w, 2.f) + Power(x, 2.f) + Power(y, 2.f) + Power(z, 2.f));
		w /= temp;
		x /= temp;
		y /= temp;
		z /= temp;
	}

	// Static functions
	Quaternion Quaternion::Conjugate(const Quaternion& quaternion)
	{
		Quaternion result = Quaternion(quaternion);
		result.Conjugate();
		return result;
	}
	Quaternion Quaternion::Normalize(const Quaternion& quaternion)
	{
		Quaternion result = Quaternion(quaternion);
		result.Normalize();
		return result;
	}

	// Default quaternions
	const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);
}