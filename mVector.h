#ifndef mVector_h
#define mVector_h

#include <vector>
#include <math.h>
#include <cstdlib>
#include <algorithm>


// Class that represents a mathematical vector
class MVector
{
public:
	// constructors
	MVector() {}
	explicit MVector(int n) : v(n) {}
	MVector(int n, double x) : v(n, x) {}
	MVector(std::initializer_list<double> l) : v(l) {}

	
	// access element (lvalue)
	double &operator[](int index)
	{
		if(index+1 > v.size() || index < 0){
			std::cout << "Error: Index outside range" << std::endl;
			exit(-1);
		}
		else{
			return v[index];
		}
	}
	
	
	// access element (rvalue)
	double operator[](int index) const {
		
		if(index+1 > v.size() || index < 0){
			std::cout << "Error: Index outside range" << std::endl;
			exit(-1);
		}
		else{
			return v[index];
		}
	}
	
	
	//Return size of vector
	int size() const { return v.size(); } // number of elements
	
	
	//Resize vector
	void resize(int n){
		v.resize(n);
	}
	
	
	//Append value to start of vector
	void appendToStart(double x){
		v.resize(v.size()+1);
		for(int i = v.size(); i > 1; i--){
			v[i-1] = v[i-2];
		}
		v[0] = x;
	}
	
	
	//Append value to end of vector
	void append(double x){
		v.resize(v.size()+1);
		v[v.size()-1] = x;
	}
	
	//Checks if selected value is contained within the given vector
	bool ContainedInVector(double x){
		for(int i = 0; i < v.size(); i++){
			if(x == v[i]){
				return true;
			}
		}
		return false;
	}
	
	//Return standard norm value of a vector
	double VectNorm(){
		double NormVal = 0.0;
		
		for(int i = 0; i < v.size(); i++){
			NormVal = NormVal + (v[i] * v[i]);
		}
		NormVal = sqrt(NormVal);
		
		return NormVal;
	}
	
	//Swap two values in a vector
	void swap(int i, int j){
		double Temp = 0;
		Temp = v[i];
		v[i] = v[j];
		v[j] = Temp;
	}

	

	
private:
	std::vector<double> v;
	
};


// Overload the << operator to output MVectors to screen or file
std::ostream& operator<<(std::ostream& os, const MVector& v){
	int n = v.size();
	if(n == 0){
		os << "()" << std::endl;
	}else{
		os << "(";
		for(int i = 0; i < n-1; i++){
			os << v[i] << ", ";
		}
		os << v[n-1] << ")" << std::endl;
	}
	return os;
}



#endif
