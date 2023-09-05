/*
 * Exercise 2-10
 * Write a function lower
 */

#include <stdio.h>
#include <ctype.h>

// void lower(char s[], char t[]);
char lower(char c);

int main()
{
  // char s1[] = "HELLO WORLD";
  // char s2[100];

  // lower(s1, s2);
  // printf("%s\n", s2);

  char c;
  while ((c = getchar()) != EOF)
  {
    putchar(lower(c));
  }

  return 0;
}

// void lower(char s[], char t[])
// {
//   int i = 0;
//   int j = 0;
//   char c;
//   while ((c = s[i++]) != '\0')
//   {
//     if ('A' <= c && c <= 'Z')
//     {
//       c = c - 'A' + 'a';
//     }
//     t[j++] = c;
//   }
//   t[j] = '\0';
// }

char lower(char c)
{
  return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}