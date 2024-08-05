#include <stdio.h>
#include "queue.h"

void main(){
    QueuePtr myQueue = createQueue();
    enqueue(myQueue,1);
    enqueue(myQueue,2);
    printf("%d",dequeue(myQueue));
    enqueue(myQueue,3);
    printf("%d",dequeue(myQueue));
    enqueue(myQueue,4);
    printf("%d",dequeue(myQueue));
    printf("%d",dequeue(myQueue));

}