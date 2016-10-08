#ifndef PLAYERGUESSER_H_CUHNAOKR
#define PLAYERGUESSER_H_CUHNAOKR

#include "TurnResult.h"
#include "Number.h"
#include "NumberHandler.h"

class PlayerGuesser
{
public:
	// Returns the number of guesses needed to find the number
	template <unsigned C> NumberHandler<C>&& guess(NumberHandler<C>&& nh)
	{
		nh.makeTurn(1234);
		nh.makeTurn(2345);
		nh.makeTurn(3456);
		nh.makeTurn(4567);
		nh.makeTurn(5678);
		return std::move(nh);
	}
};

#endif /* end of include guard: PLAYERGUESSER_H_CUHNAOKR */
