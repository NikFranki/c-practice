/**
 * @file 9.c
 * @author your name (you@domain.com)
 * @brief 要求输出国际象棋棋盘
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

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      if ((i + j) % 2 == 0)
      {
        printf("%c%c", 219, 219);
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}