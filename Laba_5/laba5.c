#include <stdio.h>
#include <math.h>

double sum(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 0, sn = 1, n = 1; fabs(sn) > eps; n++){
		s += sn;
		sn = -sn * x*x/(2*n*(2*n-1));
	}
	*m = n;
	return s;
}

int main(){ 
	int nn;
	double x;
	for (x=0; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t cos=%0.4lf\n", nn,x, sum(x, 0.00001, &nn), cos(x));
}
