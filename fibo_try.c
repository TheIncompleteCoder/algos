#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
int num1=0,num2=1,num3,temp,i,limit = 555;
if(argc!=2){
printf("usage: ./fibo start_index_value(integer)\n");
exit(0);
}
num3 = atoi(argv[1]);
if(num3 == 0) return;
if(num3  == 1)
printf("%d\n%d\n",num1,num2);
else if(num3==2)
printf("%d\n",num2);
else if(num3==3)
printf("%d\n",num2);
i=1;
while(num2<limit){
temp = num1+num2;
num1 = num2;
num2 = temp;

while(i<=num3)
{
temp = num1+num2;
num1 = num2;
num2 = temp;
i++;
continue;
}
//if(i<=num3)
//continue;
//if(temp <=limit)
if(i>num3 && temp < limit)
printf("%d\n",temp);
}
return 0;
}
