#include <stdio.h>
#include <stdlib.h>
#define num 5
int main(int argc,char *argv[]){
int row,col,space,i;
int array[num];

for(i=1;i<=num;i++){
printf("enter a number\n");
scanf("%d",&array[i]);
}
for(row=1;row <= num;row++){
for(space = num;space >row;space--){
printf(" ");
}
for(col=1;col<= row;col++){
printf("%d ",array[col]);
}
printf("\n");
}
for(row=1;row <num;row++){
for(space = 1;space<=row;space++){
printf(" ");
}
for(col=1;col<=num-row;col++){
printf("%d ",array[col]);
}printf("\n");
}
return 0;
}
