/*
BFS implemenatation using matrix
*/

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define n 7

 
// A structure to represent a queue
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};
 
 struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(
		sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(
		queue->capacity * sizeof(int));
	return queue;
}
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}
 
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}
 
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue)) {
        printf("%d\n",isFull(queue));

        printf("Queue is full\n");
    	return;
    }
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	// printf("%d enqueued to queue\n", item);
}
 
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue)) {
        printf("%d\n",isEmpty(queue));

        printf("queue is empty\n");
		return INT_MIN;
    }
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

 int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main(){
   
    
    // BFS Implementation 
    struct Queue* queue = createQueue(7);
    int node,no_of_edges;
    scanf("%d",&no_of_edges);
    int i = 7;
    int visited[n+1] = {0};
    int a[n+1][n+1];

    int edge_1, edge_2;
    for (int i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d",&edge_1,&edge_2);
        a[edge_1][edge_2] = 1;
        a[edge_2][edge_1] = 1;

    }
    
    printf("%d", i);
    visited[i] = 1;
    enqueue(queue, i); // Enqueue i for exploration
    while (!isEmpty(queue))
    {
        int node = dequeue(queue);
        for (int j = 1; j <= 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(queue, j);
            }
        }
    }
    return 0;
}
