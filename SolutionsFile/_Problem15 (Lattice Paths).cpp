#include <iostream>
#include <math.h>

//Problem 15 (COMPLETE)
//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?


//NOTES
//o Avoid factorials (tend to get very large/hard to store quite quickly)
//o Number of paths is equal to 2NCN (the binomial coefficient)
//o Can use the formula nCk = Product i=1...k  	(n+1-i)/i
//		Thus 2NCN = Product i=1...N		(2N+1-i)/i


//Calculate number of lattice paths given by formula in notes
long NumberOfLatticePaths(int SizeOfGrid){
	long NumberOfPaths = 1;
	
	for(int i = 1; i <= SizeOfGrid; i++){
		NumberOfPaths *= (2*SizeOfGrid) + 1 - i;
		NumberOfPaths /= i;
	}
	
	return NumberOfPaths;
}

int main() {
	//Change SizeOfGrid variable to chosen size of grid
	int SizeOfGrid = 20;
	
	std::cout << NumberOfLatticePaths(SizeOfGrid) << "\n";
}

