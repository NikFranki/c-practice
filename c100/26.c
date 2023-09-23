/**
 * @file 26.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  int i;
  int fact(int);

  for (i = 0; i < 6; i++)
  {
    printf("%d!=%d\n", i, fact(i));
  }

  return 0;
}

int fact(int j)
{
  int sum;
  if (j == 0)
  {
    sum = 1;
  }
  else
  {
    sum = j * fact(j - 1);
  }
  return sum;
}