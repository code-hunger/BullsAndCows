#ifndef PLAYERGUESSER_H_CUHNAOKR
#define PLAYERGUESSER_H_CUHNAOKR

#include "TurnResult.h"
#include "Number.h"
#include "numberHadler.h"

class PlayerGuesser
{
public:
	// Returns the number of guesses needed to find the number
	template <unsigned C> numberHandler<C>&& guess(numberHandler<C>&& nh)
	{
		return std::move(nh);
	};
};

#endif /* end of include guard: PLAYERGUESSER_H_CUHNAOKR */
