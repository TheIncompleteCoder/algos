#include <stdio.h>
void rev(char *);
int main(int argc,char *argv[]){
if(argc!=2 ){
printf("usage : strrev string_to_reverse\n");
}
if(argc==2)
rev(argv[1]);
printf("\n");
}

void rev(char *str){
if(*str=='\0'){
return;
}
rev(str+1);
printf("%c",*str);
}
