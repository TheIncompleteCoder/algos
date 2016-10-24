//subject : algo
//time : Mon 22 Aug 2016 02:39:49 PM IST 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

typedef struct postfix_expression{
int stack_of_ele[MAX];
int top,number;
char *string;
}POSTFIX;

void set(POSTFIX *,char *);
void push(POSTFIX *,int);
int pop(POSTFIX *);
void solve_problem(POSTFIX *);
void display(POSTFIX);
 
 
//driver-program
int main(int argc,char **argv){
POSTFIX p;
p.top =-1;
char expression[MAX];
printf("enter postfix expression...\n");
gets(expression);
set(&p,expression);
solve_problem(&p);
display(p);
return 0;
}

void display(POSTFIX p){
p.number = pop(&p);
printf("Result of above expr is :%d\n",p.number);
//printf("Result of above expr is :%d\n",pop(&p));
}

void set(POSTFIX *p,char *str){
p->string = str;
}

void push(POSTFIX *p,int data){
if(p->top == MAX-1){
printf("Stack is full\n");
}else{
p->top++;
p->stack_of_ele[p->top] = data;
}
}

int pop(POSTFIX *p){
int data;
if(p->top == -1){
printf("Stack is empty\n");
return (int)NULL;
}
data = p->stack_of_ele[p->top];
p->top--;
return data;
}

void solve_problem(POSTFIX *p){
int num1,num2,num3;
while(*(p->string)){
if(*(p->string) == ' '|| *(p->string) == '\t'){
p->string++;
continue;
}
if(isdigit(*(p->string))){
p->number = *(p->string) - '0';
push(p,p->number);
}else{
num1 = pop(p);
num2 = pop(p);
switch(*(p->string)){
case '+':
num3 = num2 + num1;
break;

case '-':
num3 = num2 - num1;
break;

case '*':
num3 = num2 * num1;
break;

case '/':
num3 = num2 / num1;
break;

case '%':
num3 = num2 % num1;
break;

case '^':
num3 = (int)pow(num2,num1);
break;

default:
printf("oops! unknown operator...\n");
exit(0);
}
push(p,num3);
}
p->string++;
}
}
