#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[500010];
void heapify(int );
void insert(int k,int i1){
arr[i1]=k;
heapify(i1);
//printf("insert successful\n");
}
void heapify(int pos)
{
 int te;
int back=(pos-1)/2;
if(arr[pos]>arr[back])
  {
        te=arr[pos];
        arr[pos]=arr[back];
        arr[back]=te;
        heapify(back);
  }


}


}
void swap(int * a,int *b)
{
int te;
te=*a;
*a=*b;
*b=te;


}

void heapify1(int n,int i)
{
  int largest=i;
  int l=2*i+1;
  int r=2*i+2;
if(l<n&&arr[l]>arr[largest])
 largest=l;
if(r<n && arr[r]>arr[largest])
 largest=r;
if(largest!=i)
  {
swap(&arr[largest],&arr[i]);
  heapify1(n,largest);
}


}
void heapsort1(int n)
{
int i;
for(i=n/2+1;i>=0;--i)
   heapify1(n,i);
for(i=n-1;i>=0;--i)
{
swap(&arr[0],&arr[i]);
heapify1(i,0);
}

}





void heapsort(int n)
{int te,k,i;
while(n>0)
{
te=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=te;
--n;
k=n-1;
for( i=k;i>=0;--i)
   {
 heapify(i);
}
}
/*
void heapify1(int k)
{
int s,l,te,b;
l=2*i+1;
s=2*i+2;
if(arr[l]>arr[k]);
 {
 te=arr[l];
arr[l]=arr[k];
arr[k]=te;

heapify1()
}

*/


main()
{
int n,k,i;
printf("enter the number of elements\n");
scanf("%d",&n);
time_t t,t1,t2;
srand((unsigned) time(&t));
arr[0]= rand() % 500000;

//printf("enter the elements\n");
//scanf("%d",&arr[0]);
for(i=1;i<n;++i)
{
k= rand() % 500000;
//scanf("%d",&k);
insert(k,i);
}
/*
for(i=0;i<n;++i)
{
printf(" %d  ",arr[i]);

}*/
t1=clock();
heapsort1(n);
t2=clock();

   double time_taken = t2-t1;
double time_taken1= ((double)time_taken)/CLOCKS_PER_SEC;

   printf("heap took %f seconds to execute size of %ld\n", time_taken1,n);


printf( " \n ");
/*
for(i=0;i<n;++i)
{
printf( " %d  ",arr[i]);

}
*/
printf("heap ready\n");

