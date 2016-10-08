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
	Number<C> number;
	bool numberGuessed = false;
	unsigned turns_count = 0;
	int digitPoolSize = 9, digitPool[10];

public:
	numberHandler(Number<C> number) : number(number) {}

	bool isGuessed() const { return numberGuessed; }
	unsigned getTurnCount() const { return turns_count; }

	TurnResult makeTurn(Number<C> number_to_check)
	{
		if (numberGuessed) {
			fputs("Number was already guessed. Why another check?", stderr);
		}

		unsigned short bulls = 0, cows = 0;
		for (unsigned i = 0; i < C; i++) {
			if (number_to_check[i] == number[i]) {
				bulls++;
			} else {
				for (unsigned j = 0; j < C; j++) {
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

		++turns_count;

		return {bulls, cows};
	}

	void setDigitPool(int digitCount, int digits[])
	{
		digitPoolSize = digitCount;
		digitPool = digits;
	}

	void print(){
        number.printDigits(digitPool);
	}

	// If number was guessed returns a pointer to the internal number, otherwise
	// return nullptr
	Number<C>* getNumber() { return numberGuessed ? &number : nullptr; }
};

#endif /* end of include guard: NUMBERHADLER_H_ZJ17ABJN */
