#include <iostream>
#include <cmath>

double graf_1(double x){
	if (-5 <= x && x < -2){
		return -0.5*x - 1.5;
	}
	if (-2 <= x && x <= 2){
		return 2*cos(2*x);
	}
	if (2 < x && x <= 5){
		return 0.5*x - 1.5;
	}
}
int main(){
	std::cout << "x" <<"\t"<< "y"<<std::endl;
	for ( int i=-5;i<5;i++){
	std::cout<<i<< "\t"<<graf_1(i)<<std::endl;
	}
		
} 