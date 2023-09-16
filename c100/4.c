/**
 * @file 4.c
 * @author your name (you@domain.com)
 * @brief 输入某年某月某日，判断这一天是这一年的第几天？
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  int year, month, day, sum, leap;
  printf("\nplease input year month day like (2023,09,16)\n");
  scanf("%d,%d,%d", &year, &month, &day);
  switch (month)
  {
  case 1:
    sum = 0;
    break;
  case 2:
    sum = 31;
    break;
  case 3:
    sum = 59;
    break;
  case 4:
    sum = 90;
    break;
  case 5:
    sum = 120;
    break;
  case 6:
    sum = 151;
    break;
  case 7:
    sum = 181;
    break;
  case 8:
    sum = 212;
    break;
  case 9:
    sum = 243;
    break;
  case 10:
    sum = 273;
    break;
  case 11:
    sum = 304;
    break;
  case 12:
    sum = 334;
    break;

  default:
    printf("date error");
    break;
  }

  sum += day;

  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
  {
    leap = 1;
  }
  else
  {
    leap = 0;
  }
  if (leap == 1 && month > 2)
  {
    sum++;
  }
  printf("the %d day of this year\n", sum);

  return 0;
}