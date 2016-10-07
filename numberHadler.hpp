#include <cstdlib>   //rand()
#include <cstdio>    //printf

enum BCTurnResult {nothing = 0, none = 0, cow = 1, bull = 2};///The result of a Bulls&Cows turn can be nothing, a cow or a bull. For multiple cows or bulls - an array.

const int MAXDIGITS = 4;/// Maximum digits should be 9!

bool clamp(int minval,int maxval,int *clval)
{
    ///@brief Keeps a value clamped within [minval,maxval].
    ///@param minval  The left bracket, smallest value.
    ///@param maxval  The right bracket, largest value.
    ///@param clval  Pointer to the number to be clamped.
    ///@return Whether the number was clamped(1) or not(0).
    if(clval>maxval)
    {
        *clval = maxval;
        return true;
    }
    if(clval<minval)
    {
        *clval = minval;
        return true;
    }
    return false;
}

bool clampInv(int minval,int maxval,int *clval)
{
    ///@brief Keeps a value withing [minval,maxval], but spins it around to the opposite end if it gets outside the bracket. For example:   [2,5] 6 will become 2, 1 will become 5.
    ///@param minval  The left bracket, smallest value.
    ///@param maxval  The right bracket, largest value.
    ///@param clval  Pointer to the number to be clamped.
    ///@return Whether the number was clamped(1) or not(0).
    if(clval>maxval)
    {
        *clval = minval;
        return true;
    }
    if(clval<minval)
    {
        *clval = maxval;
        return true;
    }
    return false;
}

class numberHandler
{
public:
    int number;             /// The number which we'll be guessing
    int digits[MAXDIGITS];  /// The digits of the number, from left to right.
    BCTurnResult turnResults[MAXDIGITS];

    template<typename T>
    void clearArray(T arr[],T clearValue,int siz){
    ///@brief Fills a 1D array with clearValue.
    ///@param arr  The array to be cleared.
    ///@param clearValue  The value that the array will be filled with.
    ///@param siz  The size of the array.
    int i;
    for(i=0;i<siz;i++){
        arr[i] = clearValue;
    }
    return ;
    }

    template<typename T>
    int simpleSearch(T arr[],T querVal,int siz){
    int i;
    for(i=0;i<siz;i++){
        if(arr[i]==querVal){
            return i;
        }
    }
    return -1;
    }

    void generateNumber()
    {
        bool occupied[9];
        clearArray(digits,-1,MAXDIGITS);
        clearArray(occupied,false,9);
        int i,j,k;
        for(i=0; i<MAXDIGITS; i++)
        {
            digits[i] = rand()%9 + 1;
            occupied[digits[i]-1] = true;
            for(j=0; j<i; j++)
            {
                if(occupied)
                }
        }
    }

    void printNumber(bool printSpaces = 1)
    {
        ///@param printType  Whether to print with(1) or without(0) spaces between digits.
        if (printSpaces)
        {
            printf("%i %i %i %i", digits[0], digits[1], digits[2],
                   digits[3]);
        }
        else
        {
            cout << number;
        }
    }

    void generateTurnResults(int )

    int playerFunction(bool verbose = 1)
    {
        ///@brief A function that plays the game once. It is supposed to be very efficient.
        ///@param verbose  Whether each turn will be displayed or not. This includes played numbers, cows & bulls, etcetera.
    }

};

