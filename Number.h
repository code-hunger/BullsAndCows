template <unsigned C> struct Number {
	short digits[C];
	int getCopyOfNumber() {
		int result, i = C, i10 = pow(10, C);
		while (i10 /= 10 && --i) {
			result += digits[i] * i10;
		}
		return result;
	}
};

template <unsigned C>
void extractDigits(Number<C> num)
{
	int i = 0, res[C];
	// @TODO
}
