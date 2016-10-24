#include <stdio.h>
int array[5];
int arrayIndex = 0;
void push(int [],int);
int pop();

int main()
{
char ch; 
int num;
int i;
for ( i=0;i<5;i++)
{
printf("enter a no.\n");
scanf("%d",&num);
push(array,num);
}
//printing
printf("\n\nand the no. are.........\n\n");
for(i=0 ;i<5;i++)
 printf("%d\n",pop());
return 0;
}

void push(int array[],int num)
{
array[arrayIndex++] = num;
}

int pop()
{
return array[--arrayIndex];
}
