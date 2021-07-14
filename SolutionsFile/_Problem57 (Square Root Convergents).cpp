#include <iostream>
#include <math.h>

#include "mVector.h"
#include "OperatorOverloads.h"

//Problem 57 (COMPLETE)
//It is possible to show that the square root of two can be expressed as an infinite continued fraction.
//	sqrt(2) = 1/(2+1/(2+1/...))
//By expanding this for the first four iterations, we get:
//	1+1/2 = 3/2
//	1+1/(2+1/2) = 7/5
//	1+1/(2+1/(2+1/2)) = 17/12
//	1+1/(2+1/(2+1/(2+1/2))) = 41/29
//The next three expansions are 99/70, 239/169 and 577/408, but the 8th expansion 1393/985 is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
//In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?


//NOTES
//o Recognising the pattern nk+1 = nk + 2dk, dk+1 = nk + dk for numerators nk and denominators dk.
//o Alternatively the relation, nk+1 = nk + 2dk, dk+1 = nk+1 - dk requires less storage
//o Store digits in vector to avoid using libraries

//Function which takes a vector as input and removes zeroes from the front of the vector until it hits a nonzero entry
MVector removeLeadingZeroes(MVector Vector){
	while(Vector[0] == 0){
		for(int i = 0; i < Vector.size()-1; i++){
			Vector[i] = Vector[i+1];
		}
		Vector.resize(Vector.size()-1);
	}
	return Vector;
}

//Function which reduces all integers in a vector to a single digit via long addition (i.e. the vector {14,23} ->(10s unit from last entry added to first) {16,3} ->(10s unit in first entry added to a new first entry) {1,6,3})
MVector AdjustToDigitsInVector(MVector TestVector){
	int carry;
	
	//Run through vector backwards until second entry
	for(int i = TestVector.size(); i > 1 ; i--){
		carry = 0;
		while(TestVector[i-1] > 9){
			TestVector[i-1] -= 10;
			carry++;
		}
		TestVector[i-2] += carry;
	}
	
	//Update first entry (double while loop to ensure first entry is reduced to a single digit before all digits are multiplied on next iteration)
	while(TestVector[0] > 9){
		carry = 0;
		while(TestVector[0] > 9){
			TestVector[0] -= 10;
			carry++;
		}
		
		TestVector.appendToStart(carry);
		TestVector = removeLeadingZeroes(TestVector);
	}
	return TestVector;
}

//Function which takes in the maximum number of continued fraction iterations as input and returns the number of times the numerator has more digits than the denominator
int NumMoreDigsThanDenom(int MaxValue){
	//Numerator and Denominator digit storage vectors
	MVector NumeratorVector(1);
	MVector DenominatorVector(1);
	
	//ICs
	NumeratorVector[0] = 3;
	DenominatorVector[0] = 2;
	
	//Counter which counts the number of times the numerator has more digits than the denominator
	int NumeratorLargerCounter = 0;
	
	//Loop over from 2nd to (MaxValue-1)th iteration and count the number of times the numerator has more digits than the denominator
	for(int i = 0; i < MaxValue-1; i++){
		//Ensure numerator and denominator lengths are same size
		if(NumeratorVector.size() > DenominatorVector.size()){
			DenominatorVector.appendToStart(0);
			NumeratorLargerCounter++;
		}
		//Apply recurrence relation and convert to vector of integers
		NumeratorVector = NumeratorVector + 2 * DenominatorVector;
		DenominatorVector = NumeratorVector - DenominatorVector;
		NumeratorVector = AdjustToDigitsInVector(NumeratorVector);
		DenominatorVector = AdjustToDigitsInVector(DenominatorVector);
		
		//std::cout << NumeratorVector << "/" << DenominatorVector << "\n";
	}
	return NumeratorLargerCounter;
}


int main() {
	
	//Change this value to alter the maximum iterative expansion to be calculated
	int MaxValue = 1000;
	
	int Occurences = 0;
	
	Occurences = NumMoreDigsThanDenom(MaxValue);
	
	std::cout << "The number of times the numerator has more digits than the denominator for iterations upto " << MaxValue << " is " << Occurences << "\n";
	
}
