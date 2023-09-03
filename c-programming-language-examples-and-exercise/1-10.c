#include <stdio.h>

// 输入到输出，替换特定的符号

int main()
{
  char c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}
