
#include <stdio.h>
//13 поиск суммы цифр в числе
int F13(int a) {
    int n, s, k;
    for (n=a, s=0; n!=0; n=n/10)
    { k=n%10; s=s+k;}
    return s;
}

//16 Программа записывает каждую цифру числа а под отдельным индексом в массиве А.
char F16 (int a){
    int n,i, j, len;
    char A[100]={0};
    for (i=0, n=a; n!=0; i++, n=n/10);
    len=i;
    for (A[i--]=-1, n=a; n!=0; i--, n=n/10)
        A[i]=n % 10;
    for (int j = 0; j < len; j++) printf("%d ", A[j]); printf("\n");
    
}

//26 программа удаляетт из массива простые числа
void F26(int *A,int *count){
    int j, i, s,m, n=*count;
   
    for (j=0,i=0; i<n ; i++){
        for (s=0,m=2; m<A[i]; m++)
        if (A[i]%m==0) { s=1; break; }
        if (s==0) {
            for (j=i; j<n-1;j++) A[j]=A[j+1];
            n--;
            i--;
        }}
    *count= n;}
//29 поиск НОД
int F29(int A[], int *count){
    int i, v=A[0], n=*count;
    for (i=0; i<n; i++)
           if (A[i]%v!=0) { v--; i=-1; }
    printf("%i", v);
}

//32 поиск элемента, встречающегося в массиве наибольшее количество раз
void F32(int *c,int *count){
    int s,i,n=*count, j, b,k;
    for (s=0,i=0; i<n; i++){
           for (k=0,j=0; j<n; j++)
               if (c[i]==c[j]) k++;
           if (k>s) s=k,b=i;
       }
      
       *count=b;
}

//35 реверс массива
int F35(int c[],int *count){
    int j, i, n=*count, k;
    for (i=0,j=n-1; i < j; i++,j--)
   { k = c[i]; c[i] = c[j]; c[j] = k; }
    *count=n;   
}

//41 поиск суммы чисел массива до первого отрицательного числа включительно
int F41(int A[],int *count){
    int s,k,i, n=*count;
    for (k=0,s=0,i=0; i<n && k==0; i++){
   if (A[i]<0) k=1;
   s=s+A[i];
   }
    printf("%i", s);
}

//47 программа записывает в массив числа из заданного промежутка, которые кратны своим цифрам
int F47(int v){
    int A[100]={0};
    int j,n,s,k,a, count=0;
    for (j=0,a=10; a<v; a++){
    for (s=0,n=a, s=0; n!=0; n=n/10){
    k=n%10;
    if (k!=0 && a%k!=0) { s=1; break; }
    }
    if (s==0) { A[j++]=a; count++;}
    }
    for (int j = 0; j < count; j++) printf("%d ", A[j]); printf("\n");
}

//49 программа находит индекс минимального элемента из неотрицательных чисел
int F49(int A[],int *count) {
    int k,i, n=*count;
    for (i=0,k=-1; i<n; i++){
    if (A[i]<0) continue;
    if (k==-1) k=i;
    else
    if (A[i]<A[k]) k=i;
    }
    printf("%i",k);
}

//55 Программа ищет количество положительных чисел массива
int F55(int A[],int *count){
    int i,s=0, n=*count;
    for (i=0,s=0; i<n; i++)
   if (A[i]>0) s++;
    printf("%i", s);
}

int main(){
    //13
    int F13_1, F13_2,F13_3;
    F13_1 = F13(12345);
    F13_2= F13(1010101);
    F13_3= F13(999999);
    printf("F13_1: %d\n", F13_1);
    printf("F13_2: %d\n", F13_2);
    printf("F13_2: %d\n\n", F13_3);

    //16
    printf("F16_1: ");
    F16(1234567);
    printf("F16_2: ");
    F16(1111111);
    printf("F16_3: ");
    F16(1010101);

    //26
    int n = 10;
    int F26_1[]={17,2,3,4,5,6,7,8,9,11};
    F26(F26_1, &n);
    printf("\nF26_1: ");
    for (int il = 0; il < n; il++) printf("%d ", F26_1[il]); 
    
    n = 10;
    int F26_2[]={1,3,5,7,11,2,9,16,10,13};
    F26(F26_2, &n);
    printf("\nF26_2: ");
    for (int il = 0; il < n; il++) printf("%d ", F26_2[il]); 
    
    n = 10;
    int F26_3[]={17,2,3,4,5,10,18,4,8,2};
    F26(F26_3, &n);
    printf("\nF26_3: ");
    for (int il = 0; il < n; il++) printf("%d ", F26_3[il]);
    
    //29
    n=5;
    int f29_1[5]={10,18,4,8,2};
    printf("\n\nF29_1: ");
    F29(f29_1, &n);
    n=5;
    int f29_2[5]={35,40,80,5,90};
    printf("\nF29_2: ");
    F29(f29_2,&n);
    n=5;
    int f29_3[5]={3,9,27,30,108};
    printf("\nF29_3: ");
    F29(f29_3,&n);
    
    //32
    n=10;
    int f32_1[10]={1,2,2,4,5,6,7,2,9,0};
    printf("\n\nF32_1: ");
    F32(f32_1, &n);
    printf("%i", f32_1[n]);
    n=10;
    int f32_2[10]={1,2,3,4,4,5,4,6,7,2};
    printf("\nF32_2: ");
    F32(f32_2, &n);
    printf("%i", f32_2[n]);
    n=10;
    int f32_3[10]={1,1,1,1,1,1,1,1,1,1};
    printf("\nF32_3: ");
    F32(f32_3, &n);
    printf("%i", f32_3[n]);
    
    //35
    n=10;
    int f35_1[10]={1,2,3,4,5,6,7,8,9,0};
    printf("\n\nF35_1: ");
    F35(f35_1, &n);
    for (int j = 0; j < n; j++) printf("%d ", f35_1[j]); printf("\n");
    n=10;
    int f35_2[10]={1,0,1,0,1,0,1,0,1,0};
    printf("F35_2: ");
    F35(f35_2, &n);
    for (int j = 0; j < n; j++) printf("%d ", f35_2[j]); printf("\n");
    n=10;
    int f35_3[10]={1,1,1,1,0,1,1,1,1,1};
    printf("F35_3: ");
    F35(f35_3, &n);
    for (int j = 0; j < n; j++) printf("%d ", f35_3[j]); printf("\n");
    
    //41
    n=10;
    int f41_1[10]={1,2,3,4,5,6,-7,-8,9,0};
    printf("\n\nF41_1: ");
    F41(f41_1, &n);
    n=10;
    int f41_2[10]={1,0,1,0,1,0,-1,0,1,0};
    printf("\nF41_2: ");
    F41(f41_2, &n);
    n=10;
    int f41_3[10]={1,1,1,1,-1,1,1,1,1,1};
    printf("\nF41_3: ");
    F41(f41_3, &n);
    
    //47
    printf("\n\nF47_1: ");
    F47(14);
    printf("F47_2: ");
    F47(19);
    printf("F47_3: ");
    F47(29);
    
    //49
    n=10;
    int f49_1[10]={1,2,3,4,5,6,-7,-8,9,0};
    printf("\nF49_1: ");
    F49(f49_1, &n);
    n=10;
    int f49_2[10]={1,0,1,0,1,0,-1,0,1,0};
    printf("\nF49_2: ");
    F49(f49_2, &n);
    n=10;
    int f49_3[10]={-1,3,1,3,5,-8,5,1,-2,12};
    printf("\nF49_3: ");
    F49(f49_3, &n);
    
    //55
    n=10;
    int f55_1[10]={1,2,3,4,5,6,-7,-8,9,0};
    printf("\n\nF55_1: ");
    F55(f55_1, &n);
    n=10;
    int f55_2[10]={1,0,1,0,1,0,-1,0,1,0};
    printf("\nF55_2: ");
    F55(f55_2, &n);
    n=10;
    int f55_3[10]={-1,3,1,3,5,-8,5,1,-2,12};
    printf("\nF55_3: ");
    F55(f55_3, &n);
    
    return 0;
}

