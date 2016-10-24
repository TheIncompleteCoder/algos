#include <stdio.h>
#include <stdlib.h>
void make_seriesFibonacci(int num1,int num2,int final){
int temp;
if(num2 < final){
//call
temp = num1+num2;
if(temp <= final)
printf("%d\n",temp);
make_seriesFibonacci(num2,temp,final);
}
else
return;
}

int main(int argc,char *argv[]){
int num1=0,num2=1,num3;
if(argc!=2){
printf("usage: ./fibo_rec limit_value(integer)\n");
exit(0);
}
num3 = atoi(argv[1]);
printf("%d\n%d\n",num1,num2);
make_seriesFibonacci(num1,num2,num3);
return 0;
}
