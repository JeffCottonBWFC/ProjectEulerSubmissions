#include <iostream>
#include <math.h>
#include "mVector.h"

//Problem 16 (COMPLETE)
//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 2^1000?

//NOTES
//o Store the digits of the power in a vector. Multiply each digit by 2 and overflow to previous entry if 10 or larger
//o Need to resize vector if the overflow occurs in the first entry (i.e (10,4,2,5) cannot overflow outside of range, must resize vector, shift values to right one and then apply rules)

//Function which takes in the desired exponent of 2^n and returns the sum of the digits it is made from
int SumOfDigitsOfPowerOfTwo(int DesiredExponent){
	//Storage for digits
	MVector DigitStorage(1);
	DigitStorage[0] = 1;
	
	//Storage for final sum
	int VectorSum = 0;
	
	//Loop from 2^1 to 2^(DesiredExponent)
	for(int Exponent = 1; Exponent < DesiredExponent+1; Exponent++){
		//Go through and mulitply each entry by 2
		for(int j = 0; j < DigitStorage.size(); j++){
			DigitStorage[j] = 2 * DigitStorage[j];
		}
		
		//Go through again from end and check if entry > 9. If so, mod 10 and add one / append a one to the vector if its the first entry
		for(int j = DigitStorage.size(); j > 0; j--){
			if(DigitStorage[j-1] > 9){
				if(j == 1){
					DigitStorage[j-1] = fmod(DigitStorage[j-1], 10);
					DigitStorage.appendToStart(1);
				}else{
					DigitStorage[j-1] = fmod(DigitStorage[j-1], 10);
					DigitStorage[j-2] += 1;
				}
			}
		}
	}
	
	//Calculates sum of digits
	for(int i = 0; i < DigitStorage.size(); i++){
		VectorSum += DigitStorage[i];
	}
	
	return VectorSum;
}


int main() {
	int VectorSum = 0;
	
	//Change DesiredExponent variable to determine the sum of the digits of 2^DesiredExponent
	int DesiredExponent = 1000;
	
	//Function call
	VectorSum = SumOfDigitsOfPowerOfTwo(DesiredExponent);
	
	//Output to user
	std::cout << "The sum of the digits of 2^" << DesiredExponent << " is " << VectorSum << "\n";

	

}
