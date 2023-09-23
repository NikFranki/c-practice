/**
 * @file 24.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1 有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
 * @date 2023-09-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int i, t;
  float sum = 0;
  float a = 2, b = 1;
  for (i = 1; i <= 20; i++)
  {
    sum = sum + a / b;
    t = a;
    a = a + b;
    b = t;
  }

  printf("%9.6f\n", sum);

  return 0;
}