#include <stdio.h>
#include <math.h>
int main()
{
    int min;
    int s1 = 480608,
        s2 = 508811,
        s3 = 723217;

    for (int i = 2; i < s1; i++) {
        if (s1 % i == s2 % i && s2 % i == s3 % i) {
            printf("divider = %d\n", i);
        }
    }
} 
