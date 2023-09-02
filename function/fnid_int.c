#include <stdio.h>

int *find_int(int key, int array[], int array_len);

int *find_int(int key, int array[], int array_len)
{
  int i;
  for (i = 0; i < array_len; i++)
    if (array[i] == key)
      return &array[i];

  return NULL;
}

long factorial(int n)
{
  if (n <= 0)
    return 1;
  else 
    return n * factorial(n - 1);
}

struct tag { 
  int a;
  char b;
  float c;
} x;

struct tag { 
  int a;
  char b;
  float c;
} y[20], *z;

int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  char str[] = "Hello";

  printf("123: %c", *(str+1));

  return 0;
}