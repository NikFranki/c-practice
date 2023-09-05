#include <stdio.h>

// 行计数

int main()
{
  int ns, nt, nl, c;

  ns = nt = nl = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ') {
      ++ns;
    }
    if (c == '\t') {
      ++nt;
    }
    if (c == '\n')
    {
      ++nl;
    }
  }

  printf("sum spaces: %1d\n", ns);
  printf("sum tabs: %1d\n", nt);
  printf("sum lines: %1d\n", nl);

  return 0;
}
