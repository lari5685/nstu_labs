#include <iostream>
#include <vector>

std::vector<int> generator(int count){
	std::vector<int> main_list;
	for(int i = 0; i < count; i++){
		main_list.push_back(rand()%200-100);
	}
	return main_list;
}

int task_1(std::vector<int> main_list){
	int sumElemets = 0;
	for (auto element : main_list){
		if (element < 0){
			sumElemets += element;
		}
	}
	return sumElemets;
}
int find_min_element(std::vector<int> v){
	int min = 101;
	int min_index = -1;
	for (int i = 0; i < v.size(); i++)
		if (v[i] < min){
			min = v[i];
			min_index = i;
		}
	return min_index;
}
int find_max_element(std::vector<int> v){
	int max = -101;
	int max_index = -1;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > max){
			max = v[i];
			max_index = i;
		}
	return max_index;
}

int task_2(std::vector<int> main_list){
	int max_index = find_max_element(main_list);
	int min_index = find_min_element(main_list);

	int min = (min_index < max_index) ? min_index : max_index;
	int max = (min_index < max_index) ? max_index : min_index;

	int multiply = 1;

	for (int i = min; i < max; i++){
		multiply *= main_list[i];
	}
	return multiply;
}

void task_3(std::vector<int> &main_list){
	int temp;
	for (int i = 0; i < main_list.size(); i++)
		for (int j = i; j < main_list.size(); j++)
			if (main_list[i] < main_list[j]){
				temp = main_list[i];
				main_list[i] = main_list[j];
				main_list[j] = temp;
			}
}


int main(){
	int count = 10;
	std::vector<int> main_list;
	//std::cin >> count;	

	main_list = generator(count);
	for (auto element : main_list){
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << task_1(main_list) << std::endl;

	std::cout << task_2(main_list) << std::endl;

	task_3(main_list);
	for (auto element : main_list){
		std::cout << element << " ";
	}
	std::cout << std::endl;

}