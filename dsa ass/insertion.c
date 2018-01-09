
#include <stdio.h>
#include <math.h>
 #include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
      
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
 

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
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
   insertionSort(arr, size);
	t1=clock()-t1;
   double time_taken = ((double)t1)/CLOCKS_PER_SEC; 
 
    printf("insertion took %f seconds to execute size of %ld\n", time_taken,size);
    
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
