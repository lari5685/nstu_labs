#include <string>
#include <cmath>
#include "A1Z23.h"

std::string A1Z23Cipher(std::string messege, int crypt) { 	
	std::string res = "";
	int temp = 0, k = 0;

	if (crypt == 1){
		for(int item : messege){
			if (item < 65) 					//NoLetter
				res += '0';
			else if (item < 91) 			//A-Z
				res += std::to_string(item - 64);
			else if (item < 97) 			//NoLetter
				res += '0';
			else if (item < 123) 			//a-z
				res += std::to_string(item - 96+26);
			else 							//NoLetter
				res += '0';
			res += ',';
		}
		res.erase(res.size()-1, 1);
	}
	else{
		for (char item : messege)
			if (item == ',') {
				if (temp == 0)
					res += '_';
				else if (temp <= 26)
					res += (char)(temp + 64);
				else if (temp <= 26*2)
					res += (char)(temp + 96 - 26);

				k = 0; temp = 0;
			}
			else
				temp = (int(item)-'0') + temp * pow(10, k++);

			if (temp != 0)
				if (temp == 0)
					res += '_';
				else if (temp <= 26)
					res += (char)(temp + 64);
				else if (temp <= 26*2)
					res += (char)(temp + 96 - 26);

				k = 0; temp = 0;
		
	}
	return res;
}