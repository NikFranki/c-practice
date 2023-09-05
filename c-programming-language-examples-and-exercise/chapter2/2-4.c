/*
 * Exercise 2-4
 * Write an alternative version of squeeze(s1,s2)
 * that deletes each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 0xff

void squeeze(char s1[], char s2[]);

int main()
{
  char s1[] = "abcdefabcdefee";
  char s2[] = "aabbccl";

  squeeze(s1, s2);
  printf("new s1: %s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[])
{
  char symbol[SIZE] = {};
  int i, j;

  // 对于出现在 s2 的字符，使用 symbol 来做标记
  for (i = 0; s2[i] != '\0'; ++i)
  {
    symbol[s2[i]] = 1;
  }

  i = j = 0;

  // 使用双循环来过滤已经存在在 s2 的字符，遍历 s1 的字符，如果在 s2 中出现过，那么就跳过这个字符
  while (s1[i] != '\0')
  {
    while (symbol[s1[i]])
    {
      i++;
    }
    s1[j++] = s1[i++];
  }
  s1[j] = '\0';
}