
#include "priorityQueue.h"

void linkedListNodeDisplay(LinkedListNode *node)
{
  printf("prioridad: %d\n", node->priority);
}

int main()
{
    PriorityQueue pq;
    priorityQueueInit(&pq);

    priorityQueueInsert(&pq, linkedListNodeCreate(14)); 
    priorityQueueInsert(&pq, linkedListNodeCreate(10));
    priorityQueueInsert(&pq, linkedListNodeCreate(12));
    priorityQueueInsert(&pq, linkedListNodeCreate(9));
    priorityQueueInsert(&pq, linkedListNodeCreate(0));

    for (int i = 0; i < priorityQueueLenght(&pq); i++)
    {
        LinkedListNode *foo = linkedListGet(&pq.data,i);
        linkedListNodeDisplay(foo);
    }
    

    return 0;
}
