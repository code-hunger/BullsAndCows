#include <iostream>  //cin,cout
#include <ctime>     //time()
#include <cstdlib>   //rand(),srand()
#include <cstdio>    //printf()

using namespace std;//So we don't have to worry about std::

class bullsAndCows{
public:
    int m_number;///The number which we'll be guessing
    int m_digits[4];///The digits of the number, from left to right.

    void generateNumber(){
    m_digits[0] = rand()%9 + 1;
    m_digits[1] = rand()%9; m_digits[1] += m_digits[1]>=m_digits[0];
    m_digits[2] = rand()%9; m_digits[2] += m_digits[2]>=m_digits[0]; m_digits[2] += m_digits[2]>=m_digits[1];
    m_digits[3] = rand()%9; m_digits[3] += m_digits[3]>=m_digits[0]; m_digits[3] += m_digits[3]>=m_digits[1]; m_digits[3] += m_digits[3]>=m_digits[2];
    m_number = m_digits[0]*1000 + m_digits[1]*100 + m_digits[2]*10 + m_digits[3];
    }

    void printNumber(bool printType = 1/** 1 will print with spaces inbetween digits. **/){
        if(printType){printf("%i %i %i %i",m_digits[0],m_digits[1],m_digits[2],m_digits[3]);}else{cout<<m_number;}
    }
};

int main(void)
{
	cout << "Hi!\n";
	return 0;
}

