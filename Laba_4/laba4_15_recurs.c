#include <stdio.h>

void sum(int *s){
	int a=0, b, c=0;
	for(int i = 0; i < 3; i++) a = a*10 + s[i];
	b = 5+s[3]*10;
	for(int i = 4; i < 10; i++) c = c*10 + s[i];

	if (a*b ==c)
		printf("%d * %d = %d\n", a,b,c);
}

void def(int *f, int *out, int n){

	if (n == 9){
		sum(out);
	}
	for(int i = 0; i < 10; i++){
		if (f[i] == 1 && i != 5){
			f[i] = 0;
			out[n] = i;
			def(f, out, n+1);
			f[i] = 1;
		}
	}
}

void main()
{
	int f[10] = {1,1,1,1,1,1,1,1,1,1};
	int out[10];
	def(f,out,0);
}