/*
 * Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinestring(char s[], int lim);
void trimr(char line[]);

int main()
{
  int len;            // current line length
  char line[MAXLINE]; // current input line

  while ((len = getlinestring(line, MAXLINE)) > 0)
  {
    trimr(line);
    if (line[0] != '\n' || line[0] != '\0')
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

void trimr(char line[])
{
  int mark;
  int i;

  i = 0;
  mark = -1;
  while (line[i] != '\n' && line[i] != '\0')
  {
    if (line[i] == ' ' || line[i] == '\t')
    {
      if (mark == -1)
      {
        mark = i;
      }
    }
    else
    {
      mark = -1;
    }
    i++;
  }

  if (mark != -1 && i > 0)
  {
    if (line[i] == '\n')
    {
      line[mark++] = '\n';
    }

    line[mark] = '\0';
  }
}
