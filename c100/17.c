/**
 * @file 17.c
 * @author your name (you@domain.com)
 * @brief 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  char c;
  int letters = 0, spaces = 0, digits = 0, others = 0;

  while ((c = getchar()) != '\n')
  {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      letters++;
    }
    else if (c >= '0' && c <= '9')
    {
      digits++;
    }
    else if (c == ' ')
    {
      spaces++;
    }
    else
    {
      others++;
    }
  }

  printf("letters=%d, spaces=%d, digits=%d, others=%d\n", letters, spaces, digits, others);

  return 0;
}