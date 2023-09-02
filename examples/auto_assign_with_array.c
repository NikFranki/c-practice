#include <stdio.h>
#include <stdlib.h>

#define DELTA 5

int *readints()
{
  int *array;
  int size;
  int count;
  int value;

  size = DELTA;
  array = malloc((size + 1) * sizeof(int));
  if (array == NULL)
  {
    return NULL;
  }

  count = 0;
  while (scanf("%d", &value) == 1)
  {
    count += 1;
    if (count > size)
    {
      size += DELTA;
      array = realloc(array, (size + 1) * sizeof(int));
      if (array == NULL)
      {
        return NULL;
      }
    }
    array[count] = value;
  }

  if (count < size)
  {
    array = realloc(array, (count + 1) * sizeof(int));
    if (array == NULL)
    {
      return NULL;
    }
  }
  array[0] = count;

  printf("当前数组的个数为： %d", *array);

  return array;
}

int main()
{
  readints();
  return 0;
}