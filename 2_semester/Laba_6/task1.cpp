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
	int N = 10, M = 10;
	//cin >> N >> M;
	vector<vector<__int64>> vec (N);

	task_1(vec, M);

	
	for (auto &vect : vec){
		for (auto &item : temp)
			cin >> item;
		vect = temp;
	}
	

	for (auto vect : vec){
		for (auto item : vect)
			cout << item << ' ';
		cout << endl;
	}


}