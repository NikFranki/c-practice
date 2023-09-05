/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define TABW 8
#define MAXL 1000

int line(char s[], int lim);
void detab(char src[], char tar[]);

int main()
{
  // test line
  char s[MAXL];
  char t[MAXL * TABW];

  while (line(s, MAXL))
  {
    detab(s, t);
    printf("%s", t);
  }
  return 0;
}

int line(char s[], int lim)
{
  char c;
  int i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }
  if (c == '\n')
  {
    s[i++] = '\n';
  }
  s[i] = '\0';
  return i;
}

void detab(char src[], char tar[])
{
  int i;
  int j = 0;
  int spacew;
  char c;

  for (i = 0; (c = src[i]) != '\0'; i++)
  {
    if (c != '\t')
    {
      tar[j++] = c;
    }
    else
    {
      spacew = TABW - j % TABW;
      while (spacew-- > 0)
      {
        tar[j++] = '-';
      }
    }
  }
  tar[j] = '\0';
}