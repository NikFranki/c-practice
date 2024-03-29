/**
 * @file 21.c
 * @author your name (you@domain.com)
 * @brief 猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
 * @version 0.1
 * @date 2023-09-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int day, x1 = 0, x2;
  day = 9;
  x2 = 1;
  while (day > 0)
  {
    x1 = (x2 + 1) * 2;
    x2 = x1;
    day--;
  }
  printf("总数为 %d\n", x1);

  return 0;
}