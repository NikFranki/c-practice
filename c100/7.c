/**
 * @file 7.c
 * @author your name (you@domain.com)
 * @brief 输出特殊图案，请在c环境中运行，看一看，Very Beautiful!
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{

  char a = 176, b = 219;
  printf("%c%c%c%c%c\n", b, a, a, a, b);
  printf("%c%c%c%c%c\n", a, b, a, b, a);
  printf("%c%c%c%c%c\n", a, a, b, a, a);
  printf("%c%c%c%c%c\n", a, b, a, b, a);
  printf("%c%c%c%c%c\n", b, a, a, a, b);

  return 0;
}