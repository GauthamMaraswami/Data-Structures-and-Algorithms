#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int visit[100],n;
void create()
{
int i,n1,n2,ch;
printf("enter the no of elements\n");
scanf("%d",&n);
for(i=1;i<=n;++i)
visit[i]=0;
do{

printf("enter the nodes which are connected and weigt n1 n2 w1 \n");
scanf("%d%d",&n1,&n2);

a[n1][n2]=1;
a[n2][n1]=1;
printf("do you want to add more edges\n");
scanf("%d",&ch);
}while(ch==1);

}

void main()
{


}
