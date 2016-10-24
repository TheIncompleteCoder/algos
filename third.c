#include <stdio.h>
#define n 5 
int third(int *,int);
int main()
{
int array[n] = { 3,8,9,-4,10};
printf("third highest in the list is %d\n",third(array,n));
return 0;
}

int third(int *arr,int num){
int i,f,s,t;
for(i=0;i<n;i++){
if(f<*(arr+i)){
//t = s;
s = f;
f = *(arr+i);
}
}
return s;
return t; // for third highest...
}
