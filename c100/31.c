/**
 * @file 31.c
 * @author your name (you@domain.com)
 * @brief 请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>

int main()
{
  char i, j;
  printf("输入一个第一个字母: \n");
  scanf("%c", &i);
  getchar();

  switch (i)
  {
  case 'm':
    printf("monday\n");
    break;

  case 'w':
    printf("wednesday\n");
    break;

  case 'f':
    printf("friday\n");
    break;

  case 't':
    printf("请输入下一个字母\n");
    scanf("%c", &j);
    if (j == 'u')
    {
      printf("tuesday\n");
      break;
    }
    if (j == 'h')
    {
      printf("thursday\n");
      break;
    }

  case 's':
    printf("请输入下一个字母\n");
    scanf("%c", &j);
    if (j == 'a')
    {
      printf("saturday\n");
      break;
    }
    if (j == 'u')
    {
      printf("sunday\n");
      break;
    }

  default:
    printf("error\n");
    break;
  }

  return 0;
}