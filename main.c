
#include "priorityQueue.h"

void pqEnqueue(PriorityQueue *pq, PRIORITY_DATA_TYPE priority) {
  priorityQueueEnqueue(pq, linkedListNodeCreate(priority));
}

LinkedListNode* pqPeek(PriorityQueue *pq) 
{
  return priorityQueuePeek(pq);
}

LinkedListNode* pqGet(PriorityQueue *pq, int position)
{
  return priorityQueueGet(pq, position);
}

PRIORITY_DATA_TYPE pqDequeue(PriorityQueue *pq) 
{
  LinkedListNode *a = priorityQueueDequeue(pq);
  PRIORITY_DATA_TYPE priority = a->priority;
  free(a);

  return priority;
}

int main()
{
  PriorityQueue pq;
  priorityQueueInit(&pq);

  pqEnqueue(&pq, 14);
  pqEnqueue(&pq, 5);
  pqEnqueue(&pq, 9);
  pqEnqueue(&pq, 0);
  pqEnqueue(&pq, 10);

  printf("el valor mas pequeño es: %d\n", pqPeek(&pq)->priority);
  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    linkedListNodeDisplay(pqGet(&pq,i));
  }

  printf("--- Pruebas de eliminacion ---\n");

  printf("%d eliminado\n", pqDequeue(&pq));
  printf("%d eliminado\n", pqDequeue(&pq));
  printf("%d eliminado\n", pqDequeue(&pq));
  printf("%d eliminado\n", pqDequeue(&pq));

  printf("el valor mas pequeño es: %d\n", pqPeek(&pq)->priority);
  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    linkedListNodeDisplay(pqGet(&pq,i));
  }

  priorityQueueFree(&pq);

  return 0;
}
