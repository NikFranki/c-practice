/*
 * Exercise 2-5
 * Write an function any function
 */

#include <stdio.h>

int any(char s1[], char s2[]);
int indexof(char s2[], char c);

int main()
{
  char s1[] = "dfadsfads";
  char s2[] = "gggggs";

  int index = any(s1, s2);
  printf("%d\n", index);

  return 0;
}

int indexof(char s[], char c)
{
  int i = 0;
  char ch;

  while ((ch = s[i++]) != '\0')
  {
    if (ch == c)
    {
      return --i;
    }
  }

  return -1;
}

int any(char s1[], char s2[])
{
  int i;
  char c;

  for (i = 0; (c = s1[i]) != '\0'; i++)
  {
    if (indexof(s2, c) != -1)
    {
      return i;
    }
  }

  return -1;
}