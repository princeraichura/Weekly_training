#include <stdio.h>
#include <stdlib.h>
#define max 100

//queue structure
typedef struct{
    int front,rear,size,*queue;
}Queue;

Queue* create(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    q->size=max;
    q->queue=(int*)malloc(max*sizeof(int));
    return q;
}

int isempty(Queue *q){
    return q->front==-1;
}

int isfull(Queue *q){
    return q->rear==max-1;
}

void enq(Queue *q,int x){
    if (isfull(q)){
        printf("queue is full\n");
        return;
    }
    if(isempty(q)){
        q->front=0;
    }
    q->rear++;
    q->queue[q->rear]=x;
}

int deq(Queue *q){
    if(isempty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int x=q->queue[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front++;
    }
    return x;
}

void display(Queue *q){
    if(isempty(q)){
        printf("queue is empty\n");
        return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->queue[i]);
    }
    printf("\n");
}

int main(){
    Queue *q=create();
    enq(q,1);
    enq(q,2);
    enq(q,3);
    display(q);
    printf("removed element: %d\n",deq(q));
    display(q);
    return 0;
}