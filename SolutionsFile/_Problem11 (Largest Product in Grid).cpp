#include <iostream>
#include <math.h>
#include <fstream>
#include "mMatrix.h"

//Problem 11 (COMPLETE)
//In the 20×20 grid below, four numbers along a diagonal line have been marked in red. The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
// 	08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
//	49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
//	81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
//	52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
//	22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
//	24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
//	32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
//	67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
//	24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
//	21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
//	78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
//	16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
//	86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
//	19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
//	04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
//	88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
//	04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
//	20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
//	20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
//	01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
//What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

//NOTES
//o Use matrix to store values
//o Only need to search in 4 directions
//o Check dont extend across edge of storageMatrix

long long LargestGridProduct(int NumberOfRows, int NumberOfCols, int ProductSize){
	
	MMatrix StorageMatrix(NumberOfRows,NumberOfCols);
	
	std::fstream FileStream;
	FileStream.open("Problem8GridProduct/TestMatrixFile2.txt", std::ios_base::in);
	if (!FileStream){
		std::cout << "File not found \n";
		exit(-1);
	}
	
	//Initialise TestMatrix
	for(int i = 0; i < StorageMatrix.Rows(); i++){
		for(int j = 0; j < StorageMatrix.Cols(); j++){
			FileStream >> StorageMatrix(i,j);
		}
	}
	FileStream.close();
	
	std::cout << StorageMatrix << "\n";
	
	//Longlong as product can exceed 2.1 bil very quickly
	long long CurrentProduct = 1;
	long long LargestProduct = 1;
	
	//Error Checking
	if(ProductSize > StorageMatrix.Rows() || ProductSize > StorageMatrix.Cols()){
		std::cout << "Variable ProductSize is greater than matrix size \n";
		exit(-1);
	}
	if(ProductSize < 1){
		std::cout << "Variable ProductSize is smaller than 1 \n";
		exit(-1);
	}
	
	//Starting at top left and moving right and down, check if corresponding n entries (horizontally, vertically, downleft diagonal and downright diagonal) are larger than current product
	for(int column = 0; column < StorageMatrix.Cols(); column++){
		for(int row = 0; row < StorageMatrix.Rows(); row++){
			
			//Check Horizontally
			if(column < StorageMatrix.Cols() - ProductSize + 1){
				CurrentProduct = 1;
				for(int i = 0; i < ProductSize; i++){
					CurrentProduct *= StorageMatrix(row,column+i);
				}
				if(CurrentProduct > LargestProduct){
					LargestProduct = CurrentProduct;
				}
			}
			
			//Check Vertically
			if(row < StorageMatrix.Rows() - ProductSize + 1){
				CurrentProduct = 1;
				for(int i = 0; i < ProductSize; i++){
					CurrentProduct *= StorageMatrix(row+i,column);
				}
				if(CurrentProduct > LargestProduct){
					LargestProduct = CurrentProduct;
				}
			}
			
			
			//Check Downright
			if(column < StorageMatrix.Cols() - ProductSize + 1 && row < StorageMatrix.Rows() - ProductSize + 1){
				CurrentProduct = 1;
				for(int i = 0; i < ProductSize; i++){
					CurrentProduct *= StorageMatrix(row+i,column+i);
				}
				if(CurrentProduct > LargestProduct){
					LargestProduct = CurrentProduct;
				}
			}
			
			
			//Check Downleft
			if(column >= ProductSize - 1  && row < StorageMatrix.Rows() - ProductSize + 1){
				CurrentProduct = 1;
				for(int i = 0; i < ProductSize; i++){
					CurrentProduct *= StorageMatrix(row+i,column-i);
				}
				if(CurrentProduct > LargestProduct){
					LargestProduct = CurrentProduct;
				}
			}
			
		}
	}
	
	//Output to user
	std::cout << "The largest product of " << ProductSize << " adjacent integers is: " <<   LargestProduct << "\n";
	return LargestProduct;
}

int main() {
	
	long long LargestProduct;
	
	//Insert size of TestMatrix written to file
	int NumberOfRows = 20;
	int NumberOfCols = 20;
	
	//Insert number of adjacent numbers wished to be multiplied
	int ProductSize = 4;
		
	LargestProduct = LargestGridProduct(NumberOfRows, NumberOfCols, ProductSize);

}
