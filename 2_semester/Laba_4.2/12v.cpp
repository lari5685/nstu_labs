#include <iostream>
#include <vector>
using namespace std;

bool graf(vector<vector<int>> &gr, vector <int> &color, int k){
	int n = gr.size();
	bool is_find = false;
	if (k == 0){
		color[0] = 1;
		graf(gr, color, 1);
		return true;
	}
	if (k == n){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (gr[i][j] == 1 && color[i] == color[j])
					return false;
		return true;
	}
	while (!is_find){
		color[k] = color[k] + 1;
		if (color[k] > n){
			color[k] = 0;
			return false;
		}
		is_find = graf(gr, color, k+1);
	}
	return true;
}

int main(){
	vector<vector<int>> l = {{0,0,0,0,0,0,0,1,0,0,},
                    {0,0,0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,0,0,1,0,1},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,1,1,0},
                    {0,0,0,0,0,0,0,1,0,0}, 
                    {1,1,1,1,0,1,1,0,1,1}, 
                    {0,0,0,0,0,1,0,1,0,0},
                    {0,0,0,1,0,0,0,1,0,0},
	};

	vector<int> colors;
		for(int i = 0; i < l.size(); ++i)
			colors.push_back(0);

	graf(l, colors, 0);
	int max = 0;
	for (auto item : colors){
		cout << item << " ";
		if (item > max)
			max = item;
	}
	cout << endl << max << endl;
}