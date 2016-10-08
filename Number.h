#ifndef NUMBER_H_J3V6CAR8
#define NUMBER_H_J3V6CAR8

#include "auxFunctions.h"
#include <array>
#include <cassert>
#include <cmath>
#include <random>

template <unsigned C, unsigned short D = 9> struct Number
{
	unsigned short digits[C]{};
	std::array<unsigned short, D> digitPool;

	Number()
	{
		clearArray(digits, -1, C);
		int i, j;
		for (i = 0; i < C; i++) {
			digits[i] = generateDigit();
			while (simpleSearch(digits, digits[i], i) != -1) {
				digits[i]++;
				clampInv(0, C, &digits[i]);
			}
		}
	}

	Number(int n)
	{
		assert(pow(10, C) > n && pow(10, C) < n * 10);
		int pow10 = 1, i = 0;
		while (i < C) {
			digits[C - i - 1] = (n / pow10) % 10;
			pow10 *= 10;
			i++;
		}
	}

	auto& operator[](unsigned i) { return digits[i]; }

	static short generateDigit() { return rand() % C; }

	void setDigitPool(std::array<short, C> digitPool)
	{
		this->digitPool = digitPool;
	}

	int getNumber()
	{
		int result, i = C, i10 = pow(10, C);
		while (i10 /= 10 && --i) {
			result += digits[i] * i10;
		}
		return result;
	}

	void print(bool printSpaces = true)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		int i;
		for (i = 0; i < C; i++) {
			printf("%i", digitPool[digits[i]]);
			if (i < (C - 1) && printSpaces) {
				printf(" ");
			}
		}
	}
};

#endif /* end of include guard: NUMBER_H_J3V6CAR8 */
