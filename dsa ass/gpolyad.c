#include<stdio.h>
#include<stdlib.h>

struct node1
{   int data;
    struct node1 *address;
};
struct node1 *header1=NULL;
struct node2
{   int data;
    struct node2 *address;
};
struct node2 *header2=NULL;
struct node3
{   int data;
    struct node3 *address;
};
struct node3 *header3=NULL;

createnode3(struct node3 *ptr1, int d)
{       struct node3 *ptr2=(struct node3 *)malloc(sizeof(struct node3));
	struct node3 *ptrx=(struct node3 *)malloc(sizeof(struct node3));
        ptrx=header3;
        ptr2->data=d;
        ptr2->address=NULL;
        if(header3==NULL)
           header3=ptr2;
        else
           {
		while(ptrx->address!=NULL)
		{ptrx=ptrx->address;
		}
                 ptrx->address=ptr2;
		
           }
}


addition(struct node1 *ptrw, struct node2 *ptry, int d)
{       struct node1 *ptr1=(struct node1 *)malloc(sizeof(struct node1));
        ptr1=header1;
	struct node2 *ptr2=(struct node2 *)malloc(sizeof(struct node2));
        ptr2=header2;
	int sum=0,i;
        for(i=0;i<=d;i++)
        {sum=(ptr1->data)+(ptr2->data);
	 printf("%d",sum);
         createnode3(header3,sum);
         ptr1=ptr1->address;
         ptr2=ptr2->address;
         printf("%d",sum);
        }
       while(ptr1->address!=NULL)
         { 
            sum=ptr1->data;
	    createnode3(header3,sum);
            ptr1=ptr1->address;
	}
       while(ptr2->address!=NULL)
         { 
            sum=ptr2->data;
	    createnode3(header3,sum);
            ptr2=ptr2->address;
	}
      printf("addition successful\n");
}

createnode1(struct node1 *ptr1, int d)
{       struct node1 *ptr2=(struct node1 *)malloc(sizeof(struct node1));
struct node1 *ptrx=(struct node1 *)malloc(sizeof(struct node1));
        ptrx=header1;
        ptr2->data=d;
        ptr2->address=NULL;
        if(header1==NULL)
           header1=ptr2;
        else
           {while(ptrx->address!=NULL)
		{ptrx=ptrx->address;
		}
                 ptrx->address=ptr2;
           }
}

createnode2(struct node2 *ptr1, int d)
{       struct node2 *ptr2=(struct node2 *)malloc(sizeof(struct node2));
struct node2 *ptrx=(struct node2 *)malloc(sizeof(struct node2));
        ptrx=header2;
        ptr2->data=d;
        ptr2->address=NULL;
        if(header2==NULL)
           header2=ptr2;
        else{
		while(ptrx->address!=NULL)
		{ptrx=ptrx->address;
		}
                 ptrx->address=ptr2;
		}
 }


display(struct node3 *ptr1, int d)
{       int i;
        printf("The Resulting Polynomial:\n ");
        for(i=0;i<=d;i++)
           {
            if(i==0)
            printf("%d+", ptr1->data);
            else if(i==d)
            printf("%dx^%d\n", ptr1->data, i);
            else
            printf("%dx^%d +",ptr1->data,i);
            ptr1=ptr1->address;
           }
}

main()
{       int d,d1,d2,n,i;
        printf("Enter the maximum degree of the first  polynomial\n");
        scanf("%d", &d1);
        printf("Enter the maximum degree of the second polynomail\n");
        scanf("%d", &d2);
        if(d1>=d2)
                d=d2;
        else
                d=d1;
        printf("\nFor the first polynomial:\n");
        for(i=0;i<=d1;i++)
        {printf("Enter the co-efficient of n^%d: ", i);
         scanf("%d", &n);
         createnode1(header1,n);
        }
        printf("\nFor the second polynomial:\n ");
        for(i=0;i<=d2;i++)
        {printf("Enter the co-efficient of n^%d: ",i);
         scanf("%d", &n);
         createnode2(header2,n);
        }
    printf("flkjk\n");
        addition(header1,header2,d);
        display(header3,d);

}

