#include <stdio.h>

// 单词计数（统计行数、单词数、字符数）

#define IN 1
#define OUT 0

int main()
{
  int c, nl, nw, nc, state;

  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
    {
      ++nl;
    }
    if (c == ' ' || c == '\t' || c == '\n')
    {
      state = OUT;
    }
    if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }

  printf("lines: %d\twords: %d\tcharacters: %d\n", nl, nw, nc);

  return 0;
}
