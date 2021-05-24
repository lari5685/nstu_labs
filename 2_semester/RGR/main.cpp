#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Caesar.h"
#include "Viginer.h"
#include "XOR.h"
#include "FileWork.h"
using namespace std;

enum cryptDo {
	encrypt = 1,
	decrypt = 2
};

enum Ciphers {
	Caesar = 1,
	Viginer = 2,
	XOR = 3
};

int WillDo(string ans) {
	if ((ans[0] == 'e') || (ans[0] == '1'))
		return 1;
	if ((ans[0] == 'd') || (ans[0] == '2'))
		return 2;
	return 0;
}

void StringToInt(string text, string& ASCIItext) {
	ASCIItext = "";
	for (char item : text)
		ASCIItext += ' ' + to_string(int(item));
}

void IntToString(string ASCIItext, string& text) {
	vector<char> v;
	text = "";
	char temp = 0;
	int k = 0;
	for (char item : ASCIItext)
		if (item == ' ') {
			v.push_back(temp);
			k = 0; temp = 0;
		}
		else
			temp = (int(item)-'0') + temp * pow(10, k++);
	if (temp > 0)
		v.push_back(temp);

	for (char item : v)
		text += item;
}

int main() {
	string crypt_message;
	cout << " Enter your login password:\n ";
	string ans; cin >> ans;
	if (ans != "1")
		return -1;

	cout << " Hello, this program like to decrypt and encrypt your messege.\n";
	cout << " Enter number cipher method: \n\t1. Caesar.\n\t2. Viginer.\n\t3. XOR.\n\t ... in development\n";

	int method = Viginer; cin >> method;
	cout << " Good choice!\n What will we do? \n\t1. encrypt\n\t2. decrypt\n ";
	cin >> ans;
	while (!WillDo(ans)) {
		cout << "sorry, i didn't understand you, pls enter again\n "; cin >> ans;
	}
	int WhatDo = WillDo(ans);

	cout << " Good choice!\n Enter messege from ";
	(WhatDo == encrypt) ? cout << "encrypt:\n " : cout << "decrypt:\n ";
	string messege;
	string InputFileName = "INPUT.txt";
	char command[50] = "notepad.exe ";
	int k = 12;
	for (char item : InputFileName)
		command[k++] = item;
	system(command);
	fileInput(InputFileName.c_str(), messege);
	cout << " Good choise!\n ";

	if (method == Caesar) {
		cout << " Enter key from cipher(number):\n ";
		int key_num = 1; cin >> key_num;
		crypt_message = CaesarCipher(messege, key_num, WhatDo);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
	}
	if (method == Viginer) {
		cout << " Enter key from cipher(string):\n ";
		string key_str = "key"; cin >> key_str;
		crypt_message = ViginerCipher(messege, key_str, WhatDo);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
	}
	if (method == XOR) {
		if (WhatDo == decrypt)
			IntToString(messege, messege);
		cout << " Enter key from cipher(string):\n ";
		string key_str = "key"; cin >> key_str;
		crypt_message = XORCipher(messege, key_str);
		if (WhatDo == encrypt)
			StringToInt(crypt_message, crypt_message);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
	}
	cout << " I write your messege in file: OUTPUT.txt\n";

	k = 12;
	string OutputFileName = "OUTPUT.txt";
	fileOutput(OutputFileName.c_str(), crypt_message);
	for (char item : OutputFileName)
		command[k++] = item;
	system(command);


}