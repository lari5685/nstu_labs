#include <iostream>
#include <vector>
using namespace std;

void outdomino(vector<pair<int,int>> &spisok, vector<int> &keys, int n){
	for (auto item : keys){//вывод последовательности
		if (item == -1)
			break;
		cout << spisok[item].first << '/' << spisok[item].second << ' ';
	}
	cout << endl;
}

void revers(vector<pair<int,int>> &a, int n){//переворачивает кость
	int temp = a[n].first;
	a[n].first = a[n].second;
	a[n].second = temp;
}

void domino(vector<pair<int,int>> &spisok, vector<int> &keys, int n){
	bool is_find = false;
	if (n == keys.size()){ //если все кости раставлены, выводим и выходим
		outdomino(spisok, keys, n);
		return;
	}
	for (int i = 0; i < spisok.size(); ++i){
		bool is_repit = false;
		for (auto &item : keys)
			if (item == i){
				is_repit = true;
				break;
			}
		if (is_repit)//если такая уже использовалась, пропускаем шаг
			continue;
		if (n == 0){
			//если мы в первые зашли в рекурсию
			is_find = true;
			keys[0] = i;
			domino(spisok, keys, 1);
			if (spisok[i].first != spisok[i].second){
				revers(spisok, i);
				domino(spisok, keys, 1);
				revers(spisok, i);
			}
			continue;
		}
		if (spisok[i].first == spisok[keys[n-1]].second){ 
			//если 2 номер на прошлой кости совпадает с 1 номером i-ой кости
			keys[n] = i;
			domino(spisok, keys, n+1);
			keys[n] = -1;
			is_find = true;
		}
		if (spisok[i].second == spisok[keys[n-1]].second && spisok[i].second != spisok[i].first){
			//если 2 номер на прошлой кости совпадает с 2 номером i-ой кости и кость не семетрична
			keys[n] = i;
			revers(spisok, i);
			domino(spisok, keys, n+1);
			revers(spisok, i);
			keys[n] = -1;
			is_find = true;
		}
	}
	if (!is_find)
		outdomino(spisok, keys, n);
	return;
}
	
int main(){
	vector<pair<int,int>> spisok = {{1,2}, {2,3}, {5,6}, {2,2}, {5,3}};
	vector<int> keys;
	for(int i = 0; i < spisok.size(); ++i)
		keys.push_back(-1);

	domino(spisok, keys, 0);
}