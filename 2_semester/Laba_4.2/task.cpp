#include <iostream>
#include <cmath>
using namespace std;

int64_t sliv(int64_t res, string ans, int n) {
	if (n == 0)
		return res;
	int number = n;
	int k = 1;
	for (int i = n - 1; i > 0; i--) {
		if (ans[i - 1] == '+') {
			res = res - number + number * 10 + n + 1;
			return res;
		}
		if (ans[i - 1] == '-') {
			res = res + number - number * 10 - n - 1;
			return res;
		}
		if (ans[i - 1] == '_') {
			number += i * pow(10, k);
			k += 1;
		}
	}
	return res - number + number * 10 + n + 1;
}

string fun(int64_t m, int n, int64_t res, string &ans) {
	if (n == 9) {
		if (res == m)
			ans[8] = '2';
		else
			ans[8] = '1';
		return ans;
	}
	ans[n - 1] = '+';
	if (fun(m, n + 1, res + n + 1, ans)[8] == '2')
		return ans;
	ans[n - 1] = '-';
	if (fun(m, n + 1, res - n - 1, ans)[8] == '2')
		return ans;
	ans[n - 1] = '_';
	if (fun(m, n + 1, sliv(res, ans, n), ans)[8] == '2')
		return ans;
	return ans;
}

int main() {
	string ans = "000000000";
	string a = fun(1-2+3+456-7+89, 1, 1, ans);
	if (a[8] != '2'){
		cout << "not found";
		return -1;
	}
	for (int i = 0; i < 8; i++) {
		cout << i + 1;
		if (a[i] != '_')
			cout << ' ' << a[i] << " ";
	}
	cout << 9;
}