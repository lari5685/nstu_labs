#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include<algorithm>



void create_train(std::map <std::string, std::set<std::string>>& Trains, std::map <std::string, std::set<std::string>>& Towns, std::string name_train, std::set<std::string> input)
{
	for (auto item : input) {
		Trains[name_train].insert(item);
		Towns[item].insert(name_train);
	}	
}
void trains_for_town(std::map <std::string, std::set<std::string>> Towns, std::string name)
{
	std::cout << std::endl << name << " : ";
	for (auto item : Towns[name])
		std::cout << item << " ";
	std::cout << std::endl;
}

void towns_for_train(std::map <std::string, std::set<std::string>> Trains, std::map <std::string, std::set<std::string>> Towns, std::string name)
{
	if (name != "") {
		std::cout << std::endl << name << " : ";
		for (auto item : Trains[name])
			std::cout << item << " ";
		std::cout << std::endl;
	}

	for (auto train : Towns) {
		std::cout << std::endl << train.first << " : ";
		for (auto item : train.second)
			if (item != name)
				std::cout << item << " ";
	}
	std::cout << std::endl;
}
void trains(std::map <std::string, std::set<std::string>> Trains, std::map <std::string, std::set<std::string>> Towns) {
	
	for (auto town : Trains) {
		std::cout << std::endl << town.first << " : ";
		for (auto item : town.second)
			std::cout << item << " ";
	}
	std::cout << std::endl;
}

int main()
{
	enum Comands{
		CREATE_TRAIN,
		TRAINS_FOR_TOWN,
		TOWNS_FOR_TRAIN,
		TRAINS
	};

	std::map <std::string, std::set<std::string>> Trains = { {"train", {"a", "b"}} }, Towns = { {"a", {"train"}}, {"b", {"train"}} };
	while (true) {
		std::string comand, input, argm = "", name = "";
		std::set<std::string> args;
		getline(std::cin, input);
		for (auto simbl : input) {
			if (simbl == ' ') {
				if (argm != "")
				if (comand == "") comand = argm;
				else if (name == "") name = argm;
				else args.insert(argm);
				argm = "";
			}
			else
				argm += simbl;
		}
		if (argm != "")
		if (comand == "") comand = argm;
		else if (name == "") name = argm;
		else args.insert(argm);
		argm = "";
		
		if (comand == "CREATE_TRAIN" || comand == std::to_string(CREATE_TRAIN))
			create_train(Trains, Towns, name, args);
		if (comand == "TRAINS_FOR_TOWN" || comand == std::to_string(TRAINS_FOR_TOWN))
			trains_for_town(Towns, name);
		if (comand == "TOWNS_FOR_TRAIN" || comand == std::to_string(TOWNS_FOR_TRAIN))
			towns_for_train(Trains, Towns, name);
		if (comand == "TRAINS" || comand == std::to_string(TRAINS))
			trains(Trains, Towns);
	}
}