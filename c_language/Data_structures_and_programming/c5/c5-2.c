/* code: c5-2.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_SIZE 6
#define QUEUE_EMPTY (-1)
struct node {
    int data;
    struct node *next;
};
typedef struct node NODE_TYPE;

void q_enque(NODE_TYPE ** front, NODE_TYPE ** rear, int data){
    NODE_TYPE *new_node;
    new_node = malloc(sizeof(NODE_TYPE));
    new_node->data = data;
    new_node->next = NULL;
    if(*rear == NULL){
        *front = *rear = new_node;
    }
    else{
        (*rear)->newx = new_node;
        *rear = new_node;
    }
}