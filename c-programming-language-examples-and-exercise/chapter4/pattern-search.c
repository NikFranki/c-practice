#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getlinex(char line[], int lim);
int strindex(char line[], char pattern[]);

char pattern[] = "ould";

int main()
{
  char line[MAXLINE];
  int founded = 0;

  while (getlinex(line, MAXLINE) > 0)
  {
    if (strindex(line, pattern) >= 0)
    {
      printf("%s\n", line);
      founded++;
    }
  }

  return founded;
}

int getlinex(char line[], int lim)
{
  int i = 0;
  char c;

  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
  {
    line[i++] = c;
  }
  if (c == '\n')
  {
    line[i++] = c;
  }
  line[i] = '\0';

  return i;
}

int strindex(char s[], char t[])
{
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}