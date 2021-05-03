/*

Выполнить программную реализацию метода «шаг младенца, шаг великана» и
алгоритма исчисления порядка и решить с помощью компьютера следующие
уравнения: 
	2^x mod 30203 = 24322

*/

#include <iostream>
#include <cmath>
#include <vector>

int stepen(int a, int b, int mod){
	int res = 1;
	for (int i = 0; i < b % mod; i++){
		res = (a * res) % mod; 
	}
	return res;
}

int find_x(int a, int p, int y){
	int m = (int)sqrt(p) + 1;
	std::vector<long int> u;
	for (int j = 1; j < m; j++)
		u.push_back(stepen(a, j*m, p));

	int find_j, find_i = 0;
	while (true){
		int v = (y * stepen(a, find_i, p) % p);

		int item = -1;
		for (int i = 0; i < u.size(); i++)
			if (u[i] == v){
				item = i;
				break;
			}

		if(item != -1){
			find_j = item + 1;
			break;
		}
		
		find_i += 1;
	}
	int x = (m * find_j - find_i) % p;

	return x;
}	
int main(){
	std::cout << "2^" << find_x(2, 30203, 24322) << " mod 30203 = 24322"<<std::endl;
}