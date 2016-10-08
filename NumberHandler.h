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

template <unsigned short C> class NumberHandler // Rename this
{
	Number<C> number;
	bool numberGuessed = false;
	unsigned turns_count = 0;

public:
	NumberHandler(Number<C> number) : number(number) {}

	bool isGuessed() const { return numberGuessed; }
	unsigned getTurnCount() const { return turns_count; }

	TurnResult makeTurn(Number<C> number_to_check)
	{
		if (numberGuessed) {
			fputs("Number was already guessed. Why another check?", stderr);
		}

		TurnResult res = number.countBC(number_to_check);

		assert(res.bulls + res.cows <= C);

		if (res.bulls == C) {
			numberGuessed = true;
		}

		++turns_count;

		return res;
	}

	void print()
	{
		if (numberGuessed) number.print();
	}

	// If number was guessed returns a pointer to the internal number, otherwise
	// return nullptr
	Number<C>* getNumber() { return numberGuessed ? &number : nullptr; }
};

#endif /* end of include guard: NUMBERHADLER_H_ZJ17ABJN */
