
#include <stdio.h>

/* 打印摄氏温度转为华氏温度对照表 */

float fachr2celsius(float degree)
{
  return degree * 9.0 / 5.0 + 32.0;
}

void printFachrList(float start, float end, float step, int withHead)
{
  if (start <= end && step < 0 || start >= end && step > 0 || step == 0)
  {
    printf("params error!\n");
    return;
  }

  if (withHead)
  {
    printf("fachr\tcelsius\n");
  }

  float i = start;
  while (start <= end ? i <= end : i >= end)
  {
    printf("%6.1f %3.0f\n", i, fachr2celsius(i));
    i += step;
  }
}

/**
 * @brief 浮点数版本
 *
 * @return int
 */
int main()
{
  // float fachr, celsius;
  // float lower, upper, step;

  // lower = -17.8; // lower limit of temperature scale
  // upper = 148.9; // upper limit
  // step = 11.1;   // step size

  // printf("celsius fachr\n");
  // celsius = lower;
  // while (celsius <= upper)
  // {
  //   fachr = celsius / (5.0 / 9.0) + 32.0;
  //   printf("%6.1f %3.0f\n", celsius, fachr);
  //   celsius = celsius + step;
  // }

  printFachrList(-17.8, 148.9, 11.1, 1);

  return 0;
}