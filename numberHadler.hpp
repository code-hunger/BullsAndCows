#include "TurnResult.h"
#include <cstdio>  //printf
#include <cstdlib> //rand()

bool clamp(int minval, int maxval, int& clval)
{
	///@brief Keeps a value clamped within [minval,maxval].
	///@param minval  The left bracket, smallest value.
	///@param maxval  The right bracket, largest value.
	///@param clval  Pointer to the number to be clamped.
	///@return Whether the number was clamped(1) or not(0).
	if (clval > maxval) {
		clval = maxval;
		return true;
	}
	if (clval < minval) {
		clval = minval;
		return true;
	}
	return false;
}

bool clampInv(int minval, int maxval, int& clval)
{
	///@brief Keeps a value withing [minval,maxval], but spins it around to the
	/// opposite end if it gets outside the bracket. For example:   [2,5] 6 will
	/// become 2, 1 will become 5.
	///@param minval  The left bracket, smallest value.
	///@param maxval  The right bracket, largest value.
	///@param clval  Pointer to the number to be clamped.
	///@return Whether the number was clamped(1) or not(0).
	if (clval > maxval) {
		clval = minval;
		return true;
	}
	if (clval < minval) {
		clval = maxval;
		return true;
	}
	return false;
}

template <typename T> void clearArray(T arr[], T clearValue, int size)
{
	///@brief Fills a 1D array with clearValue.
	///@param arr  The array to be cleared.
	///@param clearValue  The value that the array will be filled with.
	///@param siz  The size of the array.
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = clearValue;
	}
	return;
}

template <typename T> int simpleSearch(T arr[], T querVal, int size)
{
	///@brief Searches arr for querVal.
	///@param arr  The array in which we search.
	///@param querVal  The value for which we will search.
	///@param size  The array size.
	///@return The index of the found element, or -1 if it hasn't been found.
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == querVal) {
			return i;
		}
	}
	return -1;
}

#include <array>

template <unsigned C> union Number {
	uint8_t digits[C];
	uint32_t number;
};

template <unsigned C>
void extractDigits(Number<C> num)
{
	int i = 0, res[C];
	// @TODO
}

template <unsigned C> class numberHandler // Rename this
{
public:
	TurnResult makeTurn(Number<C> number_to_check)
	{
		int i, j;
		TurnResult res;
		for (i = 0; i < C; i++) {
			if (number_to_check[i] == number.digits[i]) {
				res.bulls++;
			} else {
				for (j = 0; j < C; j++) {
					if (number_to_check[i] == number.digits[j]) {
						res.cows++;
						break;
					}
				}
			}
		}
		return res;
	}

	void setDigitPool(int digitCount, int digits[])
	{
		digitPoolSize = digitCount;
		digitPool = digits;
	}

private:
	// Rename the following two variables!
	Number<C> number; /// The number which we'll be guessing
	int digitPoolSize = 9, digitPool[10];

	void generateDigit(bool digType = 1)
	{
		///@param digType  Whether to return a digit directly(0) or its index in
		/// the digitPool(1).
	}

	void generateNumber()
	{
		bool occupied[10];
		clearArray(number.digits, -1, C);
		clearArray(occupied, false, 10);
		int i, j;
		for (i = 0; i < C; i++) {
			number.digits[i] = generateDigit();
			occupied[number.digits[i]] = true;
			for (j = 0; j < 10; j++) {
				if (occupied[number.digits[i]]) number.digits[i]++;
				clampInv(1, 9, &number.digits[i]);
			}
		}
	}

	void printNumber(bool printSpaces = 1)
	{
		///@brief Prints the number.
		///@param printType  Whether to print with(1) or without(0) spaces
		/// between digits.
		if (printSpaces) {
			printf("%i %i %i %i", number.digits[0], number.digits[1],
			       number.digits[2], number.digits[3]);
		} else {
			printf("%i", number);
		}
	}
};
