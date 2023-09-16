/**
 * @file 2.c
 * @author your name (you@domain.com)
 * @brief 使用 printf() 与 %d 格式化输出整数
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int number;
  printf("input a integer: ");

  scanf("%d", &number);

  printf("your input integer is: %d\n", number);

  return 0;
}