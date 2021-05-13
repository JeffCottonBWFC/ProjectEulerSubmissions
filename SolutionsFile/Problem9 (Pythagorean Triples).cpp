#include <iostream>
#include <math.h>
#include "mVector.h"

//Problem 9 (COMPLETE)
//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
//						For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.

//NOTES
//o Pythagorean triples generator
//	m,n in integers (m > n). Then a = m^2 - n^2, b = 2mn, c = m^2+n^2 form a Pythagorean triple
// 	This formula only produces the primitive triples (i.e. produces triples of form a^2+b^2=c^2 but not integer multiples of them)

//Function which calculates a list of all primitive and checks to see if the sum of the triple equals PythagoreanTripleSum
MVector PrimitivePythagoreanTriplesGenerator(int PythagoreanTripleSum){
	
	int maxN = 50;
	
	//initialise
	int a = 0;
	int b = 0;
	int c = 0;
	
	MVector PythagTriple(3);
	
	//Generate a,b,c according to the Pythagorean triples generator formula
	for(int n = 1; n < maxN; n++){
		for(int m = 1; m < n; m++){
			a = pow(n,2) - pow(m,2);
			b = 2*m*n;
			c = pow(n,2) + pow(m,2);
			
			//Check abc sum
			if(a+b+c == PythagoreanTripleSum){
				std::cout << "Pythagorean Triple with sum " << PythagoreanTripleSum << " found \n";
				
				PythagTriple[0] = a;
				PythagTriple[1] = b;
				PythagTriple[2] = c;
				return PythagTriple;
				break;
			}
		}
	}
	std::cout << "No Pythagorean triple with sum " << PythagoreanTripleSum << " found \n";
	exit(-1);
}

int main() {
	
	MVector PythagTriple(3);
	//Max n value to be searched and and the sum value wished to be found.
	int PythagoreanTripleSum = 1000;
	int PythagTripleProduct = 0;
	
	//Function call
	PythagTriple = PrimitivePythagoreanTriplesGenerator(PythagoreanTripleSum);
	std::cout << PythagTriple;
	
	//Calculate product
	PythagTripleProduct = PythagTriple[0]*PythagTriple[1]*PythagTriple[2];
	std::cout << "Product is " << PythagTripleProduct << "\n";
}
