#include <iostream>
#include <math.h>

//Problem 120 (COMPLETE)
//Let r be the remainder when (a−1)^n + (a+1)^n is divided by a^2.
//For example, if a = 7 and n = 3, then r = 42: 63 + 83 = 728 ≡ 42 mod 49. And as n varies, so too will r, but for a = 7 it turns out that r_max = 42.
//For 3 ≤ a ≤ 1000, find ∑ r_max.

//NOTES
//o Varing values of n for fixed a into equation results in r = 2 for n even and 2an for n odd.
//o The maximum n such that 2n is closest to a is when 2n_max = a-1. Thus n_max = (a-1)/2. n_max must be integer so use floor fn (or integer division).

void SquareRemainders(int SummationMin, int SummationMax){
	
	int SummationOfrMax = 0;
	int FloorFnRem = 0;
	
	for(int a = SummationMin; a <= SummationMax; a++){
		FloorFnRem = (a-1)/2;
		SummationOfrMax += 2 * a * FloorFnRem;
	}
	
	std::cout << "The summation of maximal remainders from " << SummationMin << " to " <<  SummationMax << " is " << SummationOfrMax << "\n";
	
}

int main() {
	//Change the values of SummationMin and SummationMax to alter the limits of the summation for maximal r
	int SummationMin = 3;
	int SummationMax = 1000;
	SquareRemainders(SummationMin, SummationMax);
}
