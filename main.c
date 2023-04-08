
#include "priorityQueue.h"

void linkedListNodeDisplay(LinkedListNode *node)
{
  printf("prioridad: %d\n", node->priority);
}

void pqInsert(PriorityQueue *pq, PRIORITY_DATA_TYPE priority) {
  priorityQueueInsert(pq, linkedListNodeCreate(priority));
}

LinkedListNode* pqPeek(PriorityQueue *pq) 
{
  return priorityQueuePeek(pq);
}

LinkedListNode* pqGet(PriorityQueue *pq, int position)
{
  return priorityQueueGet(pq, position);
}

PRIORITY_DATA_TYPE pqRemove(PriorityQueue *pq) 
{
  LinkedListNode *a = priorityQueueRemove(pq);
  PRIORITY_DATA_TYPE priority = a->priority;
  free(a);

  return priority;
}

int main()
{
  PriorityQueue pq;
  priorityQueueInit(&pq);

  pqInsert(&pq, 14);
  pqInsert(&pq, 5);
  pqInsert(&pq, 9);
  pqInsert(&pq, 0);
  pqInsert(&pq, 10);

  printf("el valor mas pequeño es: %d\n", pqPeek(&pq)->priority);
  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    linkedListNodeDisplay(pqGet(&pq,i));
  }

  printf("--- Pruebas de eliminacion ---\n");

  printf("%d eliminado\n", pqRemove(&pq));
  printf("%d eliminado\n", pqRemove(&pq));
  printf("%d eliminado\n", pqRemove(&pq));
  printf("%d eliminado\n", pqRemove(&pq));

  printf("el valor mas pequeño es: %d\n", pqPeek(&pq)->priority);
  for (int i = 0; i < priorityQueueLenght(&pq); i++)
  {
    linkedListNodeDisplay(pqGet(&pq,i));
  }

  priorityQueueFree(&pq);

  return 0;
}
