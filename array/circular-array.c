#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, j;
  int A[100], temp;
  // m 数组的长度 n 循环次数
  int m, n;
  printf("请输入数组的长度和循环次数\n");
  scanf("%d %d", &m, &n);

  printf("请输入数组元素\n");
  for (i=0; i<m; i++)
  {
    scanf("%d", &A[i]);
  }

  // 开始循环
  for (i=0; i<n%m; i++)
  {
    // 先把数组里面最后的元素记录下来
    temp = A[m-1];
    // 开始移动
    for (j=m-1; j>0; j--)
    {
      A[j] = A[j-1];
    }
    // 数组的第一个元素用最后一个元素填充
    A[0] = temp;
  }

  // 打印
  printf("数组顺序为: \n");
  for (i=0; i<m; i++)
  {
    printf("%d ", A[i]);
    putchar('\n');
  }

  return 0;
}