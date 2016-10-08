#include <cstdio>

#include "Number.h"
#include "PlayerGuesser.h"

int main()
{
	PlayerGuesser player;
	auto nh = player.guess<4>({{}});
	if (nh.isGuessed()) {
		nh.getNumber()->print();
		printf("\nGuessed in %d turns.\n", game_result.second);
	} else {
		puts("Couldn't guess it!");
	}
	return 0;
}
