
#ifndef priorityQueue
#define priorityQueue

#include "linkedList.h"
#include <stdio.h>

struct PriorityQueue
{
  LinkedList data;
};

typedef struct PriorityQueue PriorityQueue;

int priorityQueueLenght(PriorityQueue *queue)
{
  return linkedListLenght(&(queue->data));
}

void priorityQueueInit(PriorityQueue *queue) 
{
  linkedListInit(&(queue->data));
}

void priorityQueueInsert(PriorityQueue *queue, LinkedListNode *node)
{
  int i = 0;

  for (i = 0; i < priorityQueueLenght(queue); i++)
  {
    // current node
    LinkedListNode *current = linkedListGet(&(queue->data),i); 

    if (current->priority > node->priority)
      break; 
  }

  linkedListInsert(&(queue->data), node, i); 
}

#endif