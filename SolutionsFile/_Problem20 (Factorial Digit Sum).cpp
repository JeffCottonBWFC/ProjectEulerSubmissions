#include <iostream>
#include <math.h>
#include "mVector.h"

//Problem 20 (COMPLETE)
//n! means n × (n − 1) × ... × 3 × 2 × 1
//For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//Find the sum of the digits in the number 100!

//NOTES
//o Store digits in a vector, much like in problem 16

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


//Adds the values of all the entries of a vector
int DigitSum(MVector Vector){
	
	int DigitSum = 0;
	//Sum the digits together
	for(int i = 0; i < Vector.size(); i++){
		DigitSum += Vector[i];
	}
	
	return DigitSum;
}


//Function which takes an integer as input (the factorial to be evaluated) and outputs the sum of the digits of said factorial to the user
void FactorialDigits(int FactorialInput){
	
	//Storage
	int DigitSummation = 0;
	MVector DigitStorage(1);
	DigitStorage[0] = 1;
	int carry;
	
	for(int k = 0; k < FactorialInput; k++){
		//Multiply each entry by (k+1)
		for(int j = 0; j < DigitStorage.size(); j++){
			DigitStorage[j] = (k+1) * DigitStorage[j];
		}
		
		//Run through vector backwards until second entry
		for(int i = DigitStorage.size(); i > 1 ; i--){
			carry = 0;
			while(DigitStorage[i-1] > 9){
				DigitStorage[i-1] -= 10;
				carry++;
			}
			DigitStorage[i-2] += carry;
		}
		
		//Update first entry (double while loop to ensure first entry is reduced to a single digit before all digits are multiplied on next iteration)
		while(DigitStorage[0] > 9){
			carry = 0;
			while(DigitStorage[0] > 9){
				DigitStorage[0] -= 10;
				carry++;
			}
			
			DigitStorage.appendToStart(carry);
			DigitStorage = removeLeadingZeroes(DigitStorage);
		}
	}
	
	//Sum integer values of DigitStorage and output to user
	DigitSummation = DigitSum(DigitStorage);
	std::cout << "The sum of the digits of " << FactorialInput << "! is " << DigitSummation << "\n";
}

int main() {
	//Change variable FactorialInput to alter the factorial to be evaluated (i.e. for 4!, change FactorialInput to 4)
	int FactorialInput = 500;
	
	FactorialDigits(FactorialInput);
	
}
