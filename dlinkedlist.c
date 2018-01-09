#include<stdio.h>
#include<stdlib.h>
struct node{
int d1;
struct node* next;
struct node* prev;
};
int sui=0;
struct node *header;
void display()
{
        struct node *ptr=header;
          if(ptr==NULL)
         printf("empty");

        while(ptr!=NULL)
           {
            printf("-->%d",ptr->d1);
            ptr=ptr->next;
           }
}

void insert(struct node *ptr,int dat)
{
    struct node *nptr=(struct node *) malloc(sizeof(struct node));
     nptr->d1=dat;
     nptr->next=NULL;
     nptr->prev=NULL;
printf("%d",nptr->d1);
    if(ptr==NULL){
        ptr=nptr;
       header=ptr;
      }
    else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        nptr->prev=ptr;
        ptr->next=nptr;
        }
printf("insert successful\n");
}
void insertatpos(struct node *ptr,int dat,int pos){
 struct node *nptr=(struct node *) malloc(sizeof(struct node));
 struct node *nptr1=(struct node *) malloc(sizeof(struct node));
    int ctr=0;
     nptr->d1=dat;
     nptr->next=NULL;
     nptr->prev=NULL;
printf("%d",nptr->d1);
    if(ptr==NULL){
        ptr=nptr;
       header=ptr;
      }
    else if(pos==0){
        header->prev=nptr;               
 nptr->next=header;
        header=nptr;
        }
    else if(pos<sui){
            while(ctr!=pos-1){
               ptr=ptr->next;
               ++ctr;
             }

          nptr1=ptr->next;
          nptr->prev=ptr;
          nptr->next=ptr->next;
          nptr1->prev=nptr;
          ptr->next=nptr;
 }
else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        nptr->prev=ptr;
        ptr->next=nptr;
        }
printf("insert successful\n");



}
void delete(struct node *ptr,int dat){
struct node *nptr=(struct node *) malloc(sizeof(struct node));
struct node *nptr1=(struct node *) malloc(sizeof(struct node));
if(ptr==NULL)
{
   printf("empty \n");
}
 else if(dat==header->d1){
if(sui==1)
{
header=NULL;
return;
}
else{
header=header->next;
header->prev=NULL;
}
}

else
{
     int flag=0;
       while(ptr->d1!=dat && ptr->next!=NULL)
        {

          flag=1;
          nptr=ptr;
          ptr=ptr->next;
          if(ptr->d1==dat)
             flag=2;

        }
          }

      if(flag==2){

        nptr1=ptr->next;
        nptr->next=ptr->next;
    if(nptr1!=NULL){
        nptr1->prev=nptr;
                }
          printf("delete sucessful\n");

        }
     else if(ptr->next==NULL){
      printf("element not found\n");}
}
}

void deletepos(struct node *ptr,int pos){
struct node *nptr=(struct node *) malloc(sizeof(struct node));
struct node *nptr1=(struct node *) malloc(sizeof(struct node));
if(ptr==NULL)
{
   printf("empty \n");
   return;
}

else if(pos==0){
if(sui==1)
{
header=NULL;
return;
}
else{
   header=header->next;
   header->prev=NULL;
}

}
else if(sui==0){
header=NULL;
printf("\n list empty\n");
}
else if(pos>=sui){
printf("cannot delete\n");

}
else{

      int ctr=0;
        while(ctr<pos){
              nptr=ptr;
          ptr=ptr->next;
           ++ctr;

           }
          nptr1=ptr->next;
          nptr->next=ptr->next;
nptr->next=ptr->next;
       if(nptr1!=NULL)
          nptr1->prev=nptr;
  printf("delete sucessful\n");

}

}

void main(){
int x,ch,pos;
printf("enter your choice\n 1-insert at end\n2-display\n3- delete node of value\n4-insert at given position\n5-delete node at pos\n 6-exit\n");
scanf("%d",&ch);
while(ch)
{


        if(ch==1)
                {printf("\nenter the value");
                scanf("%d",&x);
                insert(header,x);
                ++sui;
                }
        else if(ch==2){
                    printf("\nthe list now is  ");
                display();
                        }
        else if(ch==3){
                        printf("\nenter the value to be deleted");
                        scanf("%d",&x);
                  delete(header,x);
                        --sui;
                        }
        else if(ch==4){
                        printf("enter the value and position of the node to insert:");
                        scanf("%d",&x);
                        scanf("%d",&pos);
                       if(pos>sui)
                      {
                        printf("cannot insert\n");
                    }
                   else{
                  insertatpos(header,x,pos);
                      ++sui;
                        }}
        else if(ch==5){
                        printf("enter the position of element to be deleted");
                        scanf("%d",&pos);
                        deletepos(header,pos);
                        --sui;
                }
        else if(ch==6){
                    break;}
scanf("%d",&ch);

}


}


