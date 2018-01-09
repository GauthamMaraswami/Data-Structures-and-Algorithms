#include<stdio.h>
#include<string.h>
const int n=5;
int arr[5];
int front=-1,rear=-1;
void enque(int x)
{
if((rear+1)%n==front)
        {
        printf("overflow\n");
        return;
        }
else if(front==-1&&rear==-1)
        {
        front=rear=0;
         arr[rear]=x;
        }
//else if(front<rear)
  //  {    rear=(rear+1)%5;
//      arr[rear]=x;
//      }
//else if(front==(rear+1)%5)
//      {
//printf("overflow\n");
//      }
else
        {
    rear=(rear+1)%5;
    arr[rear]=x;
        }
}


int deque()
{
int res;
if(front==-1&&rear==-1)
        {
printf("underflow");
return -999;
        }
else if(front==rear)
        {
      res=arr[front];
      front=rear=-1;

return res;
        }


else
{
res=arr[front];
front=(front+1)%n;
return res;
}
}

void main(){
int ch,x;
ch=1;
printf("enter your choice\n 1-enque\n,2-deque\n,3-end\n");
scanf("%d",&ch);
while(ch<3)
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
scanf("%d",&ch);
}
}


