#include <stdio.h>
#define max 10
int main(){
int array[max] = {2,5,6,7,9,69,56,61,20,1};
int i;
int large,small,s_large,s_small,t_large;
printf("Array elements are...\n");
for(i = 0;i<max;i++)
printf("%d\n",array[i]);
large = array[0];
s_large = large;
t_large = s_large;
i=0;
while(i < max){
if(array[i] > large)
large  = array[i];
if(array[i]>s_large && array[i] <large)
s_large = array[i];
if(array[i] > t_large && array[i] < large && array[i] < s_large )
t_large = array[i];
i++;
}
printf("3rd largest element is =%d\n",t_large);
return 0;
}
