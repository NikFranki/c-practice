#include <stdio.h>

int hermite(int n, int x)
{
  // 处理不需要递归的地方
  if (n <= 0)
  {
    return 1;
  }

  if (n == 1)
  {
    return 2 * x;
  }

  // 否则，递归进行计算结果
  return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main()
{
  printf("Use hermite, please input two number by the common space separate: ");
  int a, b;
  scanf("%d %d", &a, &b);

  int c = hermite(a, b);
  printf("result is: %d\n", c);

  return 0;
}