#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char filename[100];

  printf("欢迎使用命令行音乐播放器!\n");

  while (1)
  {
    printf("\n请输入音乐文件名 (输入 q 退出)：");
    scanf("%s", filename);

    if (strcmp(filename, "q") == 0)
    {
      printf("退出音乐播放器。\n");
      break;
    }

    // 使用system函数调用mpv播放音乐文件
    char command[200];
    snprintf(command, sizeof(command), "mpv \"%s\"", filename);

    int result = system(command);

    if (result != 0)
    {
      printf("播放音乐时出错。\n");
    }
  }

  return 0;
}
