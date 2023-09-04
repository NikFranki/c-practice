/*
 * Exercise 1-17
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinestring(char s[], int lim);

int main()
{
  int len;            // current line length
  char line[MAXLINE]; // current input line

  while ((len = getlinestring(line, MAXLINE)) > 0)
  {
    if (len > 18)
    {
      printf("%s", line);
    }
  }

  return 0;
}

// read a line into s, return length
int getlinestring(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
