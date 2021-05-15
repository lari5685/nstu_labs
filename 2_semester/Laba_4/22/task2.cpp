#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int n = 5;

	vector <string> a_vector(n);

	for (auto &item : a_vector)
		cin >> item;
	reverse( a_vector.begin(), a_vector.end());

	vector <string> b_vector;
	for ( string item : a_vector ){

		int a;
		reverse(item.begin(), item.end());
		a = atoi(item.c_str());  //переводит строку в число
		b_vector.push_back(to_string(a));
	}

	for (auto &item : b_vector){
		cout << item << " ";
	
	}

	
}