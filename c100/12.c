/**
 * @file 12.c
 * @author your name (you@domain.com)
 * @brief 判断 101 到 200 之间的素数。
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  int i, j;
  int count = 0;

  for (i = 101; i <= 200; i++)
  {
    for (j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        break;
      }
    }

    if (j >= i)
    {
      count++;
      printf("%d ", i);
      if (count % 5 == 0)
      {
        printf("\n");
      }
    }
  }

  return 0;
}