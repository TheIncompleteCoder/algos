#include <stdio.h>
#define max_vehicle 3
int full_list_of_vehicle[max_vehicle];
int all_finished;
void push(int,int);
int pop(int);
int find(int [],int);

int front = -1; //empty
int rear = -1;  //
int array[max_vehicle];

int main(){
int i,num;
for (i=0; i<max_vehicle; i++){
printf("enter a vehicle no.[max = %d ]\n",max_vehicle);
scanf("%d",&num);
push(num,i);
}
while(all_finished!=max_vehicle)
{
printf("enter a vehicle no. to get back..\n");
scanf("%d",&num);
if(find(full_list_of_vehicle,num))
printf("no. = %d\n",pop(num));
else 
printf("not found that vehicle number...\n");
}
printf("All finished !!!\n");
return 0;
}

void push(int num,int i)
{
if(rear == max_vehicle-1){
printf("queue is full\n");
return;
}
array[++rear] = num;
full_list_of_vehicle[i] = num;
if(front == -1)
front = 0;
}


int pop(int number)
{
if(front == -1){
printf("queue is empty..\n");
return;
}
if(array[front] == number){
rear--;
all_finished++;
return array[front++];
}else{
printf("you have to wait....");
return 0;
}
}

int find(int a[max_vehicle],int num){
int i;
for(i=0;i<max_vehicle;i++){
if(a[i]  == num)
return 1;
}
return 0;
}
