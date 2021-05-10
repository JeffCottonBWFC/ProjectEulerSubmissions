#include <iostream>

//Problem 1 (COMPLETE)
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

//Function which picks out the multiples of 3 or 5 and sums them
void MultThreeFiveSum(int maxValueWanted){
	int total = 0;
	
	for(int i = 1; i < maxValueWanted; i++){
		if(i%3 == 0 || i%5 == 0){
			total += i;
		}
	}
	std::cout << total << "\n";
	return 0;
}



int main() {
	MultThreeFiveSum(1000);
}
