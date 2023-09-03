#include <stdio.h>

/* 打印华氏温度和摄氏温度对照表 */

/**
 * @brief 整数版本
 *
 * @return int
 */
// int main()
// {
//   int fachr, celsius;
//   int lower, upper, step;

//   lower = 0;
//   upper = 300;
//   step = 20;

//   fachr = lower;
//   while (fachr <= upper)
//   {
//     celsius = 5 * (fachr - 32) / 9;
//     printf("%3d %6d\n", fachr, celsius);
//     fachr = fachr + step;
//   }

//   return 0;
// }

/**
 * @brief 浮点数版本
 *
 * @return int
 */
int main()
{
  float fachr, celsius;
  float lower, upper, step;

  lower = 0;   // lower limit of temperature scale
  upper = 300; // upper limit
  step = 20;   // step size

  fachr = lower;
  while (fachr <= upper)
  {
    celsius = (5.0 / 9.0) * (fachr - 32.0);
    printf("%3.0f %6.1f\n", fachr, celsius);
    fachr = fachr + step;
  }

  return 0;
}