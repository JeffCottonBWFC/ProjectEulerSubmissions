#include <iostream>
#include <fstream>
#include <math.h>
#include "mMatrix.h"
#include "mVector.h"


//Problem 18 (INCOMPLETE)
//By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//							 3
//							7 4
//						   2 4 6
//						  8 5 9 3
//That is, 3 + 7 + 4 + 9 = 23.
//Find the maximum total from top to bottom of the triangle below:
//								       75
//								      95 64
//								     17 47 82
//							   	   18 35 87 10
//							      20 04 82 47 65
//							     19 01 23 75 03 34
//							    88 02 77 73 07 63 67
//							  99 65 04 28 06 16 70 92
//							 41 41 26 56 83 40 80 70 33
//						    41 48 72 33 47 32 37 16 94 29
//						  53 71 44 65 25 43 91 52 97 51 14
//						 70 11 33 28 77 73 17 78 39 68 17 57
//					    91 71 52 38 17 14 91 43 58 50 27 29 48
//					   63 66 04 68 89 53 67 30 73 16 69 87 40 31
//					  04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

//NOTES
//o Can store values in a lower triangular matrix, then find maximal path for each row starting from bottom and working up.
//o Note we only need to check the cell directly below and the one to the diagonal down right and compare determine which is larger, then add to the cell in question.
//			Done this way as storing the values in a matrix 'shifts' the data to the left of the 		file.
//o Example for 4 row matrix above
//		Matrix  3 0 0 0
//				7 4 0 0
//				2 4 6 0
//				8 5 9 3
//		Work through row by row
//			(Row 3)
//				3 0 0 0
//				7 4 0 0
//				10 13 15 0
//			(Row 2)
//				3 0 0 0
//				20 19 0 0
//			(Row 1)
//				23 0 0 0
// Thus maximum path value is 23.

int MaximumTrianglePathSum(int NumberOfRows, std::string FileName){
	
	//declares
	int MaximalPathSum = 0;
	MMatrix LowerTriangularMatrix(NumberOfRows,NumberOfRows);
	MVector StorageVector(NumberOfRows*(NumberOfRows+1)/2);
	
	//Read from file into vector of values
	std::ifstream FileStream;
	FileStream.open(FileName, std::ios_base::in);
	if (!FileStream){
		std::cout << "File not found \n";
		exit(-1);
	}
	
	for(int i = 0; i < NumberOfRows*(NumberOfRows+1)/2; i++){
		FileStream >> StorageVector[i];
	}
	FileStream.close();
	
	//Read from StorageVector to LowerTriangularMatrix
	int VectorCounter = 0;
	for(int i = 0; i < NumberOfRows; i++){
		for(int j = 0; j <= i; j++){
			LowerTriangularMatrix(i,j) = StorageVector[VectorCounter];
			VectorCounter++;
		}
	}
	
	//Working from second to last row, calculate current maximum path value for each row moving upward
	int TriangMatrixCounter = 0;
	//Run from i = 2 to 0
	for(int i = NumberOfRows-2; i >= 0; i--){
		for(int j = 0; j < NumberOfRows-1-TriangMatrixCounter; j++){
			LowerTriangularMatrix(i,j) += std::max( LowerTriangularMatrix(i+1,j),LowerTriangularMatrix(i+1,j+1));
		}
		TriangMatrixCounter++;
	}
	
	//Top left entry of matrix is the maximal value
	MaximalPathSum = LowerTriangularMatrix(0,0);
	std::cout << "Maximal path value is " << MaximalPathSum << "\n";
	
	return MaximalPathSum;
}


int main() {
	
	//int MaximalPathSum = 0;
	
	//Change the value of variable NumberOfRows to match the number of rows of the test triangle and the value of filename to change location of file
	int NumberOfRows = 100;
	std::string FileName = "Problem18and67MaximumPathSum/Testfile3.txt";
	
	MaximumTrianglePathSum(NumberOfRows, FileName);
		
}
