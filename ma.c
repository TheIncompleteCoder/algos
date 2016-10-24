#include <stdlib.h>
#include <stdio.h>
#define max 3

void 
display(int a[max][max],int row,int col)
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


int 
finding_minor(int a[max][max],int b[max][max],int row,int col)
{
int i,j;

for (i = 0;i<row;i++)
{
for (j = 0;j<col;j++)
{
if(row = col = 1)
{
b[0][0] = a[0][0];
return;
}

if(i==0 && j ==0)
{
b[i][j] = a[1][1];
}
if(i== 0  && j ==1)
{
b[i][j] = a[1][0];
}
if(i== 1  && j ==0)
{
b[i][j] = a[0][1];
}
if(i== 1  && j ==1)
{
b[i][j] = a[0][0];
}

}
}
return 0;
}



int 
main(int argc,char **argv)
{
int a = 3,b = 3;
int array[max][max] = {{1,2,3},{4,5,6},{7,8,9}};
int array_minor[max][max];

//input(array,a,b);
printf("before trasnpose\n");
display(array,a,b);

finding_minor(array,array_minor,a,b);
printf("minor's matrix is:\n");
display(array_minor,a,b);

return 0;
}
