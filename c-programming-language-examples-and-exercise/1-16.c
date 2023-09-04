/*
 * Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrary long input lines,
 * and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinestring(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
  int len;            // current line length
  char line[MAXLINE]; // current input line

  while ((len = getlinestring(line, MAXLINE)) > 0)
  {
    printf("%5d: %s", len, line);
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
