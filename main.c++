#include <cstdio>

#include "Number.h"
#include "PlayerGuesser.h"

int main()
{
	PlayerGuesser player;
	auto nh = player.guess<4>({5678});
	if (nh.isGuessed()) {
		nh.print();
		printf("\nGuessed in %d turns.\n", nh.getTurnCount());
	} else {
		puts("Couldn't guess it!");
	}
	return 0;
}

