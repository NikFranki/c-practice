/**
 * @file 5.c
 * @author your name (you@domain.com)
 * @brief 输入三个整数x,y,z，请把这三个数由小到大输出。
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  int x, y, z, t;

  printf("please input three numbers:\n");
  scanf("%d %d %d", &x, &y, &z);
  printf("start sort(position small -> big):\n");

  if (x > y)
  {
    t = x;
    x = y;
    y = t;
  }

  if (x > z)
  {
    t = x;
    x = z;
    z = t;
  }

  if (y > z)
  {
    t = y;
    y = z;
    z = t;
  }

  printf("final result: %d %d %d\n", x, y, z);

  return 0;
}