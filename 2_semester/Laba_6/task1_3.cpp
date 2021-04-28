#include <iostream>
#include <vector>
using namespace std;

bool is_main_simetr(vector<vector<int>>& vec) {
	int n = vec.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (vec[i][j] != vec[j][i])
				return	false;
	return	true;
}

bool is_nomain_simetr(vector<vector<int>>& vec) {
	int n = vec.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - (i + 1); j++)
			if (vec[i][j] != vec[n - 1 - j][n - 1 - i])
				return	false;
	return	true;
}

int main()
{
	int n = 3;
	cin >> n;
	vector<vector<int>> main_vector(n);
	for (auto& line : main_vector)
		for (auto i : main_vector)
			line.push_back(rand() % 5 + 1);

	for (auto line : main_vector) {
		for (auto item : line)
			cout << item << ' ';
		cout << endl;
	}

	is_main_simetr(main_vector)  ? cout << "YES" << endl : cout << "NO" << endl;
	is_nomain_simetr(main_vector)? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}