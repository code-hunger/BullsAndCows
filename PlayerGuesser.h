#ifndef PLAYERGUESSER_H_CUHNAOKR
#define PLAYERGUESSER_H_CUHNAOKR

#include "TurnResult.h"
#include "numberHadler.hpp"

class PlayerGuesser
{
public:
	PlayerGuesser();

	// Returns the number of guesses needed to find the number
	unsigned guess(numberHandler);

	virtual ~PlayerGuesser();

private:
	TurnResult queryNumber(numberHandler) const;
};

#endif /* end of include guard: PLAYERGUESSER_H_CUHNAOKR */
