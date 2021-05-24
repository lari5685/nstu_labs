#include <string>
#include "XOR.h"


std::string XORCipher(std::string messege, std::string key) {
	int k = -1;
	std::string resMessege = "";
	for (char item : messege) {
		resMessege += item ^ key[(++k) % key.size()];
	}
	return resMessege;
}