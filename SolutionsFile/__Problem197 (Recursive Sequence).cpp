#include <iostream>
#include <iomanip>
#include <math.h>

//Problem 197 (COMPLETE)
//Given is the function f(x) = ⌊230.403243784-x2⌋ × 10-9 ( ⌊ ⌋ is the floor-function), the sequence un is defined by u0 = -1 and un+1 = f(un).
// Find un + un+1 for n = 10^12.
// Give your answer with 9 digits after the decimal point.

//NOTES
//o Function converges to a bi-stable state, that is, the output values alternate between two values which simultaneously converge to two steady states
//o Function converges fairly quickly, need much less than the 10^12 iterations (~540 needed)

//Function which takes a double as input and returns the function evalation as specified in the problem
double FunctionEval(double input){
	return floor(pow(2,30.403243784-pow(input,2)))*1e-9;
}

int main() {
	double u = -1.0;
	double result = 0.0;
	
	//calculate u1
	double uNext = FunctionEval(u);
	
	//evaluate rest of terms storing the previous value in u
	for(int i = 1; i < 540; i++){
		u = uNext;
		uNext = FunctionEval(u);
	}
	
	result = u + uNext;
	std::cout << std::fixed << std::setprecision(9) << result << "\n";

}
