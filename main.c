
#include "priorityQueue.h"

void linkedListNodeDisplay(LinkedListNode *node)
{
  printf("prioridad: %d\n", node->priority);
}

void pqInsert(PriorityQueue *pq, PRIORITY_DATA_TYPE priority) {
  priorityQueueInsert(pq, linkedListNodeCreate(priority));
}

int main()
{
  PriorityQueue pq;
  priorityQueueInit(&pq);

  pqInsert(&pq, 14);
  priorityQueueInsert(&pq, linkedListNodeCreate(10));
  priorityQueueInsert(&pq, linkedListNodeCreate(12));
  priorityQueueInsert(&pq, linkedListNodeCreate(9));
  priorityQueueInsert(&pq, linkedListNodeCreate(0));

  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    LinkedListNode *foo = linkedListGet(&pq.data, i);
    linkedListNodeDisplay(foo);
  }

  printf("Pruebas de eliminacion\n");
  LinkedListNode *a = priorityQueueRemove(&pq);
  free(a);

  a = priorityQueueRemove(&pq);
  free(a);

  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    LinkedListNode *foo = linkedListGet(&pq.data, i);
    linkedListNodeDisplay(foo);
  }

  priorityQueueFree(&pq);

  return 0;
}
