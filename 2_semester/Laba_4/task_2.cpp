#include <iostream>
#include <vector>
#include <random>
#include <ctime>

std::vector<int> generator(int count){
	std::minstd_rand gen;
	gen.seed(time(0));
	std::vector<int> main_list;
	for(int i = 0; i < count; i++){
		main_list.push_back(gen()%200-100);
	}
	return main_list;
}

void sort(std::vector<int> &main_list, int first, int second){
	int temp;
	for (int i = first; i <= second; i++)
		for (int j = i; j <= second; j++)
			if (main_list[i] < main_list[j]){
				temp = main_list[i];
				main_list[i] = main_list[j];
				main_list[j] = temp;
			}
}

int main(){
	int count = 10, a = 2, b = 8;
	std::vector<int> main_list, sorted_list;
	//std::cin >> count;	
	//std::cin >> a;	
	//std::cin >> b;	

	main_list = generator(count);
	for (auto element : main_list){
		std::cout << element << " ";
	}
	std::cout << std::endl;

	sort(main_list, a, b);

	for (auto element : main_list){
		std::cout << element << " ";
	}
	std::cout << std::endl;


}