/**
 * @file 14.c
 * @author your name (you@domain.com)
 * @brief 将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int n, i;
  printf("please input a number: ");
  scanf("%d", &n);
  for (i = 2; i < n; i++)
  {
    while (n % i == 0)
    {
      printf("%d", i);
      n /= i;
      if (n != 1)
      {
        printf("*");
      }
    }
  }

  printf("\n");
  return 0;
}