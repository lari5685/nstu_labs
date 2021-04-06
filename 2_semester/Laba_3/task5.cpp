#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <string>
using namespace std;

bool is_simpl(int x) {
	int n = x / 2 + 2;
	int	a[1000];
	for (int i = 0; i < n+1; i++) a[i] = i;
	a[1] = 0;
	int k = 0,i = 2;
	while (i <= n) {
		if (a[i] != 0) {
			if (x % a[i] == 0)
				return false;
			for (int j = i; j < n + 1; j++)
				a[j] = 0;
		}
		i++;
	}
	return true;
}

unsigned int task_3(unsigned int number, unsigned int power, unsigned int div) {
	number %= div;
	unsigned int mod = 1;
	for (int i = 0; i < power; i++) {
		mod *= number;
		mod %= div;
	}	
	return mod;
}

unsigned int create_open_key(unsigned int *p) {
	unsigned int g, q;
	
	q = rand() % 900 + 100;
	*p = 2 * q + 1;
	while (!is_simpl(*p) || !is_simpl(q)) {
		q = rand()%900 + 100;
		*p = 2 * q + 1;
	}

	g = rand() % 900 + 100;
	while (task_3(g, q, *p) == 1 or g >= *p) {
		g = rand() % 900 + 100;
	}
	return g;
}

unsigned int create_close_key(unsigned int p, unsigned int g, unsigned int *Y) {
	unsigned int X;
	X = rand() % 10000 + 500;
	*Y = task_3(g, X, p);
	return X;
}

string send_messege(string message, unsigned int Z) {
	string code;
	string alpha = " abcdefghijklmnopqrstuvwxyz,.!?*1234567890=-+";
	Z %= alpha.length();
	for (int i = 0; i < message.length(); i++)
		code += alpha[(alpha.find(message[i]) + Z) % alpha.length()];
	return code;
}

string accept_massege(string code, unsigned int Z) {
	string message;
	string alpha = " abcdefghijklmnopqrstuvwxyz,.!?*1234567890=-+";
	Z %= alpha.length();
	for (int i = 0; i < code.length(); i++)
		message += alpha[(alpha.find(code[i]) - Z) % alpha.length()];
	return message;
}

int main()
{
	srand(time(0));
	unsigned int p, g, interlocutor_pub_key, X, Z, Y;
	g = create_open_key(&p);
	cout << "p = "<< p << " g = " <<g << endl;
	X = create_close_key(p, g, &Y);
	cout << "You publish key: " << Y << ". Sey interlocutor." << endl;
	cout << "Enter publish key interlocutor: ";
	cin >> interlocutor_pub_key;
	Z = task_3(interlocutor_pub_key, X, p);
	//Z = 5;
	char send_mes;
	while (true) {
		cout << "Send or accept? s/a: ";
		cin >> send_mes;
		cout << endl;
		cin.ignore(32767, '\n');
		if (send_mes == 's') {
			string message, code;
			cout << "enter you message: ";
			getline(cin, message);
			code = send_messege(message, Z);
			cout << "You code: " << code << endl;
		}
		else if (send_mes == 'a') {
			string message, code;
			cout << "enter you code: ";
			getline(cin, code);
			message = accept_massege(code, Z);
			cout << "You message: " << message << endl;
		}
	}
}