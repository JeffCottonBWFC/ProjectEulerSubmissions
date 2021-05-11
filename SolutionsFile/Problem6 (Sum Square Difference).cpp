#include <iostream>
#include <math.h>

//Problem 6 (INCOMPLETE)
//The sum of the squares of the first ten natural numbers is 1^2 + ... + 10^2 = 385
//The square of the sum of the first ten natural numbers is (1+...+10)^2 = 55^2 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

//NOTES
//o Sum of squares from 1 to n = n(n+1)(2n+1)/6

//Function which calculates the sum of squares from 1 to n using formula
int sumOfSquares(int n){
	int Sum = 0;
	Sum = n*(n+1)*(2*n+1)/6;
	return Sum;
}

//Function which calculates the square of the sum from 1 to n
int squareOfSum(int n){
	int Sum = 0;
	for(int i = 1; i <= n; i++){
		Sum += i;
	}
	return pow(Sum, 2);
}


int main() {
	//declares
	int SumOfSquares = 0;
	int SquareOfSums = 0;
	int DifferenceOfSquares = 0;

	//Input the value of n wished to be summed
	int n = 100;
	
	//Function calls
	SumOfSquares = sumOfSquares(n);
	SquareOfSums = squareOfSum(n);
	
	//Calculate difference
	DifferenceOfSquares = SquareOfSums - SumOfSquares;
	
	//Output
	std::cout << DifferenceOfSquares << "\n";
	
}
