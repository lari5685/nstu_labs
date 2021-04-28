#include <iostream>
#include <vector>
using namespace std;

string decrypt(string messege, string key){
	string encrypt_messege;
	int k = 0;
	string slovar = "abcdefghijklmnopqrstuvwxyz ";
	for (char item : messege){
		encrypt_messege += slovar[(slovar.find(item) - slovar.find(key[k++]))%slovar.size()];
		if (k == key.size()-1)
			k = 0;
	}
	return encrypt_messege;   
}

string encrypt(string messege, string key){
	string crypt_messege;
	int k = 0;
	string slovar = "abcdefghijklmnopqrstuvwxyz ";
	for (char item : messege){
		crypt_messege += slovar[(slovar.find(item) + slovar.find(key[k++]))%slovar.size()];
		if (k == key.size()-1)
			k = 0;
	}
	return crypt_messege;   
}

int main(){
	string messege = "hello world", key = "a";
	cout << messege << endl;
	cout << encrypt(messege, key) << endl;
	cout << decrypt(encrypt(messege, key), key) << endl;
}