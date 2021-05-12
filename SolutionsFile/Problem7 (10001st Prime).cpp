#include <iostream>
#include <math.h>
#include "mVector.h"


//Problem 7 (COMPLETE)
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13. What is the 10001st prime number?

//NOTES
//o A consequence of the Prime Number Theorem (PNT) is that the nth prime number p_n ~ n*ln(n).
//	Decent approximation n*ln(n) for n = 10001 is 92114.
//o Need to ensure our PrimeList generates enough terms



MVector GeneratePrimes(int MaxNumber){
	//Generate Primes (Sieve of Sundaram)
	int k = (MaxNumber-2) / 2;
	MVector IntegerList(k);
	MVector PrimesList(1);
	
	//Generate vector of 1 to MaxNumber
	for(int i = 0; i < k; i++){
		IntegerList[i] = i+1;
	}
	
	//Apply Sundaram conditions
	for(int i=1; i<=k; i++){
		for(int j=i; j <= (k-i)/(2*i+1); j++){
			IntegerList[i + j + 2*i*j - 1] = 0;
		}
	}
	
	//Save rescaled integers to PrimeList
	int IndexCounter = 1;
	
	for(int i = 1; i < k+1; i++){
		if(IntegerList[i-1] != 0){
			PrimesList.resizePlusOne();
			PrimesList[IndexCounter] = 2 * IntegerList[i-1] + 1;
			IndexCounter++;
		}
	}
	
	//Append 2 to start of PrimesList (Not generated by Sundaram Algorithm)
	PrimesList[0] = 2;
	
	return PrimesList;
}


int main() {
	MVector PrimesList;
	
	PrimesList = GeneratePrimes(105000);
	
	//Output 10001th prime
	std::cout << PrimesList[10000] << "\n";
	
}