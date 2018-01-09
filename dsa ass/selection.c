#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 

        swap(&arr[min_idx], &arr[i]);
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
    selectionSort(arr, size);
	t1=clock()-t1;
   double time_taken = ((double)t1)/CLOCKS_PER_SEC; 
 
    printf("selection took %f seconds to execute size of %ld\n", time_taken,size);
    
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
