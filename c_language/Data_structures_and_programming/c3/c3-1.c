#include<stdio.h>
#include<stdlib.h>

#define MAX 128
#define ENQUEUE_SUCCESS  1
#define ENQUEUE_FAILURE -1
#define DEQUEUE_SUCCESS  2
#define DEQUEUE_FAILURE -2
#define PEEK_SUCCESS     3
#define PEEK_FAILURE    -3

void queue_init(int *front, int *rear){
    *front = -1;
    *rear = -1;
}

int enqueue(int q[], int *rear, int data){
    if(*rear < MAX -1){
        *rear = *rear + 1;
        q[*rear] = data;
        printf("enqueue #%d %d ", *rear, data);
        return ENQUEUE_SUCCESS;
    } else {
        return ENQUEUE_FAILURE;
    }
}

int dequeue(int q[], int *front, int rear, int *data){
    if(*front == rear){
        return DEQUEUE_FAILURE;
    }
    *front = *front + 1;
    *data = q[*front];
    return DEQUEUE_SUCCESS;
}

void queue_display(int q[], int front, int rear){
    int i;
    if(front == rear){
        printf("QUEUE empty!");
    }
    printf("[ ");
    for(i = front + 1; i <= rear; i++){
        printf("%d ", q[i]);
    }
    printf("]\n");
}

int peek_front(int q[], int front, int rear, int *data){
    if(front == rear){
        return PEEK_FAILURE;
    }
    *data = q[front + 1];
    return PEEK_SUCCESS;
}

int main(){
    int queue[MAX];
    int front, rear, data;
    int stat;
    
    queue_init(&front, &rear);
    enqueue(queue, &rear, 100);
    queue_display(queue, front, rear);
    enqueue(queue, &rear, 200);
    queue_display(queue, front, rear);
    enqueue(queue, &rear, 300);
    queue_display(queue, front, rear);
    enqueue(queue, &rear, 400);
    queue_display(queue, front, rear);
    enqueue(queue, &rear, 500);
    queue_display(queue, front, rear);
    while(rear - front){
        stat = dequeue(queue, &front, rear, &data);
        if(stat == DEQUEUE_SUCCESS){
            printf("dequeue #%d %d ", front, data);
            queue_display(queue, front, rear);
        } else {
            printf("QUEUE is empty\n");
        }
    }
    
    int d[] = {680,670,690,650,660};
    queue_init(&front, &rear);
    data = 0;
    
    int i;
    for(i = 0; i < 5; i++){
        printf("enqueue: %d\n", d[i]);
        enqueue(queue, &rear, d[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        dequeue(queue, &front, rear, &data);
        printf("dequeue: %d\n", data);
    }
    
    printf("\n");
    peek_front(queue, front, rear, &data);
    printf("peek_front: %d\n", data);
    
    return 0;
}
