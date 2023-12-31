#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
struct node
{
int data;
struct node *llink,*rlink;
};
typedef struct node * NODE;
NODE construct_tree(char postfix[max])
{
if(postfix[0]==’\0’) return NULL;
char sym;
NODE newnode,stack[max];
int i,top=-1;
for(i=0;postfix[i]!='\0';i++)
{
sym=postfix[i];
newnode=(NODE)malloc(sizeof(struct node));
newnode->data=sym;
newnode->llink=NULL;
newnode->rlink=NULL;
if(isdigit(sym))
{
stack[++top]=newnode;
continue;
}
switch(sym)
{
case '+':
case '-':
case '*':
case '/': newnode->rlink=stack[top--];
newnode->llink=stack[top--];
stack[++top]=newnode;
break;
default: return NULL;
}
}
return stack[top--];
}
float evaluate(NODE root)
{
switch(root->data)
{
case '+':return(evaluate(root->llink)+evaluate(root->rlink));
case '-':return(evaluate(root->llink)-evaluate(root->rlink));
case '*':return(evaluate(root->llink)*evaluate(root->rlink));
case '/':return(evaluate(root->llink)/evaluate(root->rlink));
default: return(root->data - '0');
}
}
int main()
{
float res;
char postfix[max];
NODE root=NULL;
printf("Enter the postfix expression\n");
gets(postfix);
root=construct_tree(postfix);
if(root==NULL)
{
printf("Invalid input\n");
return 0;
}
res=evaluate(root);
printf("Result after evaluation is %.2f\n",res);
return 0;
}
