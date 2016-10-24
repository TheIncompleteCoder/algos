#include <stdio.h>
#define max 5
int main(){
int array[max];// = {2,5,6,7,9,69,56,61,20,1};
int i;
int large,small,s_large,s_small;

for(i = 0;i<max;i++)
scanf("%d",&array[i]);
printf("Array elements are...\n");
for(i = 0;i<max;i++)
printf("%d\n",array[i]);
large = array[0];
small = array[0];
s_large = large;
s_small = small;
i=0;
while(i < max){
if(array[i] > large)
large  = array[i];
if(array[i] < small)
small  = array[i];
if(array[i]>s_large && array[i] <large)
s_large = array[i];
if(array[i]<s_small && array[i] >small)
s_small = array[i];
i++;
}


printf("largest element is =%d\n",large);
printf("smallest element is =%d\n",small);
printf("second largest element is =%d\n",s_large);
printf("second smallest element is =%d\n",s_small);
return 0;
}
