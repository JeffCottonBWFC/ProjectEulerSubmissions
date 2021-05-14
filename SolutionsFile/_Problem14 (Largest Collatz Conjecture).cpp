#include <iostream>
#include <math.h>

//Problem 14 (COMPLETE)
//The following iterative sequence is defined for the set of positive integers:
//					n → n/2 (n is even)
//					n → 3n + 1 (n is odd)
//Using the rule above and starting with 13, we generate the following sequence:
//			13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//Which starting number, under one million, produces the longest chain?
//NOTE: Once the chain starts the terms are allowed to go above one million.


//NOTES
//o Store values as longs as the current value can exceed 2.1bil easily
//o Mumber of terms calculated includes the initial term chosen as a step!



//function which takes the initial value of the Collatz sequence as input and returns the number of steps taken for the Collatz sequence to reach 1. (Note number of terms includes the initial term chosen as a step)
int CollatzCall(long long InitialValue){
	int NumberOfTerms = 1;
	
	long long CurrentValue = InitialValue;
	
	while(CurrentValue != 1){
		if(CurrentValue%2 == 0){
			CurrentValue /= 2;
			NumberOfTerms++;
		}else{
			CurrentValue = 3 * CurrentValue + 1;
			NumberOfTerms++;
		}
	}
	
	return NumberOfTerms;
}

//Function which takes LargestInitialCondition to be calculated as input and outputs the largest number of steps to be produced by an initial value below LargestInitialCondition.
void LargestCollatzSequence(int LargestInitialCondition){
	//Declares
	int NumberOfTerms = 1;
	int CurrentLargestNumOfTerms = 1;
	long long InitialValueOfLongestSequence = 1;
	long long InitialValue = 1;
	
	//Runs from 1 to LargestInitialCondition, calculates number of terms in Collatz conjecture and updates if number of terms is larger than previous largest.
	for(int i = 1; i < LargestInitialCondition; i++){
		InitialValue = i;
		
		NumberOfTerms = CollatzCall(InitialValue);
		
		if(NumberOfTerms > CurrentLargestNumOfTerms){
			CurrentLargestNumOfTerms = NumberOfTerms;
			InitialValueOfLongestSequence = InitialValue;
		}
	}
	
	//Output to user
	std::cout << "The initial value " << InitialValueOfLongestSequence << " produces " << CurrentLargestNumOfTerms << " terms, the longest sequence with initial value below " << LargestInitialCondition << "\n";
}



int main() {
	//Change LargestInitialCondition to vary the maximum initial condition to be searched up to.
	int LargestInitialCondition = 1000000;
	LargestCollatzSequence(LargestInitialCondition);
}
