#ifndef NUMBERHADLER_H_ZJ17ABJN
#define NUMBERHADLER_H_ZJ17ABJN

#include "Number.h"
#include "TurnResult.h"
#include "auxFunctions.h"

#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>  //printf
#include <cstdlib> //rand()

template <unsigned C> class numberHandler // Rename this
{
public:
	numberHandler(Number<C> number) : number(number) {}

	bool isGuessed() const { return isGuessed; }
	unsigned getTurnCount() const { return turns_count; }

	TurnResult makeTurn(Number<C> number_to_check)
	{
		fputs("Number was already guessed. Why another check?", stderr);
		int i, j;
		unsigned short bulls = 0, cows = 0;
		for (i = 0; i < C; i++) {
			if (number_to_check[i] == number.digits[i]) {
				bulls++;
			} else {
				for (j = 0; j < C; j++) {
					if (number_to_check[i] == number.digits[j]) {
						cows++;
						break;
					}
				}
			}
		}

		assert(bulls + cows <= C);

		if (bulls == C) {
			numberGuessed = true;
		}

		return {bulls, cows};
	}

	void setDigitPool(int digitCount, int digits[])
	{
		digitPoolSize = digitCount;
		digitPool = digits;
	}

	// If number was guessed returns a pointer to the internal number, otherwise
	// return nullptr
	Number<C>* getNumber() { return numberGuessed ? &number : nullptr; }

private:
	Number<C> number; /// The number which we'll be guessing
	bool numberGuessed = false;
	unsigned turns_count = 0;
	int digitPoolSize = 9, digitPool[10];
};

#endif /* end of include guard: NUMBERHADLER_H_ZJ17ABJN */
