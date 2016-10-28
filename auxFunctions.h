#ifndef AUXFUNCTIONS_H_VUMFYUIM
#define AUXFUNCTIONS_H_VUMFYUIM

#include "TurnResult.h"

/// @brief Keeps a value clamped within [minval,maxval].
/// @param minval  The left bracket, smallest value.
/// @param maxval  The right bracket, largest value.
/// @param clval  Pointer to the number to be clamped.
/// @return Whether the number was clamped(1) or not(0).
bool clamp(int minval, int maxval, int& clval)
{
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

///@brief Keeps a value withing [minval,maxval], but spins it around to the
/// opposite end if it gets outside the bracket. For example:   [2,5] 6 will
/// become 2, 1 will become 5.
///@param minval  The left bracket, smallest value.
///@param maxval  The right bracket, largest value.
///@param clval  Pointer to the number to be clamped.
///@return Whether the number was clamped(1) or not(0).
bool clampInv(int minval, int maxval, int& clval)
{
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

///@brief Fills a 1D array with clearValue.
///@param arr  The array to be cleared.
///@param clearValue  The value that the array will be filled with.
///@param siz  The size of the array.
template <typename T> void clearArray(T arr[], T clearValue, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = clearValue;
	}
	return;
}

///@brief Searches arr for querVal.
///@param arr  The array in which we search.
///@param querVal  The value for which we will search.
///@param size  The array size.
///@return The index of the found element, or -1 if it hasn't been found.
template <typename T, unsigned C>
int simpleSearch(std::array<T, C> arr, T querVal)
{
	for (const T& i : arr) {
		if (i == querVal) {
			return i;
		}
	}
	return -1;
}

#endif /* end of include guard: AUXFUNCTIONS_H_VUMFYUIM */
