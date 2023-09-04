/*
 * 1.7.
 * Write a program to implement power function
 */

#include <stdio.h>

int power(int base, int n);

int main()
{
  for (int i = 0; i < 10; i++)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));

  return 0;
}

int power(int base, int n)
{
  int p = 1;

  int i;
  for (i = 0; i < n; i++)
  {
    p = p * base;
  }

  return p;
}