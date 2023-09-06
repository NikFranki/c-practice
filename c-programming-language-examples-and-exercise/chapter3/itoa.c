/**
 * @file itoa.c
 * @brief write a function tranform integer into string
 * @version 0.1
 * @date 2023-09-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
  char s[1000];
  int n = -200;

  itoa(n, s);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)
  {
    n = -n;
  }

  i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';
}