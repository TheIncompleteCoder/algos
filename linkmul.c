//write a program for multiplication using list of number's in linked list.

//    list 1					list 2					list 3
// 1->2->4->5->9->7->8-> (x) 1->2->4->5->9->7->8-> = 1->5->5->2->4->6->1->1->7->6->4->8->4.

#include <stdio.h>
#include <malloc.h>
// node with data and next pointer...

typedef struct node{
int data;
struct node *next;
}Node;

// some possible operation's

void append(Node **,int); // add_at_end();
void showList(Node *);
void calc(Node **,Node **,Node **);
int count(Node *);
void addAtBegin(Node **,int );
void reverse(Node **);

// driver program

int main()
{
Node *list1 = NULL;
Node *list2 = NULL;
Node *list3 = NULL;
// add nodes one after another...
printf("append function\n");
append(&list1,1);
append(&list1,2);
append(&list1,3);
append(&list1,4);
append(&list1,9);

append(&list2,2);
append(&list2,3);
append(&list2,5);
append(&list2,6);
append(&list2,9);

showList(list1);
showList(list2);

reverse(&list1);
reverse(&list2);

showList(list1);
showList(list2);

calc(&list1,&list2,&list3);
showList(list3);
return 0;
}

void reverse(Node **pointerToList)
{
Node *temp1,*temp2,*temp3;
temp1 = *pointerToList;
temp2 = NULL;
while(temp1!=NULL)
{
temp3 = temp2;
temp2 = temp1;
temp1  = temp1->next;
temp2->next  = temp3;
}
*pointerToList = temp2;
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

void addAtBegin(Node **pointerToList,int data)
{
Node *temp;
temp = (Node *)malloc(sizeof(pointerToList));
temp->data = data;
temp->next = *pointerToList;
*pointerToList = temp;
}


void showList(Node *pointerToList)
{
while(pointerToList!=NULL)
{
printf("%d ",pointerToList->data);
pointerToList = pointerToList->next;
}
printf("\n");
}

void calc(Node **list1,Node **list2,Node **list3)
{
// core logic:
int carry,remainder,temp,i,sum,j,k;
Node *ptr = *list1; 
int countList1,countList2;
countList2 = count(*list2);
Node *array[countList2];
i=0;
while(*list1!=NULL && *list2!=NULL)
{
carry = 0;
remainder = 0;
array[i] = (Node *)malloc(sizeof(Node));
while((*list1)!=NULL)
{
temp = (*list1)->data * (*list2)->data + carry;
remainder = temp%10;
carry = temp/10;
//for debugging
//append(&(*list3),remainder);

addAtBegin(&array[i],remainder);
*list1 = (*list1)->next;
}

for(k= 0;k<i;k++){  // k < countList2
//addAtBegin(&array[i],0);
append(&array[i],0);
}

*list1  = ptr;
(*list2) = (*list2)->next;
i++;
}
//reverse(&(*list3));
//for debugging


for(i=0;i<countList2;i++){
reverse(&array[i]);
//showList(array[i]);
}
i=0;
while(array[i]->next!=NULL)
{
for(i=0;i<countList2;i++){
sum = array[i]->data + array[i+1]->data;
append(&(*list3),sum);
}
}
}

// for appending '0'
/*
for(k= 0;k<i;k++){  // k < countList2
//addAtBegin(&array[i],0);
append(&array[i],0);
}
*/

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
