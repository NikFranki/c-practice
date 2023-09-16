/**
 * @file 13.c
 * @author your name (you@domain.com)
 * @brief 打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int x, y, z, i;

  for (i = 100; i <= 1000; i++)
  {
    x = i % 10; // 个数位
    y = i / 10 % 10; // 十分位
    z = i / 100 % 10; // 百分位

    if (i == (x*x*x + y*y*y + z*z*z))
    {
      printf("%d ", i);
    }
  }

  return 0;
}