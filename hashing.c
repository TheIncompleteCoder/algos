#include <stdio.h>
#include <stdlib.h>

#define bucket 10


typedef struct node{
int data;
struct node *next;
}Node;

int findIndex(int);
void append(Node **,int);
int ui();

int 
main(int argc,char *argv[]){
Node *pointer;
int array[bucket];
int index,key;
int coll_status;
int find_status;
while(1){
index = ui();
if(index!=0){
 if(index == 1){
  printf("enter a number..\n");
  scanf("%d",&key);
  coll_status = insertIntoHash(array,key);
  if(coll_status !=0)
  printf("no collision at index %d",coll_status);
  else
  printf("collision\n");
 }
 if(index == 2){
  find_status = findIndex(key);
  if(find_status !=0)printf("found\n");
  else printf("not found\n");
 }
 if(index == 3)
 exit(0);
}
else
{
printf("invalid selection..\n try again...\n");
continue;
}
}
return 0;
}

int ui(){
int index;
printf("1. insert into hash table.\n");
printf("2. delete from  hash table.\n");
printf("3. exit");
scanf("%d",&index);
if(index>=1 && index <=3)
return index;
else
return 0;
}

void  append(Node **pointerToList,int data)
{
Node *temp,*temp1 = *pointerToList;
temp = (Node *)malloc(sizeof(Node));
temp->data = data;
temp->next = NULL;

if(*pointerToList == NULL)
{
*pointerToList =  temp;
}
else
{
while(temp1->next!=NULL)
 temp1 = temp1->next;

temp1->next = temp;
}
}

