/*
author : Akash Nagwanshi
language : c
date : 11-aug-2016
program : Inverse of an matrix.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 4

int row = max;
int col = max;
int matrix[max][max];
int temp_minor_matrix[max][max];
int temp_cofactor_matrix[max][max];

void
init_matrix(int array2d[row][col],int init_value)
{
int row_index,col_index;
for(row_index = 1;row_index <= row; row_index++)
{
for(col_index = 1;col_index <= col; col_index++)
{
array2d[row_index][col_index] = init_value;
}
}
}


void 
input_for_array2d(int array2d[row][col])
{
int row_index,col_index;
int temp;
for(row_index = 1;row_index <= row; row_index++)
{
for(col_index = 1;col_index <= col; col_index++)
{
printf("enter value for 2d_array[%d][%d] ",row_index,col_index);
scanf("%d",&temp);
array2d[row_index][col_index] = temp;
}
}
}

int 
finding_Minor(int array_2d[row][col],int row_index,int col_index)
{
int array_2d_minor_rowIndex_colIndex;
array_2d_minor_rowIndex_colIndex = array_2d[row_index+1][col_index+1]*array_2d[row_index+2][col_index+2] - array_2d[row_index+1][col_index+2]*array_2d[row_index+2][col_index+1] ;
return array_2d_minor_rowIndex_colIndex;
}

void
finding_cofactor(int array_2d[row][col])
{
int row_index,col_index;
for (row_index = 1; row_index <= row ; row_index)
{
for(col_index = 1; col_index <= col; col_index++)
{
temp_cofactor_matrix[row_index][col_index] = (-1)^(row_index + col_index)*temp_minor_matrix[row_index][col_index]; 
}
}
}


int 
finding_determinant(int array_2d[row][col],int row_index,int col_index)
{
int detreminant_sum,temp;
for (row_index = 0; row_index < row ;row_index ++)
{
for (col_index = 0; col_index < col ;col_index ++)
{
temp = array_2d[row_index][col_index]*array_2d[row_index + 1][col_index +1] - array_2d[row_index][col_index + 1]*array_2d[row_index+1][col_index];
detreminant_sum = detreminant_sum + temp;
}
}
return detreminant_sum;
}


void display(int a[][max])
{
int i,j;
for(i= 0; i<row;i++)
{
for(j= 0; j<col;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
}


int 
main(int argc,char **argv)
{
int row_index,col_index;
int array_2d[max][max];

if(argc!=3)
{
printf("usage:mat_inv row_no col_no\n");
return;
}

row = (int)argv[1];
col = (int)argv[2];

input_for_array2d(array_2d[row][col]);
display(array_2d);
return 0;
}


/*
@@@@@@@ second function...

int 
finding_determinant(int array_2d[][col],int row_index,int col_index)
{
int i,j,k;
double sum,p;
sum = 0.0;
j = 1;
k = row_index - 1;
if(row_index == col_index)
{
for( i = 0;i < row_index ; i++)
{
p = pow(-1.0,i);
if(i == row_index - 1)
k = 1;
sum = sum + (array_2d[0][i]*([1][j] * array_2d[2][k] - array_2d[2][j] * array_2d[1][k])) * p;
j = 0;
}
}
return sum;
}
*/
