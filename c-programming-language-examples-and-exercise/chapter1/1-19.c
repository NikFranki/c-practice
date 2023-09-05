/*
 * Exercise 1-19
 * Write a program to reverse a string
 */

#include <stdio.h>

#define MAXLINE 1000

int32_t getlinestring(char line[], int maxleng);
void reversestring(char line[]);

int main()
{

  char line[MAXLINE];
  int len;

  while ((len = getlinestring(line, MAXLINE)) > 0)
  {
    reversestring(line);
    printf("%s", line);
  }

  return 0;
}

// read a line into s, return length
int getlinestring(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
  {
    s[i] = c;
    if (c == '\n')
    {
      break;
    }
  }
  s[i] = '\0';

  return i;
}

void reversestring(char s[])
{
  int len;
  // 先计算字符串的长度
  for (len = 0; s[len] != '\0'; len++)
    ;

  // 判断字符串的最后一个是否是换行，如果是的话，就字符串长度-1
  if (len > 0 && s[len - 1] == '\n')
  {
    len--;
  }

  // reverse(i, j)
  int i, j;
  char temp;
  for (i = 0; i < len / 2; i++)
  {
    j = len - 1 - i;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}