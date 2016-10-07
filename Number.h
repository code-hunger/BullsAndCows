#ifndef NUMBER_H_J3V6CAR8
#define NUMBER_H_J3V6CAR8

#include <cmath>

template <unsigned C> struct Number
{
	short digits[C];
	int getCopyOfNumber()
	{
		int result, i = C, i10 = pow(10, C);
		while (i10 /= 10 && --i) {
			result += digits[i] * i10;
		}
		return result;
	}
};

#endif /* end of include guard: NUMBER_H_J3V6CAR8 */
