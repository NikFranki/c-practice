/**
 * @file 10.c
 * @author your name (you@domain.com)
 * @brief 打印楼梯，同时在楼梯上方打印两个笑脸。
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

  printf("\1\1\n");
  for (i = 1; i < 11; i++)
  {
    for (j = 1; j <= i; j++)
    {
      printf("%c%c", 219,219);
    }
    printf("\n");
  }

  return 0;
}