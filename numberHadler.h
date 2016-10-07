#ifndef NUMBERHADLER_H_ZJ17ABJN
#define NUMBERHADLER_H_ZJ17ABJN

#include "Number.h"
#include "TurnResult.h"
#include "auxFunctions.h"

#include <array>
#include <cmath>
#include <cstdio>  //printf
#include <cstdlib> //rand()

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
};

#endif /* end of include guard: NUMBERHADLER_H_ZJ17ABJN */
