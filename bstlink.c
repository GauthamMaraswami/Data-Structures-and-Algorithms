#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node* left;
struct node* right;
};
int barr[100];
void insert(int n,struct node* nptr)
{
if (nptr==NULL)
{
 nptr=(struct node *)malloc(sizeof(struct node));
 nptr->val=n;
 nptr->left=NULL;
 nptr->right=NULL;
}
else{
 printf("lol\n");
   if(n>nptr->val)
      {
	if(nptr->right==NULL)
         {
	struct node* nptr1=(struct node *)malloc(sizeof(struct node));
	 nptr1->val=n;
 	nptr1->left=NULL;
 	nptr1->right=NULL;
	nptr->right=nptr1;
	}
	else
	  insert(n,nptr->right);
      }
   else if(n<nptr->val)
	{
	if(nptr->left==NULL)
         {
	struct node* nptr1=(struct node *)malloc(sizeof(struct node));
	 nptr1->val=n;
 	nptr1->left=NULL;
 	nptr1->right=NULL;
	nptr->left=nptr1;
	}
	else
	  insert(n,nptr->left);
	}
 
}
}
/*void input()
{
int n;
char ch='y';

printf("enter the number\n");
scanf("%d",&n);
insert(n,root);
printf("do you want to add more y or n\n");
scanf("%c",&ch);
}while(ch=='y');

}*/
int delete(int n, struct node* nptr)
{
	int r;
if(nptr==NULL)
	{
	return 1;
        }
else if(n==nptr->val)
  { 
	if(nptr->left==NULL&& nptr->right==NULL)
          {
           nptr=NULL;
	  }
	else if(nptr->right!=NULL)
	  {
	  nptr->val=((nptr->right)->val);
	  delete((nptr->right)->val,nptr->right);
	  }
	else if(nptr->left!=NULL)
	  {
	  nptr->val=((nptr->left)->val);
	  delete((nptr->left)->val,nptr->left);
	  }
	return 0;
	
  }

else if(n>nptr->val){
       r=delete(n,nptr->right);
         return r; 
	}
else if(n<nptr->val)
	{
	r=delete(n,nptr->left);
	return r;
	}
}


int delete1(int n,struct node* nptr)
{printf("doesnt jjjjjjjjjjjjjjjjjdelete\n");
int r;
if(nptr==NULL)
return 1;
else if(n>nptr->val){
//printf("doesnt delete\n");
       r=delete1(n,nptr->right);

         return r; 
	}
else if(n<nptr->val)
	{
	
	r=delete1(n,nptr->left);
	return r;
	}

else if (n==nptr->val){
//printf("doesnt jkkkkkkkkkkdelete\n");
if(nptr->left==NULL&& nptr->right==NULL)
          {
         
          free(nptr);
	  }

else {
struct node *nptr1=(struct node *)malloc(sizeof(struct node));
nptr1=nptr->right;
while((nptr1->left)!=NULL)
nptr1=nptr1->left;
nptr->val=nptr1->val;
//printf("jjjjjj%dkkkkkkkkkkkk%djjjjjjjj\n",nptr->val,nptr1->val);
   delete1(nptr->val,nptr1);
return 0;

}


}




}

int find(int n, struct node* nptr)
{
	int r;
if(nptr==NULL)
	{
	return 1;
        }
else if(n==nptr->val)
  { 
	
	return 0;
	
  }

else if(n>nptr->val){
       r=find(n,nptr->right);
         return r; 
	}
else if(n<nptr->val)
	{
	r=find(n,nptr->left);
	return r;
	}
}

void inorder(struct node* nptr)
{
if(nptr==NULL )
return;
else {
inorder(nptr->left);
printf("%d-->",nptr->val);
inorder(nptr->right);

}

}



void main()
{int ch,n,res;
 struct node *root=(struct node *)malloc(sizeof(struct node));
        root->left=NULL;
        root->right=NULL;
 printf("enter the number\n");
	scanf("%d",&n);
	root->val=n;
printf("enter youour choice\n1-insert \n 2-delete\n 3-search \n4-stop\n");
scanf("%d",&ch);
while(ch<=5){
if(ch==5)
 break;
switch (ch)
{
case 1:	
	
       printf("enter the number\n");
	scanf("%d",&n);
	insert(n,root);
	printf("insert successful\n");
	break;
case 2:
       	printf("enter the node to delete\n");
	scanf("%d",&n);
        res=delete1(n,root);
        if(res==0)
          printf("deletio;n successful\n");
        else
          printf("deletion failed\n"); 
	break;
case 3:
	
	printf("enter the node to search\n");
	scanf("%d",&n);
        res=find(n,root); 
	if(res==0)
          printf("find successful\n");
        else
          printf("find failed\n");
	break;
case 4: 
     inorder(root);
        break;

}
printf("enter your op\n");
scanf("%d",&ch);
}
}
