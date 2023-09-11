/**
 * @file 5-3.c
 * @author your name (you@domain.com)
 * @brief write a pointed version of function called strcat
 * @version 0.1
 * @date 2023-09-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>

void strcatt(char *s, char *t);

int main()
{

  char s[1000];
  char t[] = "hello world 123456";
  strcatt(s, t);
  printf("%s\n", s);
  return 0;
}

void strcatt(char *s, char *t)
{
  int i = strlen(s);
  char c;

  while ((c = *t++) != '\0')
  {
    *(s + i++) = c;
  }
}