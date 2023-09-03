#include <stdio.h>

// 行计数

int main()
{
  // int nl, c;

  // nl = 0;
  // while ((c = getchar()) != EOF)
  // {
  //   if (c == '\n')
  //   {
  //     ++nl;
  //   }
  // }

  int c, nl;
  for (nl = 0; (c = getchar()) != EOF;)
    if (c == '\n')
    {
      ++nl;
    }

  printf("sum lines: %1d\n", nl);

  return 0;
}
