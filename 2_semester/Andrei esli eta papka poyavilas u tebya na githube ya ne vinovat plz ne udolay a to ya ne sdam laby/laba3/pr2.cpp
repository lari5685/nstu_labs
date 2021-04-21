#include <iostream>
#include <cmath>
using namespace std;

double arctg_x(double x, int n) {
	double s = 0;
	for (int i = 0; i < n; i++)
		s += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
	return s;
}

int main() {
	int e;
	cin >> e;

	for (double i = -1; i <= 1; i += 0.3)
	{
		cout.precision(e);
		cout << i << " : " << arctg_x(i, 10) << " : " << atan(i) << endl;
	}
}