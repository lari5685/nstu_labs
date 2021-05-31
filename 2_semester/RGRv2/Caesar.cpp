#include <string>
#include "Caesar.h"

std::string CaesarCipher(std::string messege, int key, int crypt) {
	std::string slovar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int n = slovar.size();

	if (crypt == 1)
		key = key * -1;
	key = key % n;
	std::string res = "";
	for (char item : messege)
		res = res + slovar[(slovar.find(item) + key) % n];
	return res;
}