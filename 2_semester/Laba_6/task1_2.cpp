#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){

	int N = 3, M = 3;
	cin >> N >> M;
	vector<int> temp(M);
	vector<vector<int>> vec (N);

	for (auto &vect : vec){
		for (auto &item : temp)
			cin >> item;
		vect = temp;
	}
	
	int64_t max= INT_MIN, min = INT_MAX;
	int max_index, min_index;
	for (int i = 0; i < N; i++){
		for (auto item : vec[i]){
			if (item > max){
				max = item;
				max_index = i;
			}
			if (item < min){
				min = item;
				min_index = i;
			}
		}
	}

	vec[max_index].swap(vec[min_index]);

	for (auto vect : vec){
		for (auto item : vect)
			cout << item << ' ';
		cout << endl;
	}
}