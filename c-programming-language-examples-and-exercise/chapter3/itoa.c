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
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  char s[1000];
  int n = -200000;

  itoa(n, s);
  printf("%s\n", s);

  return 0;
}

void reverse(char s[])
{
  char c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
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

  reverse(s);

  s[i] = '\0';
}