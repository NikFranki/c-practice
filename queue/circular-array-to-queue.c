#include <stdio.h>
#include <stdlib.h>

typedef int Element_Type;

typedef struct ArrayQueue
{
  int front;
  int rear;
  int max_size;
  int capacity;
  Element_Type *array;
}AQ;

AQ *create_queue(int max)
{
  AQ *aq;
  aq = (AQ *)malloc(sizeof(AQ));
  aq->array = (Element_Type *)malloc(sizeof(Element_Type) * max);
  if (aq->array == NULL)
  {
    printf("内存分配失败");
    exit(-1);
  }
  else {
    aq->front = 0;
    aq->rear = 0;
    aq->capacity = 0;
    aq->max_size = max;
    return aq;
  }
}

// 入队
void enqueue(AQ *aq, Element_Type data)
{
  if (aq->capacity >= aq->max_size)
  {
    printf("队列已满！");
    exit(-1);
  }
  else
  {
    if (aq->capacity == 0)
    {
      aq->array[aq->rear] = data;
    }
    else
    {
      aq->rear = (++aq->rear) % aq->max_size;
      aq->array[aq->rear] = data;
    }
    aq->capacity++;
  }
}

// 出队
void dequeue(AQ *aq, Element_Type *data)
{
  if (aq->capacity == 0)
  {
    printf("队列为空！");
    exit(-1);
  }
  else
  {
    *data = aq->array[aq->front];
    aq->front = (++aq->front) % aq->max_size;
    aq->capacity--;
  }
}

void print_queue(AQ *aq)
{
  if (aq->capacity == 0)
  {
    printf("队列为空！");
    exit(-1);
  }

  for (int i=0; i<aq->capacity; i++)
  {
    printf("%d ", aq->array[i]);
    putchar('\n');
  }
}

int main(void)
{
  int length, i;

  printf("请输入队列的长度：\n");
  scanf("%d", &length);
  AQ *queue;
  queue = create_queue(length);

  printf("请输入队列元素：\n");
  int data;
  for (i=0; i<length; i++)
  {
    scanf("%d", &data);
    enqueue(queue, data);
    data = 0;
  }

  Element_Type *data1;
  dequeue(queue, data1);

  printf("打印队列\n");
  print_queue(queue);

  return 0;
}