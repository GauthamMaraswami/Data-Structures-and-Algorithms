#include<stdio.h>
#include<stdlib.h>
struct node{
int d1;
struct node* next;
};
int sui=0;
struct node *header1;
struct node *header2;
struct node *header3;
void display()
{
        struct node *ptr=header1;
          if(ptr==NULL)
         printf("empty");

        while(ptr!=NULL)
           {
            printf("-->%d",ptr->d1);
            ptr=ptr->next;
           }
}

void main(){
char s[10];
printf("enter the first polynomial\'\n\'");
scanf("%s",s);



}


