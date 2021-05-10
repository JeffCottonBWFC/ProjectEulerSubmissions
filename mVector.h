#ifndef mVector_h
#define mVector_h

#include <vector>
#include <math.h>
#include <cstdlib>
#include <algorithm>

//Normally distrubuted value calculator
double rand_normal()
{
	static const double pi = 3.141592653589793238;
	double u = 0;
	while (u == 0) // loop to ensure u nonzero, for log
	{
		u = rand() / static_cast<double>(RAND_MAX);
	}
	double v = rand() / static_cast<double>(RAND_MAX);
	return sqrt(-2.0*log(u))*cos(2.0*pi*v);
}


// Class that represents a mathematical vector
class MVector
{
public:
	// constructors
	MVector() {}
	explicit MVector(int n) : v(n) {}
	MVector(int n, double x) : v(n, x) {}
	MVector(std::initializer_list<double> l) : v(l) {}
	
	// access element (lvalue) (see example sheet 5, q5.6)
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
	
	// access element (rvalue) (see example sheet 5, q5.7)
	double operator[](int index) const {
		
		if(index+1 > v.size() || index < 0){
			std::cout << "Error: Index outside range" << std::endl;
			exit(-1);
		}
		else{
			return v[index];
		}
	}
	
	int size() const { return v.size(); } // number of elements
	
	void resize(int n){
		v.resize(n);
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
	
	
private:
	std::vector<double> v;
	std::vector<double> w;
	
};


// Overload the << operator to output MVectors to screen or file
std::ostream& operator<<(std::ostream& os, const MVector& v){
	int n = v.size();
	os << "(";
	for(int i = 0; i < n-1; i++){
		os << v[i] << ", ";
	}
	os << v[n-1] << ")" << std::endl;
	return os;
}



#endif
