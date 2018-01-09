#include<stdio.h>
#include<stdlib.h>
struct node{
int dat;
struct node* next;
};
struct node* top=NULL;
void push(int x){
struct node* nptr=(struct node *) malloc(sizeof(struct node));
nptr->dat=x;
nptr->next=NULL;
if(top==NULL)
{
top=nptr;
}
else{
nptr->next=top;
top=nptr;
}

printf("peak element is%d\n ",top->dat);


}
void pop()
{
int pope;
if(top==NULL){
printf("empty stack");
return;
}
else{
pope=top->dat;
top=top->next;
}
printf("poped element is %d \n",pope);
}

void peak()
{
if(top==NULL)
printf("empty list\n");
else
printf("peak element=%d",top->dat);

}

main()
{

int x,ch;
printf("enter your choice \n1-insertion\n2-pop\n3-peak \n4- exit");
scanf("%d",&ch);
while(ch!=0)
{
if(ch==1)
{
printf("enter the element to insert into stack\n");
scanf("%d",&x);
push(x);
}
else if(ch==2)
{
pop();
}


else if(ch==3)
peak();
else if(ch==4)
break;
printf("enter your choice\n");
scanf("%d",&ch);
}


}

