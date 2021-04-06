#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <process.h>

void generate(int A[], int n, int max, int f_print){
	srand(_getpid());
	for (int i = 0; i<n; i++)
		A[i]=rand()%max;
	for (int i = 0; i<n && f_print == 1; i++)
		printf("%d, ", A[i]);
}
//---------------------------------------------------------

int A[10000];
int left[10000], right[10000];
int sort( int m, int n, unsigned long int T, int k){//n-начало m-конец t-сложность k-n
	if (m-n==1)
		return T;
	int cl=0, cr=0;
	int c = (m-n)/2+n;//centr kameri n-c-m
	int max=0, min=999999;

	for(int i=n; i<c; i++){
		if (A[i]>max){
			max = A[i];
			T++;
		}
	}
	for(int i=c; i<m; i++){
		if (A[i]<min){
			min = A[i];
			T++;
		}	
	}
	if(min >= max){
		return sort(c, n, T, k)+sort(m, c, T, k);
		//разделяем каждую часть на 2
	}

	for(int i=n; i<c; i++){
		if (A[i]>min){
			right[cr]=A[i];
			cr++; T++;
		}
		else{
			left[cl]=A[i];
			cl++; T++;
		}
	}
	for(int i=c; i<m; i++){
		if (A[i]<max){
			left[cl]=A[i];
			cl++; T++;
		}
		else{
			right[cr]=A[i];
			cr++; T++;
		}
	}
	for (int i=0; i<cl; i++){
		A[i+n]=left[i];
	}
	for (int i=0; i<cr; i++){
		A[i+n+cl]=right[i];
	}

	return sort(m, n, T, k);
}




int main(){
	int n = 100,s;
	generate(A, n, n, 1);
	s = sort(n, 0, 0, n);
	printf("\n%d\n", s);
	for (int i = 0; i<n; i++)
		printf("%d, ", A[i]);
}