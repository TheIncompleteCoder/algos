/*
author : Akash Nagwanshi
language : c
date : 11-aug-2016
program : Inverse of an matrix.
*/


#include <stdio.h>

int row,col;
int matrix[][col];
int temp_minor_matrix[][col];
int temp_cofactor_matrix[][col];

void
init_matrix(int [][col],int);

int 
finding_Minor();

void
finding_cofactor();

int 
finding_adjoint();

int 
finding_determinant();

int 
finding_inverse();

void 
init_matrix(int [][],int);

void 
input_for_array2d(int array2d[][col]);

//driver-program
int 
main(int argc,char **argv)
{
if(argc!=3)
{
printf("usage:mat_inv row_no col_no\n");
return;
}
if(argv[1] < 1 && argv[2] < 1)
{
printf("invalid row_number and col_number\n");
return;
}


//requester for minor...
for(int row_index = 1;row_index <=row ; row_index++)
{
for(int col_index = 1;col_index <=row ; col_index++)
{
temp_minor_matrix[row_index][col_index] = finding_Minor(array_2d[][col],row_index,col_index); 
}
}

}

void
init_matrix(int array2d[][col],int init_value)
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
input_for_array2d(int array2d[][col])
{
int row_index,col_index;;
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
finding_Minor(int array_2d[][col],int row_index,int col_index)
{
int array_2d_minor_rowIndex_colIndex;
array_2d_minor_rowIndex_colIndex = array_2d[row_index+1][col_index+1]*array_2d[row_index+2][col_index+2] - array_2d[row_index+1][col_index+2]*array_2d[row_index+2][col_index+1] ;
return array_2d_minor_rowIndex_colIndex;
}

void
finding_cofactor(int array_2d[][col])
{
int row_index,int col_index;
for (row_index = 1; row_index <= row ; row_index)
{
for(col_index = 1; col_index <= col; col_index++)
{
temp_cofactor_matrix[row_index][col_index] = (-1)^(row_index + col_index)*temp_minor_matrix[row_index][col_index]; 
}
}
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
