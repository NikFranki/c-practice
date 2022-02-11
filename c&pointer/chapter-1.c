#include<stdio.h>

int main(void)
{
  char ch;
  char str[1024];
  char strArr[2];
  int row = 0;

  // 读取文本输入，存储到数组中，并把最多字符的行打印出来
  do
  {
    printf("是否要输入(Y/N): \n");
    scanf("%c", &ch);
    if (ch == 'Y')
    {
      printf("请输入当前行: \n");
      scanf("%s", str);
      strArr[row++] = str;
    }
  } while(ch != 'N');

  printf("str: %s\n", str);

  return 0;
}