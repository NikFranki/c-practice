/**
 * @file 34.c
 * @author your name (you@domain.com)
 * @brief 练习函数调用。
 * @version 0.1
 * @date 2023-10-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

void hello_world()
{
  printf("Hello, world!\n");
}

void three_hellos()
{
  int counter;
  for (counter = 1; counter <= 3; counter++)
  {
    hello_world();
  }
}

int main(void)
{
  three_hellos();
}