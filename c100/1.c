/**
 * @file 1.c
 * @author your name (you@domain.com)
 * @brief 题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int i, j, k;
  printf("\n");
  for (i = 1; i < 5; i++)
  {
    for (j = 1; j < 5; j++)
    {
      for (k = 1; k < 5; k++)
      {
        if (i != k && i != j && j != k)
        {
          printf("%d, %d, %d\n", i, j, k);
        }
      }
    }
  }

  return 0;
}