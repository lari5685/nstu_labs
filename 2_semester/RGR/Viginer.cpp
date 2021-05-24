#include <string>
#include "viginer.h"


static int mod(int a, int b) {
	return (a % b >= 0) ? a % b : a % b + b;
}

enum cryptDo {
	encrypt = 1,
	decrypt = 2
};

std::string ViginerCipher(std::string messege, std::string key, int WhatDo) {// ASCII: 32 - 126
	int p = (WhatDo == decrypt) ? 1 : -1;
	std::string resMessege = "";
	int k = -1;
	for (char item : messege)
		resMessege += char(mod((int)item + p * (int)(char)key[(++k) % key.size()] - 32, 95) + 32);
	return resMessege;
}