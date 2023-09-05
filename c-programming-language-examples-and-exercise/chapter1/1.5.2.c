#include <stdio.h>

// 统计输入字符数

int main()
{
  // int nc, c;

  // nc = 0;
  // while ((c = getchar()) != EOF)
  // {
  //   ++nc;
  // }

  int c, nc;
  for (nc = 0; (c = getchar()) != EOF; ++nc)
    ;

  printf("sum of characters: %1d\n", nc);

  return 0;
}
