#include <stdio.h>
#include <math.h>

//1. cos(x) sn: -x^2/(2n(2n-1))
double sum1(double x,double eps,int *m){
	double s, sn;
	int n; 
	for(s = 0, sn = 1, n = 1; fabs(sn) > eps; n++){
		s += sn;
		sn = -sn * x*x/(2*n*(2*n-1));
	}
	*m = n;
	return s;
}

//2. ln(x) sn: (2n-3)z^2/(2n-1) 
double sum2(double x,double eps,int *m){
	double s, sn, z=(x-1)/(x+1);
	int n; 
	for(s = 0, sn = 2*z, n = 2; fabs(sn) > eps; n++){
		s += sn;
		sn = sn * (2*n-3)*z*z/(2*n-1);
	}
	*m = n;
	return s;
}

//3. 3^x sn: x*ln(3)/n 
double sum3(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 1, sn = x*log(3), n = 2; fabs(sn) > eps; n++){
		s += sn;
		sn = sn * x*log(3)/n;
	}
	*m = n;
	return s;
}

//4. ln(x) sn: (n-1)*(x-1)/(n*x)
double sum4(double x, double eps, int* m) {
    double s, sn;
    int n;
    for (s = 0, sn = (x - 1) / x, n = 2; fabs(sn) > eps; n++) {
        s += sn;
        sn = sn * (n-1)*(x-1)/(n*x);
    }
    *m = n;
    return s;
}

//5. sh(x) sn: x*x/((2*n-1)*(2*n-2));
double sum5(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 0, sn = x, n = 2; fabs(sn) > eps; n++){
		s += sn;
		sn = sn * x*x/((2*n-1)*(2*n-2));
	}
	*m = n;
	return s;
}

//6. ch(x) sn: 1 + x2/2! + x4/4! +…+ x2n/(2n)!
double sum6(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 0, sn = 1, n = 1; fabs(sn) > eps; n++){
		s += sn;
		sn = sn * x*x/((2*n-1)*2*n);
	}
	*m = n;
	return s;
}

//7. arctg sn: -x*x*(2*n-3)/(2*n-1)
double sum7(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 0, sn = x, n = 2; fabs(sn) > eps; n++){
		s += sn;
		sn = -sn * x*x*(2*n-3)/(2*n-1);
	}
	*m = n;
	return s;
}

//8. arctg sn: -(2*n-3)/(x*x*(2*n-1))
double sum8(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = M_PI_2, sn = -1/x, n = 2; fabs(sn) > eps; n++){
		s += sn;
		sn = -sn * (2*n-3)/(x*x*(2*n-1));
	}
	*m = n;
	return s;
}

//9. 1/(1+x)^2 sn: -x * (n+1) / n
double sum9(double x,double eps,int *m){
	double s,sn;
	int n; 
	for(s = 0, sn = 1, n = 1; fabs(sn) > eps; n++){
		s += sn;
		sn = -sn * x * (n+1) / n;
	}
	*m = n;
	return s;
}

int main(){ 
	int nn;
	double x;
	for (x=0; x <= 3; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t cos=%0.4lf\n", nn,x, sum1(x, 0.00001, &nn), cos(x));
	for (x=0.1; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t ln=%0.4lf\n", nn,x, sum2(x, 0.00001, &nn), log(x));
	for (x=0; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t x^3=%0.4lf\n", nn,x, sum3(x, 0.00001, &nn), pow(3,x));
	for (x=0.5; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t ln=%0.4lf\n", nn,x, sum4(x, 0.0001, &nn), log(x));
	for (x=0; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t sh=%0.4lf\n", nn,x, sum5(x, 0.0000001, &nn), sinh(x));
	for (x=0; x <= 10; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t ch=%0.4lf\n", nn,x, sum6(x, 0.0000001, &nn), cosh(x));
	for (x=0; x <= 1; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t atan=%0.4lf\n", nn,x, sum7(x, 0.0000001, &nn), atan(x));
	for (x=1; x <= 5; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t atan=%0.4lf\n", nn,x, sum8(x, 0.0000001, &nn), atan(x));
	for (x=-0.9; x <= 0.9; x += 0.1)
		printf("n=%d \t x=%0.1f \t sum=%0.4lf \t (x+1)^-2=%0.4lf\n", nn,x, sum9(x, 0.0000001, &nn), 1/((x+1)*(x+1)));
}
