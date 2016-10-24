#include <stdio.h>
#define size 5

int initialize(int array[size][size],int initValue)
{
int row,col;
for(row = 0;row< size;row++)
{
for(col = 0;col< size;col++)
{
array[row][col] = initValue;
}
}
return 0;
}

void display(int array[size][size])
{
int row,col;
for(row = 0;row< size;row++)
{
printf(" |");
for(col = 0;col< size;col++)
{
printf(" %d |",array[row][col]);
}
printf("\n");
}
}

void transpose(int array[size][size],int array2[size][size])
{
int row,col;
int temp;
for(row=0;row< size;row++)
{
for(col=0;col< size;col++)
{
array2[row][col] = array[col][row];
}
}
}

int main()
{
int array[size][size] = { 
			{1,26,963,454,215},
		     {23,3,4,5,1},
			{30,4,54,1,2},
			{44,5,1,36,3},
			{54,100,2,3,4}
			};
int array2[size][size];
//initialize(array,2);

printf("before transpose\n");
display(array);
printf("\n after transpose\n");
transpose(array,array2);
display(array2);
printf("\n \n");
}


