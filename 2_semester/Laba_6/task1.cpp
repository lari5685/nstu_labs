#include <iostream>
#include <vector>
using namespace std;

void task_1(vector<vector<__int64>> &vec, int M){
	vector<__int64> temp (M);
	for (auto &item : vec){
		for (int i = 0; i < M; i++)
			temp[i] = 10000000000 * (i+1);
		item = temp;
	}
}

int main(){
	int N = 3, M = 3;
	//cin >> N >> M;
	vector<__int64> temp(M);
	vector<vector<__int64>> vec (N);

	task_1(vec, M);

	for (auto vect : vec){
		for (auto item : vect)
			cout << item << ' ';
		cout << endl;
	}

	for (auto &vect : vec){
		for (auto &item : temp)
			cin >> item;
		vect = temp;
	}
	
	__int64 max=-10000000, min = 10000000;
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