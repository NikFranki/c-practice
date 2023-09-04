/*
 * 1.100
 * Write a program to use string array, get lonest string by using extern define
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinestring(void);
void copy(void);

int main()
{
  int len;               // current line length
  extern int max;        // maximum length seen so far
  extern char longest[]; // longest line saved here

  max = 0;
  while ((len = getlinestring()) > 0)
  {
    if (len > max)
    {
      max = len;
      copy();
    }
  }

  if (max > 0) // there was a line
  {
    printf("最长的字符串是： %s", longest);
  }

  return 0;
}

// specialized version: read a line into s, return length
int getlinestring(void)
{
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;
}

// specialized version: copy 'from' into 'to'; assume to a big enough
void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
  {
    ++i;
  }
}
