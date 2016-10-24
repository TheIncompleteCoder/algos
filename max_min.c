







































#include <stdio.h>

int main(int argc,char **argv)
{
int max,min,smax,smin,i;
int array[] = {10,4,40,85,95,54,23,2};
max = array[0];
min = array[0];
for(i=0; i<8; i++)
{
if(array[i] > max)
max = array[i];
if(array[i] < min)
min = array[i];
}

for(i=0; i<8; i++)
{
if(array[i] <= max)  
smax = array[i];
if(array[i] > min)
smin = array[i];
}

printf("max = %d\n",max);
printf("min = %d\n",min);
printf("second max = %d\n",max);
printf("second min = %d\n",min);

return 0;
}
