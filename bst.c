/*
author : @kashNagwanshi@gmail.com
github : TheIncompleteCoder@github
code' : Binary search tree and possible operations...
# insertion
# deletion 
# traversal
# finding height
# finding levels
# finding number of leaf nodes{count}
# finding total number of nodes{count}
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0


// bst_node ...
typedef struct btreenode{
struct btreenode *leftchild;
int data;
struct btreenode *rightchild;
}bstNode;


// operations...
void insert(bstNode **, int);
void postorder(bstNode *);
void preorder(bstNode *);
void inorder(bstNode *);
bstNode *mirrorImage(bstNode *);
int ui();
void search(bstNode **,int,bstNode **,bstNode **,int *);
void delete(bstNode **,int);
int height_of_tree(bstNode *);
int levels_of_tree(bstNode *);
int total_number_of_nodes(bstNode *);
int total_number_of_leaf_nodes(bstNode *);
int max(int,int);
int 
main(int argc,char *argv[]){
bstNode *btree = NULL;
int req,i,number,index;
while(1){
index = ui();
if(index == 1){
printf("\nenter number of elements to be inserted[max-size]\n");
scanf("%d",&req);
i=0;
while(i++<req){
printf("enter element:\n");
scanf("%d",&number);
insert(&btree,number);
}
printf("\n");
}

if(index == 2){
printf("\n");
printf("In-order traversal:\n");
inorder(btree);
printf("\n");
}
if(index == 3){
printf("\n");
printf("Pre-order traversal:\n");
preorder(btree);
printf("\n");
}
if(index == 4){
printf("\n");
printf("Post-order traversal:\n");
postorder(btree);
printf("\n");
}

if(index == 5){
printf("enter element to delete:\n");
scanf("%d",&number);
delete(&btree,number);
printf("\n");
}
if (index == 6)
printf("height of tree %d\n",height_of_tree(btree));
if (index == 7)
printf("level of tree = %d\n",levels_of_tree(btree));
if (index == 8)
printf("total_number_of_leaf_nodes = %d\n",total_number_of_leaf_nodes(btree));
if (index == 9)
printf("total number of nodes in tree is = %d\n",total_number_of_nodes(btree));

if(index == 10){
printf("mirror image of tree is:\n");
mirrorImage(btree);
inorder(btree);
}
if(index == 11){
printf("Bye:\n");
exit(1);
}
}
printf("\n");
return 0;
}


void 
insert(bstNode **pointer,int data){
if(*pointer == NULL){
*pointer = (bstNode *)malloc(sizeof(bstNode));
(*pointer)->leftchild = NULL;
(*pointer)->data = data;
(*pointer)->rightchild = NULL;
return;
}
else{
if(data < (*pointer)->data)
insert(&((*pointer)->leftchild),data);
else
insert(&((*pointer)->rightchild),data);
}
return;
}

void 
inorder(bstNode *pointer){
if(pointer!=NULL){
inorder(pointer->leftchild);
printf("%d ",pointer->data);
inorder(pointer->rightchild);
}else
return;
}

void 
preorder(bstNode *pointer){
if(pointer!=NULL){
printf("%d ",pointer->data);
preorder(pointer->leftchild);
preorder(pointer->rightchild);
}else
return;
}

void 
postorder(bstNode *pointer){
if(pointer!=NULL){
postorder(pointer->leftchild);
postorder(pointer->rightchild);
printf("%d ",pointer->data);
}else
return;
}

int 
ui()
{
int index;
printf("Choose option[1-11]:\n");
printf("1. Enter elements\n");
printf("2. in-order traversal\n");
printf("3. pre-order traversal\n");
printf("4. post-order traversal\n");
printf("5. delete a node\n");
printf("6. find height of the tree\n");
printf("7. find level of the tree\n");
printf("8. total number of leaf nodes\n");
printf("9. total number of nodes\n");
printf("10. finding mirror image\n");
printf("11. exit\n");
scanf("%d",&index);
if(index >=1 && index <=11)
return index;
else{
printf("invalid selections\n");
ui();
}
}



void 
delete(bstNode **pointer , int data){
int found;
bstNode *parent,*x,*xsucc;
if(*pointer == NULL){
printf("Tree is empty\n");
return;
}
parent = x =NULL;
search(pointer,data,&parent,&x,&found);
if(found == FALSE){
printf("data to be deleted , not found in the list\n");
return;
}
// if 2 children
if(x->leftchild!=NULL && x->rightchild!=NULL){
parent = x;
xsucc = x->rightchild;

while(xsucc->leftchild!= NULL){
parent = xsucc;
xsucc = xsucc->leftchild;
}
x->data = xsucc->data;
x = xsucc;
}

//if no child
if(x->leftchild == NULL && x->rightchild == NULL){
if(parent->rightchild == x)
 parent->rightchild = NULL;
else
 parent->leftchild = NULL;
free(x);
return;
}
// if only right child
if(x->leftchild == NULL && x->rightchild!= NULL){
if(parent->leftchild == x)
parent->leftchild = x->rightchild;
else
parent->rightchild = x->rightchild;
free(x);
return;
}

// if only left child
if(x->leftchild!= NULL && x->rightchild ==  NULL){
if(parent->leftchild == x)
parent->leftchild = x->leftchild;
else
parent->rightchild = x->leftchild;
free(x);
return;
}
}

void 
search(bstNode **pointer,int number,bstNode **parent,bstNode **x,int *found){
bstNode *temp;
temp = *pointer;
*found = FALSE;
*parent  = NULL;

while(temp!=NULL){
if(temp->data == number){
*found = TRUE;
*x = temp;
return;
}
*parent = temp;
if(temp->data > number)
temp = temp->leftchild;
else
temp = temp->rightchild;
}
}

int 
max(int a,int b){
return a>b?a:b;
}

/*
           5          ------ height 0
          / \         
         4   8        ------ height 1 
        / \ / \
       3  2 6  9      ------ height 2
*/


int 
height_of_tree(bstNode *pointer){
int count,left,right;
if(pointer == NULL)
return 0;
if(pointer->leftchild == NULL && pointer->rightchild == NULL)
return 0;
else{
left = height_of_tree(pointer->leftchild);
right = height_of_tree(pointer->rightchild);
count = 1+ max(left,right);
}
return count;
}

/*
           5          ------ level 1
          / \         
         4   8        ------ level 2
        / \ / \
       3  2 6  9      ------ level 3
*/

int 
levels_of_tree(bstNode *pointer){
int count,left,right;
if(pointer == NULL)
return 0;
if(pointer->leftchild == NULL && pointer->rightchild == NULL)
return 1;
else{
left = levels_of_tree(pointer->leftchild);
right = levels_of_tree(pointer->rightchild);
count = 1+ max(left,right);
}
return count;

}

/*
           5        if only root return 1; 
          / \         -->2 ^ 0 +
         4   8        -->2 ^ 1 +
        / \ / \          ----------
       3  2 6  9         -->2 ^ 2
*/


int 
total_number_of_nodes(bstNode *pointer){
int count,left,right;
if(pointer == NULL)
return 0;
if(pointer->leftchild == NULL && pointer->rightchild == NULL)
return 1;
else{
left = total_number_of_nodes(pointer->leftchild);
right = total_number_of_nodes(pointer->rightchild);
count = left + right + 1;
}
return count;
}

/*
           5        
          / \         
         4   8        
        / \ / \          
       3  2 6  9        o/p : 4 leftchild == NULL and rightchild == NULL return 1;
*/

int 
total_number_of_leaf_nodes(bstNode *pointer){
int count,left,right;
if(pointer == NULL)
return 0;
if(pointer->leftchild == NULL && pointer->rightchild == NULL)
return 1;
else{
left = total_number_of_leaf_nodes(pointer->leftchild);
right = total_number_of_leaf_nodes(pointer->rightchild);
count = left + right;
}
return count;
}

/*

mirror function
             9
		 /  \
		5    8
	    / \  / \	
	   4  6 7  10
1 pass:
	      8
	     / \	
	    10  7
	  
2. pass	        
		5   
	    / \  
	   4  6 
	  
3. pass
      9
		 /  \
		5    8
	    / \  / \	
	   6  4 10  7
	  	  
so on..................
too boring.....

*/


bstNode *mirrorImage(bstNode *root){
bstNode *temp;
if(root == NULL) return (root);
if(root->leftchild == NULL && root->rightchild == NULL)
return (root);
else{
temp = root->rightchild;
root->rightchild = mirrorImage(root->leftchild);
root->leftchild = mirrorImage(temp);
}
return (root);
}
