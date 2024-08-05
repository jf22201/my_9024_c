#include <stdio.h>
#include "queue.h"
#include <stdlib.h>


QueuePtr createQueue(){
    QueuePtr returnPtr = (QueuePtr) malloc(sizeof(struct Queue));
    returnPtr->num_items = 0;
    return returnPtr;
}

void enqueue(QueuePtr pQueue,QUEUE_ITEM_TYPE item){
    QueueNodePtr newNodePtr = (QueueNodePtr) malloc(sizeof(struct QueueNode));
    newNodePtr->value = item;
    if (pQueue->num_items < 1){
        pQueue->queueHead = newNodePtr;
        pQueue->queueTail = newNodePtr;
    }
    else{
    pQueue->queueTail->nextNode = newNodePtr;
    pQueue->queueTail = newNodePtr;
    }
    pQueue->num_items++;
}

QUEUE_ITEM_TYPE dequeue(QueuePtr pQueue){
    if(pQueue->num_items>0){
    QueueNodePtr removeNodePtr = pQueue->queueHead;
    pQueue->queueHead = pQueue->queueHead->nextNode;
    removeNodePtr->nextNode = NULL;
    QUEUE_ITEM_TYPE ret_value = removeNodePtr->value;
    free(removeNodePtr);
    pQueue->num_items--;
    return ret_value;
    }
    else{
        printf("queue is empty\n");
        return NULL;
    }
    
}


int isQueueEmpty(QueuePtr pQueue){
    return pQueue->num_items<=0;
}