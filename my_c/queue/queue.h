#ifndef QUEUE_H
#define QUEUE_H


typedef int QUEUE_ITEM_TYPE;
struct Queue;
typedef struct QueueNode *QueueNodePtr;
typedef struct Queue *QueuePtr;
typedef struct QueueNode QueueNode;
typedef struct Queue Queue;
QUEUE_ITEM_TYPE dequeue(QueuePtr pQueue);
void enqueue(QueuePtr pQueue,QUEUE_ITEM_TYPE item);
QueuePtr createQueue();
int isQueueEmpty(QueuePtr pQueue);
struct Queue{
QueueNodePtr queueHead;
QueueNodePtr queueTail;
int num_items;
};


struct QueueNode{
QUEUE_ITEM_TYPE value;
QueueNodePtr nextNode;
};
#endif
