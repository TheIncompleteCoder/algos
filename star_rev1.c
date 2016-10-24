#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
int row,col,space;
int num;
if(argc!=2){
printf("usage : star number\n");
exit(0);
}
num = atoi(argv[1]);
for(x=1;x<num;x++)
{
for(n=k+x;n>=x;n--){
printf(" ");
}
for(y=1;y<=x;y++){
printf("%d",y);
}
printf("\n");
k--;
}
return 0;
}

/*ip: star 4
op:
1
12
123
1234
*/
