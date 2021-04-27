#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n = 5;
	double sum = 0;
	double average;
	double sum_average;
	vector <int> a_vector(n);

	for (auto &item : a_vector)
		cin >> item;

	for (auto item : a_vector)
		sum += item;

	average = sum / n;
	cout << average << endl;

	for (auto item : a_vector)
		sum_average += (item - average)*(item - average);

	cout << sum_average << endl;


	for(int i = 1; i < n; ++i)
	{
		for(int r = 0; r < n-i; r++)
		{
			if((a_vector[r]-average)*(a_vector[r]-average)<(a_vector[r+1]-average)*(a_vector[r+1]-average))
			{
				int temp = a_vector[r];
				a_vector[r] = a_vector[r+1];
				a_vector[r+1] = temp;
			}
		}
	}

	for (auto item : a_vector)
		cout << item << " ";

}