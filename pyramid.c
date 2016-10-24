#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
int row,col,space;
int num;
if(argc!=2){
printf("usage : program number\n");
exit(0);
}
num = atoi(argv[1]);
for(row=1;row <= num;row++){
for(space = num;space >row;space--){
printf(" ");
}
for(col=1;col<= row;col++){
printf("%d ",col);
}printf("\n");
}
return 0;
}
