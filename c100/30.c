/**
 * @file 30.c
 * @author your name (you@domain.com)
 * @brief 一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  long one, two, three, four, five, x;
  printf("please input 5 continutive number: ");
  scanf("%ld", &x);
  five = x / 10000;
  four = x % 10000 / 1000;
  two = x % 100 / 10;
  one = x % 10;

  if (one == five && two == four)
  {
    printf("这是回文数\n");
  }
  else
  {
    printf("这不是回文数\n");
  }

  return 0;
}