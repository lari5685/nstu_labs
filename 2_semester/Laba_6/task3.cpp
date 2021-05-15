#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void FancyPrint(vector<vector<double>> &A, vector<double> &B){
	for (int row = 0; row < B.size(); row++){
		cout << "(";
		for (int col = 0; col < A[row].size(); col++)
			cout << "\t" << A[row][col] << "\t"; 
		cout << " ) * (X" << row+1 << ") = ( " << B[row] << " )" << endl;
	}
	cout << endl;
}

void SwapRows(vector<vector<double>> &A, vector<double> &B, int row1, int row2){
	vector<double> temp_vector = A[row1];
	double temp_double = B[row1];
	A[row1] = A[row2]; A[row2] = temp_vector;
	B[row1] = B[row2]; B[row2] = temp_double;
}

void DivideRow(vector<vector<double>> &A, vector<double> &B, int row, double divider){
	for (auto &item : A[row])
		item /= divider;
	B[row] /= divider;
}

void CombineRows(vector<vector<double>> &A, vector<double> &B, int row, int source_row, double r){
	for (int i = 0; i < A[row].size(); i++)
		A[row][i] = A[row][i]-A[source_row][i]*r;
	B[row] -= B[source_row] * r;
}

int main(){
	double M = -0.77, N=0.16, P = 1.12 ;
	vector<vector<double>> A = {{M, -0.04, 0.21, -18},
 							 	{0.25, -1.23, N, -0.09},
 							 	{-0.21, N, 0.8, -0.13},
 							 	{0.15, -1.31, 0.06, P}};

	vector<double> B = 			{-1.24, P, 2.56, M};

	int column = 0;
	while (column < B.size()){
		cout << "Ищем максимальный по модулю элемент в "<<column+1<<"-м столбце:" << endl;
		int current_row = -1;
		for (int r = column; r < A.size(); r++) // поиск максимальной строки
			if (current_row == -1 || abs(A[r][column]) > abs(A[current_row][column]))
				current_row = r;
		if (current_row == -1){
			cout << "решений нет" << endl;
			return -1;
		}

		FancyPrint(A, B);
		if (current_row != column){
			cout << "Переставляем строку с найденным элементом повыше:" << endl;
			SwapRows(A, B, current_row, column);
			FancyPrint(A, B);
		}	
		cout << "Нормализуем строку с найденным элементом:" << endl; 
		DivideRow(A, B, column, A[column][column]);
		FancyPrint(A, B);
		cout << "Обрабатываем нижележащие строки:" << endl;
		for (int r = column+1; r < A.size(); r++)
			CombineRows(A, B, r, column, A[r][column]);
		FancyPrint(A, B);
		column++;
	}
	cout << "Матрица приведена к треугольному виду, считаем решение"<<endl;
	vector<double> X(B.size());
	for (int i = B.size()-1; i > -1; i--){
		double sum = 0;
		for (int r = i+1; r < X.size(); r++)
			sum += X[r]*A[i][r];
		X[i] = B[i] - sum;
	}
	cout << "Получили ответ:" << endl;
	for(auto item : X)
		cout << item << endl;
}