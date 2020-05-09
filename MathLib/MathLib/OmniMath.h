#ifndef OMNIMATH
#define OMNIMATH

#include <iostream>

using namespace std;

namespace Omniverse
{
	inline float Absolute(float number)
	{
		if (number < 0) return number * -1;
		else return number;
	}
	inline float Power(float number, float power)
	{
		float temp = number;

		if (power > 0)
		{
			for (int i = 1; i < power; ++i)
				number *= temp;

			return number;
		}
		else if (power < 0)
		{
			for (int i = 1; i < Absolute(power); ++i)
				number *= temp;

			return (1 / Absolute(number));
		}
		else
			return 1;
	}
	inline float SquareRoot(float number, float tolerance = 0.0000001f, bool returnNegative = false)
	{
		if (number >= 0)
		{
			if (number == 0) return number;
			float i = number, j = 0;

			while (true)
			{
				j = 0.5f * (i + number / i);
				if (Absolute(i - j) < tolerance) break;
				i = j;
			}

			if (returnNegative) return j * -1;
			else return j;
		}
		
		perror("Cannot take squareroot from a negavie number.");
		return number;
	}
}

#endif OMNIMATH