#include <iostream>
#include <vector>

int modul(int number, int power, int div) //find modul in a^x mod m = modul task3
{
    power = power % (div-1);
    number = number % div;
    int res = 1;
    for (int x =1; x<=power; x++)
    {
        res *= number;
        res = res % div;
    }
    return res;
}
int find_d(int number, int divisor) //find D in C*D mod m = 1 task4
{
    int z, z_1=1, z_2=0, q, remainder, first = divisor, second = number;
    q=(first / second);
    remainder = (first % second);

    while (remainder !=0 )
    {
        z=z_2-q*z_1;
        first = second;
        second = remainder;
        q=(first / second);
        remainder = (first % second);
        z_2=z_1;
        z_1=z;
    }

    if (z < 0) z += divisor;

    return z;
}

std::vector<int> decode(std::string line){ // string to vector <int>
	std::vector<int> decode_line;
	for (char item : line)
		decode_line.push_back((int)item);
	return decode_line;
}

int main(){
	int public_key = 293;

	int private_key_C, private_key_D, temp;
	char answer;

	std::cout << "Enter your privat key: ";
	std::cin >> private_key_C;
	private_key_D = find_d(private_key_C, public_key-1);

	std::cout << "Send or receive(s/r): ";
	std::cin >> answer;

	if (answer == 's'){
		std::cout << "Enter your message: ";
		std::string line;
		std::cin >> line;												// m
		std::vector<int> dec_line = decode(line);

		std::cout << "Say this key B(x1): ";
		for (auto item : dec_line)
			std::cout << modul(item, private_key_C, public_key) << " "; // x1
		std::cout << std::endl;

		std::cout << "Enter code from B(x2): ";
		std::vector<int> x2_line;
		for (int i = 0; i < dec_line.size(); i++){
			std::cin >> temp;											// x2
			x2_line.push_back(temp);
		}
		std::cout << "Say this key B(x3): ";
		for (auto item : x2_line)
			std::cout << modul(item, private_key_D, public_key) << " "; // x3

	}

	else if (answer == 'r'){
		int n; //size message
		std::cout << "Enter size message: ";
		std::cin >> n;
		std::cout << "Enter code from A(x1): ";
		std::vector<int> x1_line;
		for (int i = 0; i < n; i++){
			std::cin >> temp;											// x1
			x1_line.push_back(temp);
		}
		std::cout << "Say this key A(x2): ";
		for (auto item : x1_line)
			std::cout << modul(item, private_key_C, public_key) << " "; // x2
		std::cout << std::endl;

		std::cout << "Enter code from A(x3): ";
		std::vector<int> x3_line;
		for (int i = 0; i < n; i++){
			std::cin >> temp;											// x3
			x3_line.push_back(temp);
		}

		std::cout << "Your message: ";
		for (auto item : x3_line)
			std::cout << (char)modul(item, private_key_D, public_key); // x4 or m
	}
}