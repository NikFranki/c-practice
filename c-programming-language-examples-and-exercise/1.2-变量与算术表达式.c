#include <stdio.h>

/* 打印华氏温度和摄氏温度对照表 */

int main()
{
  int fachr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fachr = lower;
  while (fachr <= upper)
  {
    celsius = 5 * (fachr - 32) / 9;
    printf("%d\t%d\n", fachr, celsius);
    fachr = fachr + step;
  }

  return 0;
}