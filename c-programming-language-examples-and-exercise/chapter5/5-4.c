/**
 * @file 5-4.c
 * @author your name (you@domain.com)
 * @brief Write the function strend(s, t),
 * which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
 * @version 0.1
 * @date 2023-09-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
  printf("%d\n", strend("abcde", "cdef"));
  return 0;
}

int strend(char s[], char t[])
{
  int lens = strlen(s);
  int lent = strlen(t);

  if (!lent || lens < lent)
    return 0;

  while (lent > 1)
  {
    if (*(t + lent--) != *(s + lens--))
    {
      return 0;
    }
  }

  return 1;
}