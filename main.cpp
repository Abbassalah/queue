#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


//creat an queue
typedef struct  queue
{
    int rear,front,size;
    unsigned  capacity;
    int *array;
} queue;
//initializing a queue
queue *create_queue(unsigned capacity)
{

    queue *que= (queue*)malloc(sizeof(queue));
    que->capacity=capacity;
    que->front =que->size=0;
    que->rear=capacity-1;
    que->array=(int*)malloc(sizeof(int)*que->capacity);
    return que;
}
//check QUEUE is FULL
int isFULL(queue *que)
{
    if (que->rear=(que->capacity)-1) return 0;
    else
    {
        /*do_nothing*/
    }

}
//CHECK THAT QUEUE IS  EMPTY
int isEMPTY(queue *que)
{
    if (que->size == 0)return -1;

    else
    {
        /*do nothing*/
    }
}
// add elements to a queue
void enqueue(queue * que, int item)
{
    if (isFULL(que))return;
    que->rear=(++que->rear%que->capacity);
    que->array[que->rear]=item;
    que->size ++;
    printf("%d\n",item);
}
// remove an item from queue;
int dequeue (queue *que)
{
    if (!(isEMPTY(que)))return -1;
    else
    {
        int item = que->array[que->front];
        que->front=++que->front%que->capacity;
        que->size--;
        return item;
    }
}

int front_queue(queue* que)
{
    if (isEMPTY(que))return -1;
    else return que->array[que->front];
}


// rear queue
int rear_queue (queue *que)
{
    if (isEMPTY(que))return -1;
    else return que->array[que->rear];

}

void print_queue(queue *que)
{
    while(!isEMPTY(que))
    {
        printf("%d\n",front_queue(que));
        dequeue(que);
    }

}

// Driver code
int main()
{
    queue* que = create_queue(1000);

    enqueue(que, 10);
    enqueue(que, 20);
    enqueue(que, 30);
    enqueue(que, 40);
    //print_queue(que);

    cout<<dequeue(que)<<" dequeued from queue\n";

    cout << "Front item is " << front_queue(que) << endl;
    cout << "Rear item is " << rear_queue(que) << endl;

    return 0;
}
