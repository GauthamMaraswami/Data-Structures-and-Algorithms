#include<stdio.h>
#include<stdlib.h>
struct node{
int dat;
struct node* left;
struct node* right;
};


void input(struct node* nptr,int data){
int ch,i;
//struct node* nptr1;
if(nptr==NULL)
{	return;
}
printf("do you want to go right-1,do you want to go left-2\n");
	scanf("%d",&ch);
if(ch==1&&nptr->right==NULL){
	struct node *nptr2=(struct node *)malloc(sizeof(struct node));
	
	
	nptr2->dat=data;
	(nptr2)->left=NULL;
	(nptr2)->right=NULL;
	nptr->right=nptr2;
	
}
else if(ch==1){
          input(nptr->right,data);
	}
else if(ch==2&&nptr->left==NULL){
	struct node *nptr2=(struct node *)malloc(sizeof(struct node));
	
	
	nptr2->dat=data;
	(nptr2)->left=NULL;
	(nptr2)->right=NULL;
	nptr->left=nptr2;
	
}
else if(ch==2){
input(nptr->left,data);
}
	
	
    
}

void preorder(struct node* nptr)
{
	if(nptr==NULL){return;}
	else{printf(" %d ",(nptr)->dat);
        preorder((nptr)->left);
	preorder((nptr)->right);
	}

}

void inorder(struct node* nptr)
{
	if(nptr==NULL){return;}
	else{
        inorder(nptr->left);
	printf(" %d ",(nptr)->dat);
	inorder((nptr)->right);
	}

}

void postorder(struct node* nptr)
{
	if(nptr==NULL){return;}
	else{
        postorder((nptr)->left);
	postorder((nptr)->right);
	printf(" %d ",(nptr)->dat);
	}

}
int main(){
	struct node *root=(struct node *)malloc(sizeof(struct node));
        root->left=NULL;
	root->right=NULL;
	int ch,d;
	printf("enter the th root\n");
         scanf("%d",&(root->dat));
	do{
		printf("enter next node value\n");
		scanf("%d",&d);
		input(root,d);
		printf("do you want to add more yes-1 no-2\n");
		scanf("%d",&ch);
	}while(ch==1);
	
	printf("\npreorder");
	preorder(root);
	printf("\npostorder");
	postorder(root);
	printf("\ninorder");
	inorder(root);
return 0;
}
