
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
 
       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
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
    quickSort(arr, 0,size-1);
	t1=clock()-t1;
   double time_taken = ((double)t1)/CLOCKS_PER_SEC; 
 
    printf("quick took %f seconds to execute size of %ld\n", time_taken,size);
 
   free(arr);
    return 0;
}
void main()
{
long int size=50000;

for(;size<=500000;size=size+25000)
{
 gotofun(size);
}
}
