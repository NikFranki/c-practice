/*
 * 1.9
 * Write a program to use string array, get lonest string
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinestring(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
  int len;               // current line length
  int max;               // maximum length seen so far
  char line[MAXLINE];    // current input line
  char longest[MAXLINE]; // longest line saved here

  max = 0;
  while ((len = getlinestring(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) // there was a line
  {
    printf("最长的字符串是： %s", longest);
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

// copy 'from' into 'to'; assume to a big enough
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}
