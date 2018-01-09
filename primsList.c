#include<stdio.h>
#include<stdlib.h>

#define max 100


typedef struct node
{
        struct node* parent;
        int flag;
        int key;
        int index;
}node;

typedef struct cell
{
        struct cell* next;
        int weight;
        int other;
       /* //int flag;*/
}cell;

void swap(int* a, int *b)/* //O(1)*/
{
        int t = *a;
        *a = *b;
        *b = t;
}

void heapify(int arr[], node* v[], int n, int p)/* //O(log(n)), since maximum operations is eual to the height of the tree(goes downwards)*/
{
        int l=2*p+1, r=2*p+2, smallest=p;

        if(l<n && v[arr[l]]->key < v[arr[smallest]]->key)
                smallest = l;

        if(r<n && v[arr[r]]->key < v[arr[smallest]]->key)
                smallest = r;

        if(smallest!=p)
        {
                swap(&arr[p], &arr[smallest]);
                swap(&(v[arr[p]]->index) ,&(v[arr[smallest]]->index));

                heapify(arr, v, n, smallest);
        }
}

int deleteMin(int arr[], node* v[], int n)/* //O(log(n)), only heapify{O(log(n))} and constant time function withnin*/
{
        swap(&arr[0], &arr[n-1]);
        swap(&(v[arr[0]]->index) ,&(v[arr[n-1]]->index));

        heapify(arr, v, n-1, 0);

        return arr[n-1];
}

void bubbleUp(int arr[], node* v[], int i)/* //O(log(n)), since maximum operations is eual to the height of the tree(goes upwards)*/
{
int p = (i-1)/2;

        while((p>=0)&&(v[arr[p]]->key > v[arr[i]]->key))
        {
                swap(&arr[p], &arr[i]);
                swap(&(v[arr[p]]->index) ,&(v[arr[i]]->index));

                i = (i-1)/2;
                p = (i-1)/2;

        }
}

void decreaseKey(int arr[], node* v[], node* vertex, int nKey)/* //O(log(n))*/
{
        vertex->key = nKey;

        bubbleUp(arr, v, vertex->index); /*//accesing the index of the vertex = O(1), the corresponding vertex's index int the heapArray can be accesed in constant time*/
}

void main()
{
        cell**  graph;
        int size, i, j, k, weight;

        printf("Enter the size : ");
        scanf("%d", &size);

        graph = (cell**)malloc((size)*(sizeof(cell*)));

       /* //reading and display of the graph
        //# of operations = sum of degree of each vertex = 2*|E|  */
        printf("Enter the edges :\n");
        scanf("%d %d %d", &i, &j, &weight);

        while(i != j)
        {
                cell* temp = graph[i];

                cell* newNodeA = (cell*)malloc((size)*(sizeof(cell*)));
                newNodeA->next = NULL;
                newNodeA->weight = weight;
                newNodeA->other = j;

                cell* newNodeB = (cell*)malloc((size)*(sizeof(cell*)));
                newNodeB->next = NULL;
                newNodeB->weight = weight;
                newNodeB->other = i;

                if(temp == NULL)
                        graph[i] = newNodeA;
                else
                {
                        while(temp->next != NULL)
                                temp = temp->next;

                        temp->next = newNodeA;
                }

                temp = graph[j];
   if(temp == NULL)
                        graph[j] = newNodeB;
                else
                {
                        while(temp->next != NULL)
                                temp = temp->next;

                        temp->next = newNodeB;
                }

                scanf("%d %d %d", &i, &j, &weight);
        }

        printf("\nGraph as adjacency list (vertex-weight):\n");
        for(i = 0; i < size; i++)
        {
                cell* temp = graph[i];

                printf("%d\t", i);

                while(temp != NULL)
                {
                        printf("%d-%d\t", temp->other, temp->weight);
                        temp = temp->next;
                }
                printf("\n");
        }
        printf("\n");

        node** vertices = (node**)malloc(size*sizeof(node*));/*//Array of nodes to store the data of each vertices*/

        for(i = 0; i < size; i++)/*//O(n)*/
        {
                vertices[i] = (node*)malloc((size)*(sizeof(node)));
                vertices[i]->parent = NULL;
                vertices[i]->flag = 0;
                vertices[i]->key = max;
                vertices[i]->index = i;
        }

        int* heapArray = (int*)malloc((size)*(sizeof(int)));/*//Array of indexes of the vertices which is in a min heap(based on the vertex's key)*/

        for(i = 0; i < size; i++)
                heapArray[i] = i;

        int hsize = size;

        int src;
        printf("Enter the Source Node: ");
        scanf("%d", &src);

        /*//vertices[src]->key = 0;//Add the source vertex to the tree(Here source node is considered to be vertices[0])
        //vertices[0]->flag = 1;*/

        decreaseKey(heapArray, vertices, vertices[src], 0);


      /*  //Main loop*/
        for(i = 0; i < size-1; i++)/*//the loop runs |E| or (|V|-1){# of edges in a MST} or times*/
        {

  int p = deleteMin(heapArray, vertices, hsize);//O(log(n)) 
                hsize = hsize - 1;

                vertices[p]->flag = 1;

                cell *temp = graph[p];

                while(temp != NULL)/*//in each cycle the loop runs (degree of p) times, hence total # of cycles = sum of degree of all vertices = 2*|E|*/
                {
                        if((vertices[temp->other]->flag != 1) && (vertices[temp->other]->key > (temp->weight)) )
                        {
                                vertices[temp->other]->parent = vertices[p];

                                decreaseKey(heapArray, vertices, vertices[temp->other], temp->weight);  //O(log(n))                     
                        }

                        temp = temp->next;
                }

                /*for(j = 0; j < size; j++)
                        printf("%d\t", heapArray[j]);
                printf("\n");
                for(j = 0; j < size; j++)
                        printf("%d\t", vertices[j]->key);
                printf("\n\n");*/

        }

        for(i = 0; i < size; i++)
        {
                printf("vertex: %d\tkey: %d\n", i, vertices[i]->key);
        }

        int cost = 0;

        for(i=0; i < size; i++)
                cost+=vertices[i]->key;

        printf("Total weight : %d\n", cost);

}


