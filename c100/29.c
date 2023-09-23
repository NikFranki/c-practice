/**
 * @file 29.c
 * @author your name (you@domain.com)
 * @brief 给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  long a, b, c, d, e, x;
  printf("please input 5 continutive numbers: ");
  scanf("%ld", &x);
  a = x / 10000; // 分解出万位
  b = x % 10000 / 1000; // 分解出千位
  c = x % 1000 / 100; // 分解出百位
  d = x % 100 / 10; // 分解出十位
  e = x % 10; // 分解出个位

  if (a != 0)
  {
    printf("为5位数，逆序为：%ld %ld %ld %ld %ld\n", e, d, c, b, a);
  }
  else if (b != 0)
  {
    printf("为4位数，逆序为：%ld %ld %ld %ld\n", d, c, b, a);
  }
  else if (c != 0)
  {
    printf("为3位数，逆序为：%ld %ld %ld\n", c, b, a);
  }
  else if (d != 0)
  {
    printf("为2位数，逆序为：%ld %ld\n", b, a);
  }
  else if (e != 0)
  {
    printf("为4位数，逆序为：%ld\n", a);
  }

  return 0;
}