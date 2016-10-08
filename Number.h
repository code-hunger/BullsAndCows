#ifndef NUMBER_H_J3V6CAR8
#define NUMBER_H_J3V6CAR8

#include "auxFunctions.h"
#include <cmath>
#include <random>


template <unsigned C> struct Number
{
	short digits[C];

	Number()
	{
		clearArray(digits, -1, C);
		int i, j;
		for (i = 0; i < C; i++) {
			digits[i] = generateDigit();
			while(simpleSearch(digits,digits[i],i) != -1){
                digits[i]++;
                clampInv(0,C,&digits[i]);
			}
		}
	}

	static short generateDigit()
    {
        return rand() % C;
    }

	int getNumber()
	{
		int result, i = C, i10 = pow(10, C);
		while (i10 /= 10 && --i) {
			result += digits[i] * i10;
		}
		return result;
	}

	void printDigits(int digitPool[C],bool printSpaces = true)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		int i;
		for(i=0;i<C;i++){
            printf("%i",digitPool[digits[i]]);
            if(i<(C-1) && printSpaces){
                printf(" ");
            }
		}
	}
};

#endif /* end of include guard: NUMBER_H_J3V6CAR8 */
