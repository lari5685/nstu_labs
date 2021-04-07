#include <iostream>
#include <vector>
#include <random>
#include <ctime>

std::vector<int> generator(int count, int max){
	std::minstd_rand gen;
	gen.seed(time(0));

	std::vector<int> main_list;

	for(int i = 0; i < count; i++){
		main_list.push_back(gen()%max+1);
	}
	return main_list;
}
double x_su(int count){
	std::vector<int> list = generator(count, 100);

	int distrib_list[100];
	for (int i = 0; i < 100; i++)
		distrib_list[i] = 0;
	for (auto item : list){
		distrib_list[item]++;
	}

	double x = 0;
	double Vexp = (double)count/100;
	for (auto item : distrib_list)
		x += (item - Vexp)*(item - Vexp)/Vexp;
	return x;
}


int main(){
	std::cout << "count = " << 50   << "  \tx-sqr = "<< x_su(50)   << std::endl;
	std::cout << "count = " << 100  << "  \tx-sqr = "<< x_su(100)  << std::endl;
	std::cout << "count = " << 1000 << "  \tx-sqr = "<< x_su(1000) << std::endl;
}