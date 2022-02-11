#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define QUEUE_SIZE 100
#define ARRAY_SIZE (QUEUE_SIZE + 1)

static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

void insert(QUEUE_TYPE data)
{
  assert(!is_full());
  rear = (rear + 1) % ARRAY_SIZE;
  queue[rear] = data;
}

void delete()
{
  assert(!is_empty());
  front = (front + 1) % ARRAY_SIZE;
}

QUEUE_TYPE first()
{
  assert(!is_empty());
  return queue[front];
}

void print_queue()
{
  assert(!is_empty());
  for (int i=1; i<6; i++)
  {
    printf("%d ", queue[i]);
  }
  putchar('\n');
}

int is_empty()
{
  return (rear + 1) % ARRAY_SIZE == front;
}

int is_full()
{
  return (rear + 2) % ARRAY_SIZE == front;
}

int main(void)
{
  // test
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);

  print_queue();

  return 0;
}