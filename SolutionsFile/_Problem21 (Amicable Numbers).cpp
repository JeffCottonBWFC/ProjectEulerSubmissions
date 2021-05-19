#include <iostream>
#include <math.h>
#include "mVector.h"

//Problem 21 (COMPLETE)
//Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
//If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//Evaluate the sum of all the amicable numbers under 10000.

//NOTES
//o

//Remove duplicate values from an inputted vector
MVector RemoveDuplicates(MVector &InputVector){
	MVector Temp(0);
	for(int i = 0; i < InputVector.size()-1; i++){
		if(InputVector[i] != InputVector[i+1]){
			Temp.resize(Temp.size()+1);
			Temp[Temp.size()-1] = InputVector[i];
		}
	}
	
	Temp.resize(Temp.size()+1);
	Temp[Temp.size()-1] = InputVector[InputVector.size()-1];
	return Temp;
}

//Remove all zeroes from an inputted vector
MVector RemoveZeroes(MVector &InputVector){
	MVector Temp(0);
	for(int i = 0; i < InputVector.size(); i++){
		if(InputVector[i] != 0){
			Temp.resize(Temp.size()+1);
			Temp[Temp.size()-1] = InputVector[i];
		}
	}
	return Temp;
}


//Function which calculates the number of divisors of a given integer
int SumOfProperDivisors(int TestNumber){
	//Storage for Prime Factors and a list of exponents for each prime factor
	MVector PrimeFactors(0);
	MVector ExponentsVector(1);
	
	//declares
	int exponent = 0;
	
	int SumOfCurrentFactor = 0;
	int SumOfTotalFactors = 1;
	int SumOfProperFactors = 0;
	
	int InputtedNumber = TestNumber;
	
	if(TestNumber == 1){
		return 1;
	}
	
	
	//Divide by 2 until number is no longer even
	while(TestNumber % 2 == 0){
		PrimeFactors.resize(PrimeFactors.size()+1);
		PrimeFactors[PrimeFactors.size()-1] = 2;
		TestNumber = TestNumber / 2;
		exponent = exponent+1;
	}
	
	ExponentsVector[0] = exponent;
	
	
	//Run through odd values up to sqrt(TestNumber) and check if divisible by remaining amount of TestNumber
	for(int i = 3; i < TestNumber; i+=2){
		exponent = 0;
		while(TestNumber % i == 0){
			PrimeFactors.resize(PrimeFactors.size()+1);
			PrimeFactors[PrimeFactors.size()-1] = i;
			TestNumber = TestNumber / i;
			exponent = exponent+1;
		}
		ExponentsVector.append(exponent);
	}
	
	//Remaining TestNumber is prime, so add to PrimeFactors vector (1 not prime)
	if(TestNumber != 1){
		PrimeFactors.resize(PrimeFactors.size()+1);
		PrimeFactors[PrimeFactors.size()-1] = TestNumber;
		ExponentsVector.append(1);
	}
	
	//Remove duplicates and zeroes from selected vectors
	PrimeFactors = RemoveDuplicates(PrimeFactors);
	ExponentsVector = RemoveZeroes(ExponentsVector);
		
	
	//Calculate the Sum of proper divisors
	for(int i = 0; i < ExponentsVector.size(); i++){
		if(ExponentsVector[i] != 0){
			SumOfCurrentFactor = (1-pow(PrimeFactors[i], ExponentsVector[i]+1))/(1-PrimeFactors[i]);
		}
		SumOfTotalFactors *= SumOfCurrentFactor;
	}
	
	SumOfProperFactors = SumOfTotalFactors - InputtedNumber;
	return SumOfProperFactors;
}

int AmicableNumbersSummation(int MaxValue){
	MVector AmicableNumbers(0);
	
	int Sibling = 0;
	int AmicableNumbersSum = 0;
	
	//Generate list of Sums of proper divisors from 2 to MaxValue
	for(int i = 1; i < MaxValue; i++){
		Sibling = SumOfProperDivisors(i);
		
		if (i == SumOfProperDivisors(Sibling) && i != Sibling && !AmicableNumbers.ContainedInVector(i)){
			AmicableNumbers.append(i);
			AmicableNumbers.append(Sibling);
		}
	}
	
	for(int i = 0; i < AmicableNumbers.size(); i++){
		AmicableNumbersSum += AmicableNumbers[i];
	}
	
	return AmicableNumbersSum;
}


int main() {
	
	int AmicableNumbersSum = 0;
	
	//Change value of MaxValue variable to alter the maximum value to search for amicable numbers to
	int MaxValue = 10000;
	
	AmicableNumbersSum = AmicableNumbersSummation(MaxValue);
	std::cout << "The sum of amicable numbers from 1 to " << MaxValue << " is " << AmicableNumbersSum << "\n";
}
