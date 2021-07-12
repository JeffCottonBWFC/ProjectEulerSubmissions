#include <iostream>
#include <math.h>
#include "mVector.h"
#include "OperatorOverloads.h"

//Problem 55 (COMPLETE)
//If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
//Not all numbers produce palindromes so quickly. For example,
//		349 + 943 = 1292,
//		1292 + 2921 = 4213
//		4213 + 3124 = 7337
// That is, 349 took three iterations to arrive at a palindrome.
//Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
//Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
//How many Lychrel numbers are there below ten-thousand?

//NOTES
//o Use IsPalindromic() function from Problem 4, re-implement to work with vector of digits?
//o Store digits in vector

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


//Function which reverses a given input vector
MVector VectorReverse(MVector InputVector){
	for(int i = 0; i < InputVector.size()/2; i++){
		InputVector.swap(i,InputVector.size()-i-1);
	}
	return InputVector;
}

//Function which reverses an input integer and compares it with the original input. Returns true if palindromic
bool IsPalindromic(MVector InputVector){
	MVector ReverseVector = VectorReverse(InputVector);
	
	for(int i = 0; i < InputVector.size(); i++){
		if(InputVector[i] != ReverseVector[i]){
			return false;
		}
	}
	return true;
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

//Function which tests the given input vector of component digits representing an integer, performs the Lychrel process of reversing the digit vector, adding to initial vector and checking whether result is a palindrome. If so, return true. If not, iterate again until palindromic or 50 iterations performed
bool LychrelNumber(MVector TestVector){
	//Lychrel Testing function
	for(int i = 0; i < 50; i++){
		TestVector = TestVector + VectorReverse(TestVector);

		TestVector = AdjustToDigitsInVector(TestVector);
	
		if(IsPalindromic(TestVector) == 1){
			return false;
		}
	}
	return true;
}

//Function which converts input integer into a vector of component digits
MVector InputIntegerToVector(int TestInteger){
	MVector StorageVector(1);
	StorageVector[0] = TestInteger;
	
	return AdjustToDigitsInVector(StorageVector);
}

int main() {
	//Change value of MaxValue to alter the maximum value to be checked up to (from 10 to MaxValue)
	int MaxValue = 10000;
	
	MVector TestVector;
	int NumOfLychrelNums = 0;

	//Test from 10 (single digits not palindromic) to MaxValue for Lychrel numbers
	for(int i = 10; i < MaxValue; i++){
		TestVector = InputIntegerToVector(i);
		if(LychrelNumber(TestVector) == true){
			NumOfLychrelNums++;
		}
	}

	std::cout << "The number of Lychrel numbers below " << MaxValue << " is: " << NumOfLychrelNums << "\n";
	
}
