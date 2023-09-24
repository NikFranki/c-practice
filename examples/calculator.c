#include <stdio.h>

int main()
{
  char operator;
  double num1, num2, result;

  printf("欢迎使用命令行计算器!\n");

  // 输入运算符和操作数
  printf("请输入运算符 (+, -, *, /)：");
  scanf(" %c", &operator);

  printf("请输入第一个操作数：");
  scanf("%lf", &num1);

  printf("请输入第二个操作数：");
  scanf("%lf", &num2);

  // 执行计算
  switch (operator)
  {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    if (num2 != 0)
    {
      result = num1 / num2;
    }
    else
    {
      printf("除数不能为零。\n");
      return 1;
    }
    break;
  default:
    printf("无效的运算符。\n");
    return 1;
  }

  // 显示结果
  printf("计算结果：%.2lf\n", result);

  return 0;
}
