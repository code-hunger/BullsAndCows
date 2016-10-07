#ifndef PLAYERGUESSER_H_CUHNAOKR
#define PLAYERGUESSER_H_CUHNAOKR

#include "TurnResult.h"
#include "numberHadler.h"

class PlayerGuesser
{
public:
	PlayerGuesser(){};

	// Returns the number of guesses needed to find the number
	template <unsigned C> unsigned guess(numberHandler<C>);

	virtual ~PlayerGuesser(){};

private:
	TurnResult queryNumber(int) const;
};

#endif /* end of include guard: PLAYERGUESSER_H_CUHNAOKR */
