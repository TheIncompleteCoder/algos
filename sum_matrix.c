#include <stdio.h>
#define max 3

int main(int argc,char *argv[]){
int array2d_1[max][max];
int array2d_2[max][max];
int row,col,temp;
  printf("enter element for first array(3x3)...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
  printf("enter element for array_1[%d][%d]\n",row,col);
  scanf("%d",&array2d_1[row][col]);  
}
}
  printf("enter element for second array(3x3)...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
  printf("enter element for array_2[%d][%d]\n",row,col);
  scanf("%d",&array2d_2[row][col]);  
}
}
  printf("thier sum...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
   array2d_1[row][col] = array2d_1[row][col]+array2d_2[row][col];
}
}
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
   printf("%d ",array2d_1[row][col]);
}printf("\n");
}
return 0;
}
