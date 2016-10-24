#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define max 3

struct array_node{
int a;
int flag;
};

/*
1| 2| 3 
4| 5| 6
7| 8| 9

00->
x|x|x       x-->flag = 0
x|.|.        else flag = 1
x|.|.            if (flag) show_it_in_result_set  solution.... 
			  else not contain in result set  solution...


*/

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
printf(" %d|",a[i][j]);
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

// function for skipping the row and col index.
int leave_row_col(int a[][max],int row,int col,int max_no)
{
int temp[2][2];
int i,j,minor;
static int k,l;
for(i= 0 ;i<2 ;i++)
{
for(j= 0 ;j<2 ;j++)
{
 for(k=0;k<max_no;k++)
 {
 for(l=0;l<max_no;l++)
 { 
  printf(" %d %d \n",k,l);
	if( (k == row && l == col ) || (k == row+1 && l == col ) || (k == (row+2)%max_no && l == col ) || (k == row && l == col+1 ) || (k == 		row && l == (col+2)%max_no ) )
	{
        continue;
	}
   else
   {

	temp [i][j] = a[k][l];
	    printf("temp value of at %d %d = %d",i,j,temp[i][j]);
    break;
   }
 }
 printf("\n");
 }
}
//printf("\nloon ends\n"); ** for analysing
}
minor = (temp[0][0]*temp[1][1] - temp[0][1]*temp[1][0] );
printf("minor of %d %d = %d\n",row,col,minor); //** for analysing
return minor;
}

/* function for skipping the row and col index.
int leave_row_col(int a[][max],int row,int col,int max_no)
{
int temp[2][2];
int i,j,minor;
static int k,l;;
for(i= 0 ;i<max_no  ;i++)
{
for(j= 0 ;j<max_no  ;j++)
{
if( (i == row && j == col ) || (i == row+1 && j == col ) || (i == (row+2)%max_no && j == col ) || (i == row && j == col+1 ) || (i == row && j == (col+2)%max_no ) )
{
//printf("skip %d %d\n",i,j);  // for analysing
continue;
}
else 
{

}
}
//printf("\nloon ends\n"); // for analysing
}
minor = (temp[0][0]*temp[1][1] - temp[0][1]*temp[1][0] );
//printf("minor of %d %d = %d\n",row,col,minor); // for analysing
return minor;
}
*/

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
static int a,b;
int temp;
int array[max][max];
int array_transpose[max][max];
int array_minor[max][max];
int array_cofactor[max][max];
int i,j;
if(argc!=3)
{printf("usage:mat row col\n"); return;}

a = atoi(argv[1]);
b = atoi(argv[2]);
if((a < 1 && a >4 )|| (b <1 && b > 4))
{
printf("oops! invalid setting....\n");
exit(1);
}

printf("row = %d  col = %d\n",a,b);

temp = ui();
while(1)
{
if(temp == 1)
{
input(array,a,b);
//printf("before trasnpose\n");
display(array,a,b);
}


if(temp == 2){
printf("enter a no [1-3] for row\n");
scanf("%d",&a);
printf("enter a no [1-3] for col\n");
scanf("%d",&b);
temp = ui();
}


if(temp == 3)
{
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
break;
}

if(temp == 4)
{
transpose(array,array_transpose,a,b);
printf("after trasnpose\n");
display(array_transpose,a,b);
break;
}

if(temp == 5){
finding_cofactor(array_minor,array_cofactor,a,b);
printf("cofactor's matrix is:\n");
display(array_cofactor,a,b);
break;
}


if(temp == 7){
//inverse();
break;
}

if(temp == 8){
//determinant
break;
}

if(temp == 9){
exit(0);
}
}
return 0;
}
