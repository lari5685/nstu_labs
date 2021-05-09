#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

vector<int>  generator( int n ){
	minstd_rand0 gen; //объявляем генератор
	gen.seed(time(0)); //начальное число генератора

	vector <int> a_vector(n);
	for ( auto &item : a_vector){
		item = gen()%100+1;//возвращает случайное число 
	}
	return a_vector;
}

double F(int a ){

	vector <int> a_vector = generator(a);

	double Vexp = (double)a/100;

	int arr[100];
	for (int i = 0; i < 100; i++) arr[i] = 0; //Vn
	for ( auto item : a_vector){
		arr[item - 1]++;
	}

	double x = 0;

	for ( auto Vn  : arr ){
		x += ((Vn - Vexp)*(Vn - Vexp))/Vexp;
	}

	return x;

}


int main(){

	cout << "count: " << 50 << "  x-sqr: " << F(50) << endl;
	cout << "count: " << 100 << "  x-sqr: " << F(100) << endl;
	cout << "count: " << 1000 << "  x-sqr: " << F(1000) << endl;

}

