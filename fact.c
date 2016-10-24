#include <stdio.h>
int fact(int);
int main(int argc,char *argv[]){
if(argc!=2 ){
printf("usage : factorial number\n");
}
if(argc==2)
printf("factorial of %d = %d\n",atoi(argv[1]),fact(atoi(argv[1])));
}

int fact(int num){
if(num == 1){
return 1;
}
return num*fact(num-1);
}
