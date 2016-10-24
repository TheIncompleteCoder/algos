#include <stdio.h>
#include <malloc.h>
// node with data and next pointer...

typedef struct node{
int data;
struct node *next;
}Node;

// all possible operation's

void append(Node **,int); // add_at_end();
void addAtBegin(Node **,int);
void addAfterX(Node *,int,int);
void deleteX(Node **,int);
int count(Node *);
void showList(Node *);



// driver program

int main()
{
Node *start = NULL;
// add nodes one after another...
printf("append function\n");
append(&start,10);
append(&start,12);
append(&start,13);
append(&start,15);
append(&start,19);

showList(start);

printf("add at begin function\n");
addAtBegin(&start,9);
addAtBegin(&start,1);

showList(start);

printf("add after location function\n");
addAfterX(start,2,11);
addAfterX(start,5,16);

showList(start);

printf("delete function\n");
deleteX(&start,10);
deleteX(&start,15);
deleteX(&start,19);

showList(start);

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


void showList(Node *pointerToList)
{
while(pointerToList!=NULL)
{
printf("linked list data = %d\n",pointerToList->data);
pointerToList = pointerToList->next;
}
printf("\n");
}


void addAtBegin(Node **pointerToList,int data)
{
Node *temp;
temp = (Node *)malloc(sizeof(pointerToList));
temp->data = data;
temp->next = *pointerToList;
*pointerToList = temp;
}

void addAfterX(Node *pointerToList,int location,int data)
{
Node *temp,*temp1 = pointerToList;
int i;

for(i = 0;i < location;i++)
{
temp1=temp1->next;
 if(temp1==NULL)
 {
  printf("not enough nodes!!!!\n");
 return;
 }
}
temp = (Node *)malloc(sizeof(pointerToList));
temp->data = data;
temp->next = temp1->next;
temp1->next = temp;
}

void deleteX(Node **pointerToList,int data)
{

}

int count(Node *pointerToList)
{
int number = 0;
while(pointerToList!=NULL)
{
number++;
pointerToList = pointerToList->next;
}
return number;
}
