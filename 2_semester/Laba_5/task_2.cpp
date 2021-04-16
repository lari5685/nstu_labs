#include <map>
#include <set>
#include <string>
#include <iostream>

void add_friend(std::map <std::string, std::set<std::string>>& friends, std::string name_1, std::string name_2)
{
	friends[name_1].insert(name_2);
	friends[name_2].insert(name_1);
}
int count_friend(std::map <std::string, std::set<std::string>> friends, std::string name_1)
{
	return friends[name_1].size();
}
bool is_friend(std::map <std::string, std::set<std::string>> friends, std::string name_1, std::string name_2)
{
	for (auto item : friends[name_1])
		if (item == name_2)
			return true;
	return false;
}

int main()
{
	std::map <std::string, std::set<std::string>> friends;
	while (true) {
		std::string comand, name_1, name_2;
		std::cin >> comand >> name_1;

		if (comand != "COUNT" && comand != "1")
			std::cin >> name_2;

		if (comand == "FRIENDS" || comand == "0")
			add_friend(friends, name_1, name_2);
		if (comand == "COUNT" || comand == "1")
			std::cout << count_friend(friends, name_1) << std::endl;
		if (comand == "QUESTION" || comand == "2") {
			is_friend(friends, name_1, name_2) ? std::cout << "YES" : std::cout << "NO";
			std::cout << std::endl;
		}

	}
}