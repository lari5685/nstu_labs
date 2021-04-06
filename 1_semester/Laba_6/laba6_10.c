#include <stdio.h>
#include <string.h>
#include <math.h>

void F(char c[], int nn)
{ 
	int k,mm;
	for (mm=nn, k=0; mm !=0; mm /=10 ,k++);
	for (c[k--]='\0'; k>=0; k--){ 
		c[k]= nn % 10 + '0'; 
		nn /=10; 
	}
}

int main() {
	char c[20], c1[] = "gg71hcfbdfF";
	int a = 923;
	F(c,a);
	printf("%d\n",a);
	for(int i=0; c[i]!='\0';i++)
		printf("%c",c[i]);
}