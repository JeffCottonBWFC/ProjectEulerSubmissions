#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#include "mVector.h"
#include "OperatorOverloads.h"

//Problem 102 (COMPLETE)
//Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.
//Consider the following two triangles:
//	A(-340,495), B(-153,-910), C(835,-947)
//	X(-175,41), Y(-421,-714), Z(574,-645)
//It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not
//Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.

//NOTES
//o Calculate area triangle ABC and areas of subtriangles ABP, BCP, ACP for origin P. If not equal, triangle ABC cannot contain the origin
//o Area of triangle is half of absolute value of determinant
//		0.5 * |(xA-xC)(yB-yA) - (xA-xB)(yC-yA)| where xA is the x-ordinate of point A
//o Can ignore factor of 0.5 as we are only comparing the areas


//Function which takes three vectors with 2 elements in each and returns 2*Area of triangle the given coordinates form
int TwiceAreaOfTriangle(MVector Vect1, MVector Vect2, MVector Vect3){
	
	if(Vect1.size() == 2 && Vect2.size() == 2 && Vect3.size() == 2){
		int Area = abs((Vect1[0] - Vect3[0])*(Vect2[1] - Vect1[1]) - (Vect1[0] - Vect2[0])*(Vect3[1] - Vect1[1]));
		return Area;
	}else{
		std::cout << "Size of each vector must be two" << "\n";
		exit(-1);
	}
}

//Function which takes three vectors as input and returns whether the origin is located within the triangle the coordinates make when straight lines are drawn between them
bool OriginInTriangle(MVector VectA, MVector VectB, MVector VectC){
	
	MVector OriginP = {0,0};
	int AreaABC, AreaABP, AreaBCP, AreaACP = 0;
	//Calculate areas
	AreaABC = TwiceAreaOfTriangle(VectA, VectB, VectC);
	AreaABP = TwiceAreaOfTriangle(VectA, VectB, OriginP);
	AreaBCP = TwiceAreaOfTriangle(VectB, VectC, OriginP);
	AreaACP = TwiceAreaOfTriangle(VectA, VectC, OriginP);
	
	//Check if area ABC is equal to sum of subtriangles (+1 to counter if so)
	if(AreaABC == AreaABP + AreaBCP + AreaACP){
		return true;
	}else{
		return false;
	}
}


//Function which takes a file location as input, with each line containing six integers delimited by commas, storing these values in three vectors with two elements each and sending to function OriginInTriangle, then counts the number of times the triangle formed contains the origin
int GetCoordsFromFile(std::string FileName){
	
	int OriginInTriangleCounter = 0;
	
	//Coordinate vectors
	MVector VectA = {0,0};
	MVector VectB = {0,0};
	MVector VectC = {0,0};
	MVector OriginP = {0,0};
	
	MVector StorageVector(6);
	
	//Open Filestream
	std::fstream FileStream;
	FileStream.open(FileName);
	if (!FileStream){
		std::cout << "File not found \n";
		exit(-1);
	}
	
	//Read file line by line
	while(!FileStream.eof()){
		//Store line in string
		std::string LineString = "";
		getline(FileStream, LineString);
		
		//Convert string with commas to StorageVector of values
		std::stringstream StringStream(LineString);
		
		int IndexCounter = 0;
		for(int i; StringStream >> i;){
			StorageVector[IndexCounter] = i;
			if (StringStream.peek() == ','){
				StringStream.ignore();
			}
			IndexCounter++;
		}
		
		//Insert values into corresponding A B and C vectors
		VectA[0] = StorageVector[0];
		VectA[1] = StorageVector[1];
		VectB[0] = StorageVector[2];
		VectB[1] = StorageVector[3];
		VectC[0] = StorageVector[4];
		VectC[1] = StorageVector[5];
		
		OriginInTriangleCounter += OriginInTriangle(VectA, VectB, VectC);
	}
	
	FileStream.close();
	
	return OriginInTriangleCounter;
}


int main() {
	//Change the file location for the list of coordinates here
	std::string FileName = "Problem102TriangleContainment/TriangleCoordinates.txt";
	
	int OriginInTriangleCounter = 0;
	
	OriginInTriangleCounter = GetCoordsFromFile(FileName);
	
	std::cout << "In the file submitted, the origin is contained inside " << OriginInTriangleCounter << " of the triangles" << "\n";
	
}
