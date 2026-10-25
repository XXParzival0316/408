#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct QueueNode{
    Elemtype data; 
    struct QueueNode *next;
}QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}Queue;

Queue* initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

int isEmpty(Queue *q){
    if(q->front == q->rear){
        printf("空的\n");
        return 1;
    }else {
        return 0;
    }
}

void equeue(Queue *q, Elemtype e){
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue *q, Elemtype *e){
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if(q->rear == node){
        q->rear = q->front;
    }
    free(node);
    return 1;
}

Elemtype getFront(Queue *q){
    if(isEmpty(q)){
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}


int main(){
    Queue *q = initQueue();
    equeue(q, 50);
    equeue(q, 40);
    equeue(q, 30);
    equeue(q, 20);
    equeue(q, 10);

    Elemtype e;
    dequeue(q,&e);
    printf("出队%d\n",e);
    dequeue(q,&e);
    printf("出队%d\n",e);

    printf("%d\n",getFront(q));
        
    return 0;
}
