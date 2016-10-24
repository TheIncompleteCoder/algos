#include <stdio.h>

//recursive
// time complexity  = O(lgn)
int binary_search(int a[],int low,int high,int mid,int x)
{
if(a[mid == x])
return 0;
if(a[mid] > x)
binary_search(a,low,mid-1,(low+high)/2,x);
if(a[mid] < x)
binary_search(a,mid+1,high,(low+high)/2,x);
return -1;
}

// non-recursive prodedure 
// time complexity  = O(n)

/*(int binary_search(int a[],int low,int high,int mid,int x)
{
while(low <= high)
{
if(a[mid] == x)
return mid;

if(a[mid] <= x)
low = mid+1;

if(a[mid] >= x)
high = mid-1;

mid = (low+high)/2;
}
return -1;
}
*/
int main()
{
int a[] = {1,2,5,6,9,89,90,201};
int low = 0;
int high = 7;
int mid = (low+high)/2;
int temp = binary_search(a,low,high,mid,1);
if(temp == 0 )
printf("found at \n");
else 
printf(" not found \n");
}
