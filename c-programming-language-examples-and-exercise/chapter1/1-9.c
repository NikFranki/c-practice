#include <stdio.h>

// write a program to copy its input to its output
// replace each string of one or more blanks by a single blank

int main()
{
  char prev;
  char c;

  while ((c = getchar()) != EOF)
  {
    if (c != ' ' || prev != ' ')
    {
      putchar(prev = c);
    }
  }

  // use pointer
  // char *s;
  // int p = 0;
  // char c;
  // char prev;

  // while ((c = getchar()) != EOF)
  // {
  //   if (c != ' ' || prev != ' ')
  //   {
  //     *(s + p++) = prev = c;
  //   }
  // }

  // printf("\n%s", s);

  return 0;
}