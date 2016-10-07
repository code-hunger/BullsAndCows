#ifndef PLAYERGUESSER_H_CUHNAOKR
#define PLAYERGUESSER_H_CUHNAOKR

#include "TurnResult.h"
#include "numberHadler.h"

class PlayerGuesser
{
public:
	// Returns the number of guesses needed to find the number
	template <unsigned C> unsigned guess(numberHandler<C>) { return 69; };
};

#endif /* end of include guard: PLAYERGUESSER_H_CUHNAOKR */
