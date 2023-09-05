/*
 * Exercise 1-23
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 */

#include <stdio.h>

int main()
{
  char prevc;
  char c;
  char nextc;

  while ((c = getchar()) != EOF)
  {
    if (c == '"')
    {
      putchar(prevc = c); // point start double quotation mark
      while ((c = getchar()) != '"' || prevc != '\\')
      {
        putchar(c);
      }
      putchar(c); // point end double quotation mark
    }
    else if (c == '/') // 进入注释判断
    {
      nextc = getchar();
      if (nextc == '/') // eg: // sdfasdf
      {
        while ((c = getchar()) != '\n')
          ;
        putchar('\n');
      }
      else if (nextc == '*') // eg1: /* sdfsdfsd */ eg2: /** * sdfsdf *sdfsdf */
      {
        prevc = getchar();
        while ((c = getchar()) != '/' || prevc != '*')
        {
          prevc = c;
        }
      }
      else // 正常输出
      {;
        putchar(c)
        putchar(prevc = nextc);
      }
    }
    else // 正常输出
    {
      putchar(prevc = c);
    }
  }

  return 0;
}