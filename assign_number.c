#include <stdio.h>
#define max 10

int 
main(int argc,char **argv){
int array[max] = {2,5,6,7,9,69,56,61,20,1};
int find_min,find_max;
int lower_bound,upper_bound;
//int temp[max];
int i,j,temp;
/*if(argc!=2){
printf("usage : ./assign_number min max");
return;
}
if(argc!= 3 && argc == 2)
{
find_min = argv[1];
find_max = argc[1];
}
if(argc == 3){
find_min = argv[1];
find_max = argc[2];
}
*/

lower_bound = 0;
upper_bound = 9;

for(i = 0;i<max-1;i++){
 for(j = 0;j<max-i;j++){
 if(array[j] > array[j+1] ){
 temp = array[j];
 array[j] = array[j+1];
 array[j+1] = temp;
 }
}
}
   avg = lower_bound + upper_bound;

  for(i=0;i<upper_bound;i++){
    if(avg%2==0){
    
    }else
    {
    
    }
    
  }
for(i = 0;i<max;i++){
printf("%d \n",array[i]);
 }
return 0;
}


