#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
int top;
int items[MAX];
};
void push(int,struct stack *);
void pop(struct stack *);
void display(struct stack *);
int main()
{
struct stack s;
s.top=-1;
int choice,item;
for(;;)
{
printf("Enter your choice\n");
printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter the item\n");
scanf("%d",&item);
push(item,&s);
break;
case 2: pop(&s);
break;
case 3: display(&s);
break;
case 4: exit(0);
}
}
return 0;
}
void push(int item,struct stack *s)
{
if(s->top==MAX-1)
printf("The stack is full\n");
else
{
(s->top)++;
s->items[s->top]=item;
}
}
void pop(struct stack *s)
{
int item;
if(s->top==-1)
printf("The stack is empty\n");
else
{
item=s->items[s->top];
(s->top)--;
printf("%d deleted\n",item);
}
}
void display(struct stack *s)
{
int t=s->top;
if(s->top==-1)
printf("The stack is empty\n");
else
{
printf("Elements in the stack are\n");
while(t>-1)
{
printf("%d ",s->items[t--]);
}
printf("\n");
}
}
