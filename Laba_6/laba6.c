#include <stdio.h>
#include <string.h>
#include <math.h>


int main() {
	char str[]= "abc2,3defg2ho";
	char out[100];
	gets(str);
	int p=0, a = 0, b = 0; 
	puts(str);
	for (int i = 0; str[i] != '\0'; i++, p++) {
		if (fabs(str[i] - 53) <= 4) {
			a = str[i] - 48; b = 1;
			i++;
			while (str[i] > 47 && str[i] < 58) {
				a = a * 10 + str[i] - 48;
				i++;
			}
			if (str[i] == ',' && fabs(str[i + 1] - 53) <= 4) {
				b = str[++i] - 48;
				i++;
				while (str[i] > 47 && str[i] < 58) {
					b = b * 10 + str[i] - 48;
					i++;
				}
			}
			for (int j = 0; j < a; j++) 
				for (int m = 0; m < b; m++) {
					out[p] = str[i+m];
					p++;
				}
			i += b;
		}
		out[p] = str[i];
	}
	for (int i = 0; i<p; i++)
		putchar(out[i]);
gets(str);
}