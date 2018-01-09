#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int d1;
struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enque(int x)
{
 struct node *nptr=(struct node *) malloc(sizeof(struct node));

     nptr->d1=x;
     nptr->next=NULL;
 if(front==NULL&&rear==NULL)
    {
        front=rear=nptr;
        rear->next=rear;
        printf("enqus sucessful\n");
    }
 else {
         rear->next=nptr;
         rear=rear->next;
         rear->next=front;
        printf("enqus sucessful\n");
        }
}
int deque()
{
struct node* ptr=(struct node *) malloc(sizeof(struct node));

int res;
if(front==NULL&&rear==NULL)
 {
   printf("underflow\n");
return -999;
}
else if(front->next==front){
   res=front->d1;
    front=rear=NULL;
   return res;
}
else{
       res=front->d1;
       rear->next=front->next;
       front=front->next;
       return res;
     }

}

void print()
{
struct node* ptr=(struct node *) malloc(sizeof(struct node));
  ptr=front;
if(front!=NULL&&rear!=NULL)
 { while(ptr->next!=front)
{
       printf("%d<-",ptr->d1);
          ptr=ptr->next;
}
 printf("%d<-",ptr->d1);
}
else
printf("empty");
}
void main()
{
int ch,x;
ch=1;
printf("enter your choice\n 1-enque\n,2-deque\n,3-print\n,4-end");
scanf("%d",&ch);
while(ch<=4)
{
if(ch==1)
{
printf("enter the element to enque\n");
scanf("%d",&x);
enque(x);
}
else if(ch==2)
{
x=deque();
if(x!=-999)
printf("dequed element is%d",x);
}
else if(ch==3)
print();
scanf("%d",&ch);
}

}
                                                                                                                                                                                          93,1          Bot

