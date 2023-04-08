
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

/**
 * libera la memoria
 * @param queue direccion a la lista 
 */
void priorityQueueFree(PriorityQueue *queue) 
{
  linkedListFree(&(queue->data));
}

/**
 * Revisar el primer valor de la lista
 * @warning liberar la memoria a la direccion despues de usarla
 * @param queue direccion a la lista
 * @return una copia del primer nodo
 */
LinkedListNode *priorityQueuePeek(PriorityQueue *queue)
{
  LinkedListNode *foo = linkedListNodeCopy(linkedListGet(&(queue->data), 0));
  return foo;
}

/**
 * Eliminar el valor al inicio de la lista
 * @warning liberar la memoria a la direccion despues de usarla
 * @param queue direccion a la lista
 * @return direccion al elemnto eliminado
 */
LinkedListNode *priorityQueueRemove(PriorityQueue *queue)
{
  LinkedListNode *foo = linkedListNodeCopy(linkedListGet(&(queue->data), 0));
  linkedListRemove(&(queue->data), 0);
  return foo;
}

/**
 * Insertar el nodo en la lista
 * @param queue direccion a la lista
 * @param node direccion al nodo
 */
void priorityQueueInsert(PriorityQueue *queue, LinkedListNode *node)
{
  int i = 0;

  while (i < priorityQueueLenght(queue))
  {
    // incrementar i hasta encontrar la posicion con
    // mayor prioridad que el nodo que queremos insertar

    LinkedListNode *current = linkedListGet(&(queue->data), i);

    if (current->priority > node->priority)
      // lista en orden asendente
      break;

    i++;
  }

  // insertar el nodo en 'i'
  linkedListInsert(&(queue->data), node, i);
}

#endif