#include<stdio.h>
#include<stdlib.h>
#define max 30
char stack[max], c[max], d[max];
int top=-1, j=0, k=0;
char pop();
void push(char);
int main()
{
char a[30], b[30], sym;
int m=0,i;
printf("Enter a string\n");
gets(a);
if(a[0]=='\0')
printf("Enter valid string\n");
else
{
for(i=0;a[i]!='\0';i++)
m++;
for(i=0;i<m;i++)
{
sym=a[i];
push(sym);
}
for(i=0;(i<m)&&(top!=-1);i++)
b[i]=pop();
b[i]='\0';
d[k]='\0';
printf("Reverse of given string is\n");
printf("%s\n",d);
for(i=0;b[i]!='\0';i++)
{
if(c[i]!=b[i])
{
printf("String is not a palindrome\n");
exit(0);
}
}
printf("String is a palindrome\n");
}
return 0;
}
void push(char sym)
{
if(top==max-1)
{
printf("Stack is full\n");
return;
}
top++;
stack[top]=sym;
if(sym!=' ')
c[j++]=sym;
}
char pop()
{
if(top==-1)
{
printf("Stack is empty\n");
exit(0);
}
if(stack[top]==32)
d[k++]=stack[top--];
d[k++]=stack[top];
return (stack[top--]);
}
