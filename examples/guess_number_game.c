#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int numberToGuess, userGuess, attempts = 0;
  srand(time(NULL)); // 用当前时间初始化随机数生成器

  // 生成一个1到100之间的随机数
  numberToGuess = rand() % 100 + 1;

  printf("欢迎来到猜数字游戏！\n");
  printf("我已经选好了一个1到100之间的数字。你可以开始猜了。\n");

  do
  {
    printf("请输入你的猜测：");
    scanf("%d", &userGuess);
    attempts++;

    if (userGuess < numberToGuess)
    {
      printf("太低了！再试一次。\n");
    }
    else if (userGuess > numberToGuess)
    {
      printf("太高了！再试一次。\n");
    }
    else
    {
      printf("恭喜你，猜对了！答案是 %d。\n", numberToGuess);
      printf("你用了 %d 次猜中了。\n", attempts);
    }
  } while (userGuess != numberToGuess);

  return 0;
}
