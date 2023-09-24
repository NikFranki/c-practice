#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file;
  char filename[100];
  char line[1000];
  char choice;

  printf("欢迎使用简易文本编辑器!\n");

  // 提示用户输入文件名
  printf("请输入要打开或创建的文件名：");
  scanf("%s", filename);

  // 打开文件，如果文件不存在则创建
  file = fopen(filename, "a+");

  if (file == NULL)
  {
    printf("无法打开或创建文件。\n");
    return 1;
  }

  // 主循环
  while (1)
  {
    printf("\n请选择操作：\n");
    printf("1. 打开文件\n");
    printf("2. 编辑文件\n");
    printf("3. 保存文件\n");
    printf("4. 退出\n");
    printf("你的选择：");

    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
      // 打开文件
      rewind(file);
      printf("\n文件内容：\n");
      while (fgets(line, sizeof(line), file))
      {
        printf("%s", line);
      }
      break;

    case '2':
      // 编辑文件
      printf("\n请输入文本内容 (输入'.'保存并退出)：\n");
      while (1)
      {
        scanf(" %[^\n]", line);
        if (line[0] == '.')
        {
          break;
        }
        fprintf(file, "%s\n", line);
      }
      break;

    case '3':
      // 保存文件
      rewind(file);
      printf("\n文件已保存。\n");
      break;

    case '4':
      // 退出
      printf("\n再见!\n");
      fclose(file);
      exit(0);

    default:
      printf("\n无效的选择。\n");
      break;
    }
  }

  return 0;
}
