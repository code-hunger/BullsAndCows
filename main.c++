#include <iostream>

#include "PlayerGuesser.h"
#include "Number.h"

// @TODO: Include numberHandler

using std::cout;

int main()
{
	PlayerGuesser player;
	auto checks_number = player.guess<4>({Number<4>::generate()});
	cout << checks_number << '\n';
	return 0;
}
