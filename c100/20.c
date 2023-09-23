/**
 * @file 20.c
 * @author your name (you@domain.com)
 * @brief 一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
  float h, s;
  h = s = 100;
  h = h / 2;

  for (int i = 0; i <= 10; i++)
  {
    s = s + 2 * h;
    h = h / 2;
  }
  printf("the 10 times fall down has go %f kimemiters, the 10 times fall up top %f kimemiters\n", s, h);

  return 0;
}