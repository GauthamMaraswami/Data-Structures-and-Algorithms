#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{       int i,n,*arr;
        clock_t start,end;
        double time;
        printf("Enter the number of elements\n");
        
        scanf("%d", &n);
        arr=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        *(arr+i)=rand()%100;
        start=clock();
        bubblesort(arr,n);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("algorithm      time\n");
        printf("bubblesort     %lf seconds\n",time);
        for(i=0;i<n;i++)
        *(arr+i)=rand()%100;
        start=clock();
        selectionsort(arr,n);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("selection sort %lf seconds\n",time);
         for(i=0;i<n;i++)
        *(arr+i)=rand()%100;
        start=clock();
        partition(arr,0,n-1,n);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("mergesort      %lf seconds\n",time);
        for(i=0;i<n;i++)
        *(arr+i)=n-i;
        start=clock();
        quicksort(arr,0,n-1);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("quicksort      %lf seconds\n",time);
        for(i=0;i<n;i++)
        *(arr+i)=rand()%100;
        start=clock();
        insertionsort(arr,n);
        end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("insertionsort  %lf seconds\n", time);

}

insertionsort(int *a, int n)
{
        int i,j,k;
        for(i=1;i<n;i++)
        {
                j=i-1;
                k=*(a+i);
                while(*(a+j)>=k && j>=0)
                {
		*(a+j+1)=*(a+j);
                         j--;
                        }
                *(a+j+1)=k;
        }

}
quicksort(int *a,int low,int high)
{
        int pivot;
        if(low<high)
        {       pivot=partition1(a,low,high);
                quicksort(a,low,pivot);
                quicksort(a,pivot+1,high);
        }
}

int partition1(int *a, int low, int high)
{
        int i,j,t,pivot;
        i=low;
        j=high;
        pivot=*(a+i);
        for(;;)
        {
                while(*(a+i)<pivot && *(a+i)!=pivot)
                        i++;
                while(*(a+j)>pivot && *(a+j)!=pivot)
                        j--;
                if(i<j)
                {
                        t=*(a+i);
                        *(a+i)=*(a+j);
                        *(a+j)=t;
                }
                else return j;
        }
}





partition(int *arr, int low, int high, int n)
{       int mid;
        if(low<high)
        {   mid=(low+high)/2;
            partition(arr,low,mid,n);
            partition(arr,mid+1,high,n);
            mergesort(arr,low,mid,high,n);
        }
}

mergesort(int *arr, int low, int mid, int high,int n)
{       int i,m,k,l,*temp;
        temp=(int *)malloc(n*sizeof(int));
        l=low; i=low; m=mid+1;
        while(l<=mid && m<=high)
        {   if(*(arr+l)<=*(arr+m))
{   *(temp+i)=*(arr+l);
                l++;
            }
            else
            {   *(temp+i)=*(arr+m);
                m++;
            }
        i++;
        }
        if(l>mid)
        {   for(k=m;k<=high;k++)
                {*(temp+i)=*(arr+k);
                 i++;
                }
        }
        else
        {   for(k=l;k<=mid;k++)
               {*(temp+i)=*(arr+k);
                i++;
               }
        }
        for(k=low;k<=high;k++)
           *(arr+k)=*(temp+k);
}

selectionsort(int *arr, int n)
{       int i,small,pos,j;
        for(i=0;i<n-1;i++)
        {   small=*(arr+i);
            pos=i;
            for(j=i+1;j<n;j++)
            {   if(*(arr+j)<small)
                   {small=*(arr+j);
                    pos=j;
                   }
            }
        *(arr+pos)=*(arr+i);
        *(arr+i)=small;
        }
}


bubblesort(int *arr, int n)
{       int i,j,t;
        for(i=0;i<n-1;i++)
          {for(j=0;j<n-1-i;j++)
             {if(*(arr+j)>*(arr+j+1))
                {  t=*(arr+j);
                   *(arr+j)=*(arr+j+1);
 *(arr+j+1)=t;
                }
             }
          }
}
display(int *arr, int n)
{       int i;
        printf("The sorted array: ");
        for(i=0;i<n;i++)
          printf("%d  ", *(arr+i));
        printf("\n\n");
}



