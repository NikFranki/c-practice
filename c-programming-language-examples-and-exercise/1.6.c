#include <stdio.h>

// 统计各个数字，空白符（使用数组记录数字出现的次数）

int main()
{
  int c, nwhite, nother;
  int ndigits[10];

  nwhite = nother = 0;
  for (int i = 0; i < 10; i++)
  {
    ndigits[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c >= '0' && c <= '9')
    {
      ++ndigits[c - '0'];
    }
    else if (c == ' ' || c == '\t' || c == '\n')
    {
      ++nwhite;
    }
    else
    {
      ++nother;
    }
  }

  printf("digits =");
  for (int i = 0; i < 10; i++)
  {
    printf(" %d", ndigits[i]);
  }
  printf(", space: %d other: %d\n", nwhite, nother);

  return 0;
}
