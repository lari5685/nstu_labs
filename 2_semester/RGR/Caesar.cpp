#include <string>
#include "Caesar.h"


static int mod(int a, int b) {
	return (a % b >= 0) ? a % b : a % b + b;
}

enum cryptDo {
	encrypt = 1,
	decrypt = 2
};

std::string CaesarCipher(std::string messege, int key, int WhatDo) {// ASCII: 32 - 126
	key *= (WhatDo == decrypt) ? 1 : -1;
	std::string resMessege = "";
	for (char item : messege)
		resMessege += char(mod((int)item + key - 32, 95) + 32);
	return resMessege;
}