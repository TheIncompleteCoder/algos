#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define max 3

void 
init(int a[][max],int value,int m)
{
int i,j;
for(i = 0; i< m;i++)
{
for(j = 0; j< m;j++)
{
a[i][j] = value;
}

}
}

void 
display(int a[][max],int row,int col)
{
int i,j;
for(i = 0; i< row;i++)
{
for(j = 0; j< col;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
}


int ui()
{
int i;
printf("1. input\n");
printf("2. change [row] [col] parameter\n");
printf("3. minor\n");
printf("4. transpose matrix\n");
printf("5. cofacor matrix\n");
printf("7. inverse\n");
printf("8. find determinant\n");
printf("9. exit\n");
scanf("%d",&i);
if(i >=1 && i<= 9)
{
return i;
}
else
ui();
}

int leave_row_col(int a[][max],int row,int col,int max_no)
{
int temp[max_no][max_no];
static int k,l;
int i,j,minor,flag = 0;
init(temp,-1,max_no);
for(i= 0 ;i<max_no -1 ;i++)
{
for(j= 0 ;j<max_no -1 ;j++)
{
if(i == row && j == col )
{
flag = 1;
continue;

}
else if(i == row+1 && j == col )
{
flag = 1;
continue;
}
else if(i == (row+2)%max_no && j == col )
{
flag = 1;
continue;
}
if(i == row && j == col+1 )
{
flag = 1;
continue;
}
else if(i == row && j == (col+2)%max_no )
{
flag = 1;
continue;
}
else 
{
for(k = 0;k<2;k++)
{
for(l= 0;l<2;l++)
{
if(flag == 1)
{
temp [k][l] = a[i][j];
flag = 0;
}
else
break;
//printf("value of temp is temp[%d][%d] = %d\n",k,l,temp[k][l]);
}
}
}
}
}
minor = (temp[0][0]*temp[1][1] - temp[0][1]*temp[1][0] );
//printf("minor of %d %d = %d\n",row,col,minor);
return minor;
}



void 
input(int a[][max],int row,int col)
{
int i,j,temp;
for(i = 0; i< row;i++)
{
for(j = 0; j< col;j++)
{
printf("enter a no. ");
scanf("%d",&temp);
a[i][j] = temp;
}
printf("\n");
}
}


void 
transpose(int a[][max],int b[][max],int row,int col)
{
int i,j;
for(i = 0; i< row;i++)
{
for(j = 0; j< col;j++)
{
b[i][j] = a[j][i];
}
printf("\n");
}
}


int 
finding_minor(int a[][max],int row,int col,int max_number)
{
if(max_number == 1)
{
// 1*1 logic
return a[0][0];
}
else if(max_number == 2)
{
// 2*2 logic
if(row==0 && col ==0)
{
return a[1][1];
}
if(row== 0  && col ==1)
{
return a[1][0];
}
if(row== 1  && col ==0)
{
return a[0][1];
}
if(row== 1  && col ==1)
{
return a[0][0];
}
}
else if(max_number == 3)
{
// 3*3 logic
return leave_row_col(a,row,col,max_number);
}
else 
{
printf("invalid row col number ..\n");
return ;
}
}

void 
finding_cofactor(int a[max][max],int b[max][max],int row,int col)
{
int i,j;
for(i = 0; i<row;i++)
{
for(i = 0; i<row;i++)
{
//b[i][j] = pow(-1,(i+j))* a[i][j];
}
}
}

int 
main(int argc,char **argv)
{
int a,b,temp;
int array[max][max];
int array_transpose[max][max];
int array_minor[max][max];
int array_cofactor[max][max];
int i,j;
if(argc!=3)
{printf("usage:mat row col\n"); return;}

a = atoi(argv[1]);
b = atoi(argv[2]);
if(a < 1 && b <1 )
return;
printf("%d  %d\n",a,b);

//temp = ui();

input(array,a,b);
printf("before trasnpose\n");
display(array,a,b);

transpose(array,array_transpose,a,b);
printf("after trasnpose\n");
display(array_transpose,a,b);

//finding_minor(array,array_minor,a,b);
printf("minor's matrix is:\n");
for (i=0;i<a;i++)
{
for (j=0;j<a;j++)
{
array_minor[i][j] = finding_minor(array,i,j,a);
}
}

display(array_minor,a,b);

/*finding_cofactor(array_minor,array_cofactor,a,b);
printf("cofactor's matrix is:\n");
display(array_cofactor,a,b);
*/

return 0;
}







