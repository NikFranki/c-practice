/*
 * Exercise 2-1
 * Write a program show signed | unsigned to support int | char type
 */

#include <stdio.h>
#include <limits.h>

int main()
{
  printf("Unsigned char max: %d\n", UCHAR_MAX);
  printf("Signed char max: %d\n", SCHAR_MAX);
  printf("Signed char min: %d\n", SCHAR_MIN);

  unsigned int i = ~0;
  printf("Unsigned int max: %d\n", i);
  printf("Signed int max: %d\n", i / 2);
  printf("Signed int max: %d\n", -(i / 2) - 1);

  return 0;
}