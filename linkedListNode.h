
/**
 * AUTOR: Luis Eduardo Galindo Amaya                           FECHA: 26-02-2023
 *
 * DESCRIPCIÓN:
 * En este archivo se encuentrara todos los metodos para crear nodos para
 * linkedList.
 */

#ifndef linkedListNode
#define linkedListNode

#define PRIORITY_DATA_TYPE int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedListNode
{
  /* Propiedades */
  PRIORITY_DATA_TYPE priority;

  /* Required */
  struct LinkedListNode *next;
};

typedef struct LinkedListNode LinkedListNode;

/**
 * Crear un nodo para la lista
 */
LinkedListNode *linkedListNodeCreate(PRIORITY_DATA_TYPE priority)
{
  LinkedListNode *foo = malloc(sizeof(LinkedListNode));

  if (foo == NULL)
  {
    printf("LinkedListNodeCreate: No se pudo reservar memoria!!\n");
    exit(EXIT_FAILURE);
  }

  foo->priority = priority;

  return foo;
}

/**
 * Copiar un nodo de la lista
 * @param node direccion al nodo
 * @return
 */
LinkedListNode *linkedListNodeCopy(LinkedListNode *node)
{
  return linkedListNodeCreate(node->priority);
}


#endif
