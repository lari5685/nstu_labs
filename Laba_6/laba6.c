#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
	char str[20];
	char out[50];

	printf("input :: \n"); 
	strcpy(str, "abc13,4defg2ho");
	//scanf("%30s",str);

	int l, k ,a = 0, b = 0, n = strlen(str);

	for(int i = 0; i<n; i++){
		if (fabs(str[i] - 53) <= 4){
			l = i;
			a = str[i] - 48;
			i++;
			while(str[i]>= 48 && str[i] <= 57){
				a = a*10+(str[i]-48);
				i++;
			}

			//have ','
			if (str[i] == ',' && fabs(str[i+1] - 53) <= 4){
				b = str[i+1] - 48;
				i+=2;
				while(str[i]>= 48 && str[i] <= 57){
					b = b*10+(str[i]-48);
					i++;
				}
			
				// we have n1(a) and n2(b)
				printf("%d %d\n", a,b);
				k = i;
				
				for(int j = 0; j<i; j++){
					out[j] = str[j];
				}





				puts(s);
			
			}
			// haven`t ',' // we have n1

		}
	}

	//scanf("%30s",str);
}


