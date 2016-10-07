#include "TurnResult.h"
#include <cstdio>  //printf
#include <cstdlib> //rand()
#include <array>
#include <cmath>

template <unsigned C> class numberHandler // Rename this
{
public:
	TurnResult makeTurn(Number<C> number_to_check)
	{
		int i, j;
		TurnResult res;
		for (i = 0; i < C; i++) {
			if (number_to_check[i] == number.digits[i]) {
				res.bulls++;
			} else {
				for (j = 0; j < C; j++) {
					if (number_to_check[i] == number.digits[j]) {
						res.cows++;
						break;
					}
				}
			}
		}
		return res;
	}

	void setDigitPool(int digitCount, int digits[])
	{
		digitPoolSize = digitCount;
		digitPool = digits;
	}

private:
	// Rename the following two variables!
	Number<C> number; /// The number which we'll be guessing
	int digitPoolSize = 9, digitPool[10];

	void generateDigit(bool digType = 1)
	{
		///@param digType  Whether to return a digit directly(0) or its index in
		/// the digitPool(1).
	}

	void generateNumber()
	{
		bool occupied[10];
		clearArray(number.digits, -1, C);
		clearArray(occupied, false, 10);
		int i, j;
		for (i = 0; i < C; i++) {
			number.digits[i] = generateDigit();
			occupied[number.digits[i]] = true;
			for (j = 0; j < 10; j++) {
				if (occupied[number.digits[i]]) number.digits[i]++;
				clampInv(1, 9, &number.digits[i]);
			}
		}
	}

	void printNumber(bool printSpaces = 1)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		if (printSpaces) {
			printf("%i %i %i %i", number.digits[0], number.digits[1],
			       number.digits[2], number.digits[3]);
		} else {
			printf("%i", number);
		}
	}
};

