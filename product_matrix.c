#include <stdio.h>
#define max 3

int main(int argc,char *argv[]){
int array2d_1[max][max];
int array2d_2[max][max];
int result_2d_array[max][max];
int row,col,temp,product;

//1st array insertion
  printf("enter element for first array...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
  printf("enter element for array_1[%d][%d]\n",row,col);
  scanf("%d",&array2d_1[row][col]);  
}
}

//2nd array insertion
  printf("enter element for second array...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
  printf("enter element for array_2[%d][%d]\n",row,col);
  scanf("%d",&array2d_2[row][col]);  
}
}

//their multiplication
  printf("thier product...\n");
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){product  = 0;
   for(temp = 0;temp <max;temp++){
      product = product + array2d_1[row][temp] * array2d_2[temp][col];
   }result_2d_array[row][col] = product;
 }
}


//for displaying results.
for(row = 0;row <max ;row++){
 for(col = 0;col <max ;col++){
   printf("%d ",result_2d_array[row][col]);
}printf("\n");
}
return 0;
}
