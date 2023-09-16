/**
 * @file 16.c
 * @author your name (you@domain.com)
 * @brief 输入两个正整数m和n，求其最大公约数和最小公倍数。
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int a, b, t, r, n;
  printf("please input two number: \n");
  scanf("%d %d", &a, &b);
  if (a < b)
  {
    t = b;
    b = a;
    a = t;
  }

  r = a % b;
  n = a * b;

  while (r != 0)
  {
    a = b;
    b = r;
    r = a % b;
  }
  printf("%d %d\n", b, n / b);

  return 0;
}