/**
 * @file 8.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int i, j, result;

  for (i = 1; i < 10; i++)
  {
    for (j = 1; j <= i; j++)
    {
      result = i * j;
      printf("%d*%d = %-3d", i, j, result);
    }
    printf("\n");
  }

  return 0;
}