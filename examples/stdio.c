#include <stdio.h>
#include <stdlib.h>

// 处理输入，打印行号和输出字符
int main()
{
  // int ch;
  // int line;
  // int at_beginning;

  // line = 0;
  // at_beginning = 1;

  // 逐个读取字符并处理
  // while ((ch = getchar()) != EOF)
  // {
  //   if (at_beginning == 1)
  //   {
  //     at_beginning = 0;
  //     line += 1;
  //     printf("%d ", line);
  //   }

  //   putchar(ch);
  //   if (ch == '\n')
  //   {
  //     at_beginning = 1;
  //   }
  // }

  int ch;
  int line;
  int at_beginning;

  line = 0;
  at_beginning = 1;

  while ((ch = getchar()) != EOF)
  {
    if (at_beginning == 1) {
      at_beginning = 0;
      line += 1;
      printf("%d ", line);
    }

    putchar(ch);
    if (ch == '\n') {
      at_beginning = 1;
    }
  }


  return EXIT_SUCCESS;
}