#include<stdio.h>
#include<stdlib.h>
int a[100];
void input(int pos){
int ch,i;
if(a[pos]==0)
  {
    printf("enter the node\n");
    scanf("%d",&a[pos]);
    return;
  }
else {
      printf("got to right-1,go to left-2\n");
      scanf("%d",&ch);
      if(ch==1)
        {
          i=2*pos+1;
          input(i);
        }
        else{
          i=2*pos+2;
          input(i);
        }

        return; }
}

void insert()
 { int ch;
  do{
      input(0);
   printf("do you want to add more?? 1-yes 2-no\n");
   scanf("%d",&ch);
    }while(ch==1);

}




void postorder(int pos)
{
if(a[pos]==0)
return;
else
{
int i,j;
i=2*pos+1;
postorder(i);
j=2*pos+2;
postorder(j);
printf(" %d ",a[pos]);
}}
void inorder(int pos)
{
if(a[pos]==0)
return;
else
{
int i,j;
i=2*pos+1;
inorder(i);
printf(" %d ",a[pos]);
j=2*pos+2;
inorder(j);
}}
void preorder(int pos)
{
if(a[pos]==0)
return;
else{
int i,j;
printf(" %d ",a[pos]);
i=2*pos+1;
preorder(i);

j=2*pos+2;
preorder(j);
}}

void main(){
int ch;
int i;
for(i=0;i<100;++i)
a[i]=0;
printf("enter the tree\n");
insert();
printf("preorder=");
preorder(0);
printf("\npostorder=");
postorder(0);
printf("\ninorder=");
inorder(0);

}

