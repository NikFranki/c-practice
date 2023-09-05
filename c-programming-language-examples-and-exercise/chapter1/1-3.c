#include <stdio.h>

/* 打印华氏温度和摄氏温度对照表 使之能够转换表顶部打印一个标题 */

float fachr2celsius(float degree)
{
  return 5.0 * (degree - 32.0) / 9.0;
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
    printf("%3.0f %6.1f\n", i, fachr2celsius(i));
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

  // lower = 0;   // lower limit of temperature scale
  // upper = 300; // upper limit
  // step = 20;   // step size

  // printf("fachr celsius\n");
  // fachr = lower;
  // while (fachr <= upper)
  // {
  //   celsius = (5.0 / 9.0) * (fachr - 32.0);
  //   printf("%3.0f %6.1f\n", fachr, celsius);
  //   fachr = fachr + step;
  // }

  printFachrList(0.0, 300.0, 20.0, 1);

  return 0;
}