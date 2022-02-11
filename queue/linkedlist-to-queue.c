/*
** 一个用链表实现的队列，没有长度的限制
*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QUEUE_NODE {
  QUEUE_TYPE value;
  struct QUEUE_NODE *next;
} QueueNode;

static QueueNode*front;
static QueueNode*rear;

void destroy(void)
{
  while(!is_empty())
  {
    delete();
  }
}

void insert(QUEUE_TYPE value)
{
  QueueNode*new_node;

  new_node = (QueueNode *)malloc(sizeof(QueueNode));
  assert(new_node != NULL);
  new_node->value = value;
  new_node->next = NULL;

  if (rear == NULL)
  {
    front = new_node;
  }
  else
  {
    rear->next = new_node;
  }
  rear = new_node;
}

void delete(void)
{
  QueueNode *next_node;

  assert(!is_empty());
  next_node = front->next;
  free(front);
  if (front == NULL)
  {
    rear = NULL;
  }
}

QUEUE_TYPE first(void)
{
  assert(!is_empty());
  return front->value;
}

int is_empty(void)
{
  return front == NULL;
}

int is_full(void)
{
  return 0;
}