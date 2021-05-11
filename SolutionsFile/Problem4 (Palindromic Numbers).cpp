#include <iostream>
#include <math.h>

//Problem 4 (COMPLETE)
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

//NOTES
//o Two 3-digit numbers in range [100*100, 999*999] = [10000, 998001]
//o Can safely assume the palindrome in question is 6 digits long

//Function which reverses an input integer and compares it with the original input. Returns true if palindromic
bool IsPalindromic(int input){
	
	int remainder;
	int sum = 0;
	int temp;
	
	temp = input;
	
	//Pulls last digit from input and appends to front at each iteration
	while(input > 0){
		remainder = input % 10;
		sum = (sum * 10) + remainder;
		input = input / 10;
	}
	
	if(temp == sum){
		return true;
	}else{
		return false;
	}
}


int main(){
	
	int TestInteger;
	int CurrentLargest = 0;
	
	//Runs from 999*999 and detemines whether palindromic, replaces CurrentLargest if larger. Note j runs from 999 to i for each i loop for efficiency.
	for(int i = 999; i > 99; i--){
		for(int j = 999; j > i; j--){
			TestInteger = i*j;
			if(IsPalindromic(TestInteger) == true && CurrentLargest < TestInteger){
				CurrentLargest = TestInteger;
			}
		}
	}
	std::cout << CurrentLargest << "\n";
}
