#include <cstdlib>   //rand()
#include <cstdio>    //printf

enum BCTurnResult{none = 0, cow = 1, bull = 2};

const int MAXDIGITS = 4;/// Maximum digits should be 9!

class bullsAndCows
{
public:
	int number;             /// The number which we'll be guessing
	int digits[MAXDIGITS];  /// The digits of the number, from left to right.
	BCTurnResult turnResults[MAXDIGITS];

    void clearNumber()
    {
        int i;
        for(i=0;i<MAXDIGITS;i++){
            digits[i] = -1;
        }
    }

	void generateNumber()
	{
	    clearNumber();
		int i,j;
		for(i=0; i<MAXDIGITS; i++){
            digits[i] = rand()%9;
            for(j=0; j<i; j++){

            }
		}
	}

	void printNumber(bool printSpaces = 1)
	{
	    ///@param printType  Whether to print with(1) or without(0) spaces between digits.
		if (printSpaces) {
			printf("%i %i %i %i", digits[0], digits[1], digits[2],
			       digits[3]);
		} else {
			cout << number;
		}
	}

	void generateTurnResults(int )

	int playerFunction(bool verbose = 1){
	///@brief A function that plays the game once. It is supposed to be very efficient.
	///@param verbose  Whether each turn will be displayed or not. This includes played numbers, cows & bulls, etcetera.
	}

};
