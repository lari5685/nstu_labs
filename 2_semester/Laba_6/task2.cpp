#include <iostream>
#include <vector>
using namespace std;

string decrypt(string messege, string key) {
	string encrypt_messege;
	string slovar = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ/.,|+=-_()*&^%$#@!?1234567890";
	int k = 0, index, n = slovar.size();
	for (char item : messege) {
		if (k == key.size())
			k = 0;
		index = (slovar.find(item) - slovar.find(key[k++])) % n;
		encrypt_messege += slovar[index < 0 ? index + n : index];
	}
	return encrypt_messege;
}

string encrypt(string messege, string key) {
	string crypt_messege;
	int k = 0, index;
	string slovar = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ/.,|+=-_()*&^%$#@!?1234567890";
	for (char item : messege) {
		if (k == key.size())
			k = 0;
		index = (slovar.find(item) + slovar.find(key[k++])) % slovar.size();
		crypt_messege += slovar[index];
	}
	return crypt_messege;
}

int main() {
	string messege = "Hello world", key = "Key";
	cout << messege << endl;
	cout << encrypt(messege, key) << endl;
	cout << decrypt(encrypt(messege, key), key) << endl;
}