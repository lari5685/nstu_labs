#include <stdio.h>
#include <string.h>
#include <math.h>

int XtoDEC_int(int a, int p)
{
	char q,k=0,l=1 ;
    int res = 0;
    while(a>0) {
    	q = a%10;
    	a = a/10;
        res += l*q;
        l*=p;
    }
    a = res;
    while(a>0) {
    	k++;
    	a = a/10;
    }
    return res*100+k;
    printf("%d::%d\n", res,k);
}	

	

int main() {
	XtoDEC_int(101,2);
	XtoDEC_int(761,8);
	char str[1000];
	char out[1000];
	gets(str);
	int p = 0, a = 0, b = 0;
	puts(str);
	for (int i = 0; str[i] != 0; i++) {
		if (fabs(str[i] - 53) <= 4) {//если нашли цифру
			a = str[i++] - 48; b = a;
			while (str[i] > 47 && str[i] < 58) {
				a = a * 10 + str[i] - 48;
				if (str[i] - 48 > b)
					b = str[i] - 48;
				i++;
			}
			int res = XtoDEC_int(a,b+1);
			int n = res%100;
			res /= 100;
			for(int j=n-1; j >= 0; j--){
				out[p+j]=res%10+'0';	
				res/=10;
				
			}
			p+=n;
			i--;
		}
		else
			out[p++] = str[i];
	}
	out[p]=0;
	for (int i = 0; i < p; i++)
		putchar(out[i]);
	printf("\nOK\n");
	gets(str);
}