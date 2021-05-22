#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum cryptDo{
	encrypt = 1,
	decrypt = 2
};
enum Ciphers{
	Caesar = 1,
	Viginer = 2,
	XOR = 3
};

int WillDo(string ans){
	if ((ans[0] == 'e') || (ans[0] == '1'))
		return 1;
	if ((ans[0] == 'd') || (ans[0] == '2'))
		return 2;
	return 0;
}

void fileInput(string FileName, string &messege){
	string text;
	ifstream fin(FileName);
	while(!fin.eof()) {
		fin >> text;
		messege += text + " ";
	}
	if (messege.size() > 0)
		messege.erase(messege.end()-1);  
}

int mod(int a, int b){
	return (a%b >= 0) ? a%b : a%b + b;
}

string CaesarCipher(string messege, int key, int WhatDo){// ASCII: 32 - 126
	key *= (WhatDo == decrypt) ? 1 : -1;
	string resMessege = "";
	for (char item : messege)
		resMessege += char(mod((int)item + key - 32, 95) + 32);
	return resMessege;
}

string ViginerCipher(string messege, string key, int WhatDo){// ASCII: 32 - 126
	int p = (WhatDo == decrypt) ? 1 : -1;
	string resMessege = "";
	int k = -1;
	for (char item : messege)
		resMessege += char(mod((int)item + p*(int)(char)key[(++k)%key.size()] - 32, 95) + 32);
	return resMessege;
}

string XORCipher(string messege, string key){
	int k = -1;
	string resMessege = "";
	for (char item : messege){
		resMessege += item ^ key[(++k)%key.size()];
	}
	return resMessege;
}


int main(){
	cout << " Enter your login password\n";
	string ans; cin >> ans;
	if (ans != "1")
		return -1;

	cout << " Hello, this program like to decrypt and encrypt your messege.\n";
	cout << " Enter number cipher method: \n\t1. Caesar.\n\t2. Viginer.\n\t3. XOR.\n";
	
	int method = Viginer; cin >> method; 
	cout << " Good choice!\n What will we do? \n\t1. encrypt\n\t2. decrypt\n";
	cin >> ans;
	while(!WillDo(ans)){
		cout << "sorry, i didn't understand you, pls enter again\n"; cin >> ans;
	}
	int WhatDo = WillDo(ans);

	cout << " Good choice!\n Enter messege from ";
	(WhatDo == encrypt) ? cout << "encrypt:\n" : cout << "decrypt:\n";
	string messege;
	char FileName[50] = "INPUT.txt";
	char command[50] = "notepad.exe INPUT.txt";
	system(command);
	fileInput(FileName, messege);
	cout << " Good choise!\n";

	if (method == Caesar){
		cout << " Enter key from cipher(number):\n";
		int key_num = 1; cin >> key_num;
		string crypt_message = CaesarCipher(messege, key_num, WhatDo);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
	}
	if (method == Viginer){
		cout << " Enter key from cipher(string):\n";
		string key_str = "key"; cin >> key_str;
		string crypt_message = ViginerCipher(messege, key_str, WhatDo);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
	}
	if (method == XOR){
		cout << " Enter key from cipher(string):\n";
		string key_str = "key"; cin >> key_str;
		string crypt_message = XORCipher(messege, key_str);
		cout << " Good job! Your messeg: ";
		cout << crypt_message << endl;
		cout << XORCipher(crypt_message, key_str) << endl;
	}


}