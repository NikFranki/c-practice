/**
 * @file 32.c
 * @author your name (you@domain.com)
 * @brief 删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* deleteCharacters(char * str, char * charSet)
{
  int hash[256];
  if (NULL == charSet)
  {
    return str;
  }

  for (int i = 0; i < 256; i++)
  {
    hash[i] = 0;
  }

  for (int i = 0; i < strlen(charSet); i++)
  {
    hash[charSet[i]] = 1;
  }

  int currentIndex = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    if (!hash[str[i]])
    {
      str[currentIndex++] = str[i];
    }
  }

  str[currentIndex] = '\0';

  return str;
}

int main()
{
  char s[2] = "a";
  char s2[5] = "acda";
  printf("%s\n", deleteCharacters(s2, s));
  return 0;
}