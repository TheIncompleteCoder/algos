#include <stdio.h>
#include <stdlib.h>
#define size 10
#define max 100

int array[size];
void printFibonacci(int);
int main(int argc,char *argv[]){
int num1=0,num2=1,num3,temp,i=0;
if(argc!=2){
printf("usage: ./fibo limit_value(integer)\n");
exit(0);
}
num3 = atoi(argv[1]);
array[0]= 0;
array[1]= 1;
i=2;
if(num3 == 1)
printf("%d\n",num1);
do{
temp = num1+num2;
num1 = num2;
num2 = temp;
if(num2 <= max)
array[i] = temp;
i++;
}while(num2 < max);
printFibonacci(num3);
return 0;
}


void printFibonacci(int index)
{
int i;
for(i=index;i<size;i++){
printf("%d\n",array[i]);
}
}
