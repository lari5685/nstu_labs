//Вариант:2     2^x mod 30323 = 21740

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int stepen( int a, int n, int mod){
	int res = 1;						// res от а^n % mod 
	for (int i = 0; i<n; i++){
		res = (res*a) % mod;
	}
	return res;
}


int step( int a, int b, int p){ //a^x=b mod p
	int m = sqrt(p) + 1;
	vector <int> a_vector;
	for (int i = 0; i < m; i++){
		a_vector.push_back(stepen(a, (i+1)*m, p));    //i+1 тк в цикле i=[0,m-1], а рсчёт идет от 1 до m
	}

	for ( int j = 0; j < m; j++){
		int temp = stepen(a,j,p)*b % p;    // функция считает степень а^j, умножает на b и берет значение по модулю
		for (int i = 0; i < m; i++){
			if (a_vector[i] == temp){
				return (i+1)*m - j;      // вывод х
			}
		}
	}

}

int main(){
	cout << "x: " << step(2, 21740, 30323) << endl;
}