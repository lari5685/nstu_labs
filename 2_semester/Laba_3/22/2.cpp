#include <iostream>
#include <cmath>

int Fact(int n){
	if (n==0)
		return 1;
	else 
		return n*Fact(n-1);	
}

double graf_2(double x, int n){
	double res=0;
	for (int i=0;i<n;i++){
		res += pow(x,2*i)/(Fact(2*i));
	}
	return res;
}
int main(){
	std::cout << "x" <<"\t\t"<< "ch(x)"<<std::endl;
	for (float i = 0; i <= 1; i+=0.1)
		std::cout<<i<<"\t\t"<<graf_2(i, 10)<<std::endl;
}