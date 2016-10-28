#ifndef NUMBER_H_J3V6CAR8
#define NUMBER_H_J3V6CAR8

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <random>

#include "TurnResult.h"

template <unsigned short C, unsigned short D = 9> class Number
{
	std::array<unsigned short, C> digits{};
	std::array<unsigned short, D> digitPool{};

	short generateDigit() { return rand() % C; }

public:
	Number()
	{
		clearArray(digits, -1, C);
		for (int i = 0; i < C; i++) {
			digits[i] = generateDigit();
			while (std::find(digits, digits[i]) != digits[i]) {
				digits[i]++;
				clampInv(0, C, &digits[i]);
			}
		}
	}

	Number(unsigned n)
	{
		assert(pow(10, C) > n && pow(10, C) < n * 10);

		for (unsigned i = 0, pow10 = 1; i < C; ++i, pow10 *= 10) {
			digits[C - i - 1] = static_cast<short unsigned>(n / pow10 % 10);
		}
	}

	auto& operator[](unsigned i) { return digits[i]; }

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

	TurnResult countBC(Number<C> guessNumber)
	{
		unsigned short bulls = 0, cows = 0;
		for (unsigned short i = 0; i < C; i++) {
			if (guessNumber.digits[i] == this->digits[i]) {
				bulls++;
			} else {
				for (unsigned j = 0; j < C; j++) {
					if (guessNumber.digits[i] == this->digits[i]) {
						cows++;
						break;
					}
				}
			}
		}

		return {bulls, cows};
	}

	void print(bool printSpaces = true)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		for (unsigned i = 0; i < C; i++) {
			printf("%i", digitPool[digits[i]]);
			if (i < (C - 1) && printSpaces) {
				printf(" ");
			}
		}
	}
};

#endif /* end of include guard: NUMBER_H_J3V6CAR8 */
