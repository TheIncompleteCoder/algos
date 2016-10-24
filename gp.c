#include <stdio.h>
#include <stdlib.h>
unsigned int getUnsign(size_t bytes)
{
int bits = 8*bytes;
unsigned int to = ((1 << (bits-1))-1)+(1 << (bits-1));
return to;
}

int main(int argc,char *argv[]){
unsigned int range;
int first_term,ratio,terms,value,sum = 0,i;
range = getUnsign(sizeof(int));
first_term = atoi(argv[1]);
ratio = atoi(argv[2]);
value = first_term;
printf("gp series....\n");
for(i=0;i<range - 1;i++){
if(value < 0)
exit(0);
else
printf("%d\n",value);
sum = sum +value;
value = value *ratio;
}
return 0;
}
