/**
 * @file 25.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  int i;
  long double sum = 0, mix = 1;

  for (i = 1; i <= 20; i++)
  {
    mix = mix * i;
    sum = sum + mix;
  }

  printf("%Lf\n", sum);

  return 0;
}