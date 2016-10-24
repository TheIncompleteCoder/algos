#include <stdio.h>
#define max 5

void push(int);
int pop();
int front = -1; //empty
int rear = -1;  //
int array[max];

int main(){
int i,num;
for (i=0; i<5; i++){
printf("enter a no.\n");
scanf("%d",&num);
push(num);
}
for (i=0; i<5; i++){
printf("no. = %d\n",pop());
}
return 0;
}

void push(int num)
{
if(rear == max-1){
printf("queue is full\n");
return;
}
array[++rear] = num;
if(front == -1)
front = 0;
}


int pop()
{
if(front == -1){
printf("queue is empty..\n");
return;
}
rear--;
return array[front++];
}
