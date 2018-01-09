#include <stdlib.h>
#include <time.h>
#include<stdio.h>
 

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    
 
   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        
        int m = l+(r-l)/2;
 
      
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int gotofun(long size)
{
	int *arr;
    
	time_t t,t1;
srand((unsigned) time(&t));
    

	arr=(int *) malloc(size*sizeof(int));
         for(int i=0;i<size;++i)
             {
		*(arr+i)= rand() % 500000;		
		}
    

      printf("\n");
     t1=clock();
    mergeSort(arr,0, size-1);
	t1=clock()-t1;
   double time_taken = ((double)t1)/CLOCKS_PER_SEC; 
 
    printf("merge took %f seconds to execute size of %ld\n", time_taken,size);
   
    return 0;
    free(arr);
}
void main()
{
long int size=50000;
for(;size<=500000;size=size+25000)
{
 gotofun(size);
}
}

