#include <iostream>
#include <math.h>
#include "mVector.h"

//Problem 3 (COMPLETE)
//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

//NOTES
//o If n=pq not prime then at least one prime factor of n is < sqrt(n)
//o If n not prime then at most one prime factor of n is > sqrt(n)

//Calculates the prime factors of a given integer
void PrimeFactors(long TestNumber){
	MVector PrimeFactors(0);
		
	//Divide by 2 until number is no longer even
	while(TestNumber % 2 == 0){
		PrimeFactors.resize(PrimeFactors.size()+1);
		PrimeFactors[PrimeFactors.size()-1] = 2;
		TestNumber = TestNumber / 2;
	}
	
	
	//Run through odd values up to sqrt(TestNumber) and check if divisible by remaining amount of TestNumber
	for(int i = 3; i < sqrt(TestNumber)+1; i+=2){
		while(TestNumber % i == 0){
			PrimeFactors.resize(PrimeFactors.size()+1);
			PrimeFactors[PrimeFactors.size()-1] = i;
			TestNumber = TestNumber / i;
		}
	}
	
	//Remaining TestNumber is prime, so add to PrimeFactors vector
	PrimeFactors.resize(PrimeFactors.size()+1);
	PrimeFactors[PrimeFactors.size()-1] = TestNumber;
	
	std::cout << "Prime factors are: " << PrimeFactors;
}

int main() {
	long TestNumber = 600851475143;
	PrimeFactors(TestNumber);
}
