#include <iostream>
#include <math.h>

#include "mMatrix.h"

//Problem 28 (COMPLETE)
//Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
//			21 22 23 24 25
//			20  7  8  9 10
//			19  6  1  2 11
//			18  5  4  3 12
//			17 16 15 14 13
//It can be verified that the sum of the numbers on the diagonals is 101.
//What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

//NOTES
//o Generate the Ulam spiral and store in a matrix

//Function which takes a side length 'n' and outputs the corresponding nxn Ulam Spiral as a matrix
MMatrix GenerateUlamSpiral(int SideLength){
	
	//Check that input is odd
	if(SideLength %2 != 1){
		std::cout << "SideLength must be odd \n";
		exit(-1);
	}
	
	int MidMatrixVal = (SideLength - 1)/2;
	
	MMatrix Matrix(SideLength,SideLength);
	
	//Set initial central element to 1
	Matrix(MidMatrixVal,MidMatrixVal) = 1;
	
	//Move through the matrix in an anti-clockwise spiral starting with movement to the right
	int IntegerCounter = 2;
	int RowCounter = MidMatrixVal;
	int ColCounter = MidMatrixVal;
	
	int MovementCounter = 1;
	
	for(int j = 0; j < MidMatrixVal; j++){
		
		//Move right
		for(int i = 0; i < MovementCounter; i++){
			ColCounter++;
			Matrix(RowCounter, ColCounter) = IntegerCounter++;
		}
				
		//Move down
		for(int i = 0; i < MovementCounter; i++){
			RowCounter++;
			Matrix(RowCounter, ColCounter) = IntegerCounter++;
		}
		
		//Increase movement offset counter
		MovementCounter++;
		
		//Move left
		for(int i = 0; i < MovementCounter; i++){
			ColCounter--;
			Matrix(RowCounter, ColCounter) = IntegerCounter++;
		}
		
		//Move up
		for(int i = 0; i < MovementCounter; i++){
			RowCounter--;
			Matrix(RowCounter, ColCounter) = IntegerCounter++;
		}
		
		//Increase movement offset counter
		MovementCounter++;
	}
	
	//Fill top row across
	for(int i = 0; i < SideLength - 1; i++){
		Matrix(0,i+1) = IntegerCounter++;
	}
	
	return Matrix;
}

//Calculate sum of the diagonals of a matrix
int DiagSum(MMatrix InputMatrix){
	if(InputMatrix.Rows() != InputMatrix.Cols()){
		std::cout << "Matrix must be square for the sum of the diagonals to be calculated \n";
		exit(-1);
	}
	
	int DiagSum = 0;
	
	for(int i = 0; i < InputMatrix.Rows(); i++){
		DiagSum += InputMatrix(i,i);
		DiagSum += InputMatrix(i,InputMatrix.Rows()-i-1);
	}
	DiagSum--;

	return DiagSum;
}


int main() {
	//Change the variable SideLength to alter the size of the Ulam Spiral matrix (Value must be odd)
	int SideLength = 5;
	MMatrix UlamSpiral(SideLength,SideLength);

	UlamSpiral = GenerateUlamSpiral(SideLength);
	
	std::cout << "The sum of the diagonals of the " << SideLength << " by " << SideLength << " Ulam Spiral is " << DiagSum(UlamSpiral) << "\n";

}
