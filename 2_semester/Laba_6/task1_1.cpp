#include <iostream>
#include <vector>
using namespace std;

void task_1(vector<vector<int64_t>> &vec, int M){
	vector<int64_t> temp (M);
	for (auto &item : vec){
		for (int i = 0; i < M; i++)
			temp[i] = 10000000000 * (i+1);
		item = temp;
	}
}

int main(){
	int N = 3, M = 3;
	cin >> N >> M;
	vector<int64_t> temp(M);
	vector<vector<int64_t>> vec (N);

	task_1(vec, M);

	for (auto vect : vec){
		for (auto item : vect)
			cout << item << ' ';
		cout << endl;
	}
}