#include <stdio.h>
#define max 6
void BubbleSort();
void insert();
void large(int);
void small(int);
int array[max];
int *f,*r;
int main(){
int fr,rr,i;
insert();
BubbleSort();
f = &array[0];
r = &array[max-1];
if(max%2==0){
fr = max/2;
rr = max/2;
}
else{
fr = max/2;
rr = max/2 +1;
}
for(i=0;i<rr;i++){
large(i);
small(i);
}
if(!max%2==0)
small(i);
return ;
}
void large(int i){
printf("%d largest = %d\n",i+1,*(r));
r--;
}

void small(int i){
printf("%d smallest = %d\n",i+1,*(f));
f++;
}
void insert()
{
int j;
for(j=0;j<max;j++)
{
printf("enter an number\n");
scanf("%d",&array[j]);
}
}

void BubbleSort(){
int i,j,temp;
for(i = 0;i<max-1;i++){
for(j=0;j<max-1-i;j++)
{
if(array[j] > array[j+1]){
temp = array[j];
array[j]= array[j+1];
array[j+1]  =temp;
}
}
}
}
