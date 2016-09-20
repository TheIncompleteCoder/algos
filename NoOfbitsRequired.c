/*
author : akash nagwanshi
code : to find number of bits required,for storing a number in memory.
*/

#include <stdio.h>
#include <stdlib.h>
#define max 16 // {16/32/64}

int find_bits(int);
int 
main(int argc,char *argv[]){
int number,bits;
if(argc!=2 && argc>2){
printf("usage : ./bits input_number\n");
exit(1);
}
number  = atoi(argv[1]);
if(number == 0)
printf("no of bits required = all zero's\n");
else{
bits = find_bits(number);
printf("no of bits required = %d\n",bits);
}
return 0;
}

int 
find_bits(int number){
int array[max],i,j,count = 0;
int remainder;
// init
for(i=0;i<max;i++)
array[i] = 0;
j = max -1;
while(number >= 1){
remainder = number%2; // for remainder (0/1)
number = number/2; // gets next number
array[j] = remainder;// store that remainder in to the array from the end.
j--;
}

// for debugging...
//for(i=max;i>0;i--)
//printf("%d\n",array[i]);

// count bits
j=0;
while(array[j]!=1)
{
count++;
j++;
}
count = max - count;
return count;
}
