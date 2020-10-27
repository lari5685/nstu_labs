#include <stdio.h>

//main_N() - процедура для запуска/проверки функции FN. присуствуют примеры.
//в main() собраны все процедуры(10).

//--------------------------------------------------------16 
//число а переносим посимвольно в массив А.
int* F16(long double a, int n) {
	int A[3000];
	int i;
	for (i = 0, n = a; n != 0; i++, n = n / 10);
	for (A[i--] = -1, n = a; n != 0; i--, n = n / 10)
		A[i] = n % 10;
	return A;
}
void main_16() {//start program number 16
	printf("N 16\n");
	int* A;
	int a = 123456789, n = 9;

	A = F16(a, n);

	printf("%d\n", a);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n\n");
}


//--------------------------------------------------------25
//удаление простых чисел из массиве А [со сдвигом в лево без обнуления]
void F25(int *A, int *b) {
	int n = *b, i, j, m;

	for (i = 0; i < n; i++) {
		for (m = 2; m < A[i]; m++)
		{
			if (A[i] % m == 0) break;
		}
		if (m == A[i]) {
			for (j = i; j < n - 1; j++) A[j] = A[j + 1];
			n--;
			i--;
		}
	}

	*b = n;
}

void main_25() {
	printf("N 25\n");
	int n = 10;
	int *A = F16(1234567890,n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	F25(A, &n);

	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n\n");
}


//--------------------------------------------------------28
//Поиск НОД среди чисел в массиве А
int F28(int* A, int n) {
	int v, s, i;

	v = A[0] + 1;
	do {
		v--;
		for (i = 0, s = 0; i < n; i++)
			if (A[i] % v != 0) { s = 1; break; }
	} while (s == 1);

	return v;
}

void main_28() {
	printf("N 28\n");
	int n = 8;
	int* A = F16(23456780, n); F25(A, &n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	printf("%d", F28(A,n)); printf("\n\n");
}

//--------------------------------------------------------31
//поиск 2 одинаковых элементов массива
int F31(int* c,int n) {
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (c[i] == c[j]) return i;
	return -1;
}

void main_31() {
	printf("N 31\n");
	int n = 9;
	int* A = F16(361427748, n); 
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");
	
	printf("%d", F31(A, n)); printf("\n\n");
}


//--------------------------------------------------------34
//возращает целую часть степени двойки
int F34(int n) {
	int k, m;

	for (k = 0, m = 1; m <= n; k++, m = m * 2);
	return k - 1;
}

void main_34() {
	printf("N 34\n");
	int n = 126;
	printf("%d\n", n);
	printf("%d", F34(n));
	printf("\n\n");
}


//--------------------------------------------------------35
//переворачивает массив 
void F35(int* c,int n) {
	int i, j, k;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		k = c[i];
		c[i] = c[j];
		c[j] = k;
	}
}

void main_35() {
	printf("N 35\n");
	int n = 8;
	int* A = F16(123456789, n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	F35(A, n);

	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n\n");
}


//--------------------------------------------------------40
//Сумма элементов до первого не положительного
int F40(int* A, int n) {
	int s, i;

	for (s = 0, i = 0; i < n && A[i]>0; i++)
		s = s + A[i];
	return s;
}

void main_40() {
	printf("N 40\n");
	int n = 9;
	int* A = F16(361407748, n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	printf("%d", F40(A, n)); printf("\n\n");
}


//--------------------------------------------------------46
//сортировка(выбором класическая) по убыванию [с 1 массивом]
void F46(int* A, int n) {
	int k, i, c;

	while (n != 0) {
		for (k = 0, i = 1; i < n; i++)
			if (A[i] < A[k]) k = i;
		c = A[k]; A[k] = A[n - 1]; A[n - 1] = c;
		n--;
	}
}

void main_46() {
	printf("N 46\n");
	int n = 8;
	int* A = F16(123456789, n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	F46(A, n);

	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n\n");
}


//--------------------------------------------------------48
//удаляет рядом стоящие 2 одинаковых элемента из массива 
void F48(int* A, int* m) {
	int i,j,n=*m;

	for (i = 0; i < n - 1; i++)
		if (A[i] == A[i + 1]) {
			for (j = i; j < n - 2; j++) A[j] = A[j + 2];
			n = n - 2;
			i--;
		}

	*m = n;
}

void main_48() {
	printf("N 48\n");
	int n = 8;
	int* A = F16(44722627, n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	F48(A, &n);

	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n\n");
}


//--------------------------------------------------------51
//поиск максимального положительного элемента массива
int F51(int* A, int n) {
	int i, s;

	for (i = 0, s = 0; i < 10; i++)
		if (A[i] > s) s = A[i];

	return s;
}

void main_51() {
	printf("N 51\n");
	int n = 9;
	int* A = F16(361407948, n);
	for (int il = 0; il < n; il++) printf("%d, ", A[il]); printf("\n");

	printf("%d", F51(A, n));
}





int main()
{	
	main_16();
	main_25();
	main_28();
	main_31();
	main_34();
	main_35();
	main_40();
	main_46();
	main_48();
	main_51();

	return 0;
}