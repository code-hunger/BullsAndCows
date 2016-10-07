#ifndef NUMBER_H_J3V6CAR8
#define NUMBER_H_J3V6CAR8

#include "auxFunctions.h"
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

	static void generateDigit(bool digType = 1)
	{
		///@param digType  Whether to return a digit directly(0) or its index in
		/// the digitPool(1).
	}

	static Number generate()
	{
		bool occupied[10];
		int digits[C];
		clearArray(digits, -1, C);
		clearArray(occupied, false, 10);
		int i, j;
		for (i = 0; i < C; i++) {
			digits[i] = generateDigit();
			occupied[digits[i]] = true;
			for (j = 0; j < 10; j++) {
				if (occupied[digits[i]]) digits[i]++;
				clampInv(1, 9, &digits[i]);
			}
		}
	}

	void printNumber(bool printSpaces = 1)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		if (printSpaces) {
			printf("%i %i %i %i", digits[0], digits[1], digits[2], digits[3]);
		} else {
			printf("%i", getCopyOfNumber());
		}
	}
};

#endif /* end of include guard: NUMBER_H_J3V6CAR8 */
