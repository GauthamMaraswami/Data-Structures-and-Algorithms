#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node* next;
}aptr[100];
//struct node* aptr;
int a[100][100];
int visit[100],n;




void create1()
{
int i,n1,n2,ch;
printf("enter the no of elements\n");
scanf("%d",&n);
for(i=1;i<=n;++i)
visit[i]=0;
do{

printf("enter the nodes which are connected and weigt n1 n2  \n");
scanf("%d%d",&n1,&n2);

a[n1][n2]=1;
a[n2][n1]=1;
printf("do you want to add more edges\n");
scanf("%d",&ch);
}while(ch==1);

}





void create()
{
int i;
//aptr=(struct node*) malloc((n+1)*sizeof(struct node));
for(i=1;i<n+1;++i)
{/* printf("\nlol1\n");
  (aptr+i).val=i;
  (aptr+i)->next=NULL;*/
  aptr[i].val=i;
  aptr[i].next=NULL;
}

}

/*

void createedge(int a,int b){
int i=1;
struct node* nptr=(struct node*) malloc(sizeof(struct node));
nptr=&aptr[a];
while(nptr->next!=NULL)
 { 
 printf("lolll%d",nptr->val);
 nptr=nptr->next;
 }
struct node* nptr1=(struct node*)malloc(sizeof(struct node));
nptr1->val=b;
nptr1->next=NULL;
nptr->next=nptr1;

//free(nptr1);
nptr=&aptr[b];
while(nptr->next!=NULL)
  {nptr=nptr->next;
  printf("reached\n");

}
//struct node* nptr1=(struct node*)malloc(sizeof(struct node));
nptr1->val=a;
nptr1->next=NULL;
nptr->next=nptr1;
free(nptr1);
free(nptr);
}

*/



void createlink1(){
int i,j;
struct node* nptr1=(struct node*)malloc(sizeof(struct node));
struct node* nptr=(struct node*)malloc(sizeof(struct node));
struct node* nptr2=(struct node*)malloc(sizeof(struct node));
for(i=1;i<=n;++i)
 {
  nptr=&aptr[i];
  nptr2=nptr;
  for(j=1;j<=n;++j)
   {

    if(a[i][j]==1)
     {
      nptr1->val=j;
      nptr1->next=NULL;
      nptr->next=nptr1;
      nptr=nptr->next;
   //   printf("%d",nptr->val);
      printf("\nhiihihi\n");
     }
   }

		
		printf("%d root ",nptr2->val);
		while(nptr2->next!=NULL){
			nptr2=nptr2->next;
			printf("%d",nptr2->val);
		               }
		printf("\n");
	



  }
}


void printgraph()
{
	struct node* nptr=(struct node*) malloc(sizeof(struct node));
	int i,j;
for(i=1;i<n+1;++i)
{ for(j=1;j<n+1;++j)
    {
    printf("%d", a[i][j]);
    }
    printf("\n");
}
	for (i=1;i<=n;++i){
		nptr=&aptr[i];
		printf("%d root ",nptr->val);
		while(nptr->next!=NULL){
			nptr=nptr->next;
			printf("%d",nptr->val);
		               }
		printf("\n");
	}
}


void main()
{
int n,a,b,ch;

create1();
create();
//printf("\nlol\n");
//printgraph();
createlink1();
printgraph(n);




}
