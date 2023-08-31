#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue {
int rear,front;
int q[MAX];
};
void INSERT(int,struct queue *);
void DELETE(struct queue *);
void DISPLAY(struct queue *);
int main()
{
int choice, item;
struct queue s;
s.rear=-1;
s.front=0;
for(;;)
{
printf("Enter your choice\n1 Insertion\n2 Deletion\n3 Display\n4 Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:if(s.rear==MAX-1)
printf("Queue is full\n");
else
{
printf("Enter the element to be inserted\n");
scanf("%d",&item);
INSERT(item,&s);
}
break;
case 2:DELETE(&s);
break;
case 3:DISPLAY(&s);
break;
case 4:exit(0);
}
}
return 0;
}
void INSERT(int item,struct queue *s)
{
s->rear=s->rear+1;
s->q[s->rear]=item;
}
void DELETE(struct queue *s)
{
int item;
if(s->front>s->rear)
printf("Queue is empty\n");
else
{
item=s->q[s->front];
printf("%d deleted\n",item);
(s->front)++;
}
}
void DISPLAY(struct queue *s)
{
int i;
if(s->front>s->rear)
printf("Queue is empty\n");
else
{
printf("Elements in the queue are\n");
for(i=s->front;i<=s->rear;i++)
printf("%d ",s->q[i]);
printf("\n");
}
}
