
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      

      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}


void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
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
    bubbleSort(arr, size);
	t1=clock()-t1;
   double time_taken = ((double)t1)/CLOCKS_PER_SEC; 
 
    printf("bubble took %f seconds to execute size of %ld\n", time_taken,size);
   
	free(arr);
    return 0;
}

void main()
{
long int size=450000;
for(;size<=500000;size=size+25000)
{
 gotofun(size);
}}
