/**
 * @file search_text_in_file.c
 * @author your name (you@domain.com)
 * @brief 文件内容查找工具： 创建一个程序，可以在给定文件中查找指定的关键词，并显示出现的位置。
 * @version 0.1
 * @date 2023-09-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>

// 定义一个常量，用于指定搜索关键词的最大长度
#define MAX_KEYWORD_LENGTH 100

// 定义一个函数，用于在文本中查找关键词并显示位置
void findKeyword(FILE *file, const char *keyword)
{
  char line[256]; // 假设每行最多256个字符
  int line_number = 0;

  while (fgets(line, sizeof(line), file))
  {
    line_number++;

    // 使用 strstr 函数查找关键词在当前行的位置
    char *pos = strstr(line, keyword);

    if (pos != NULL)
    {
      // 如果找到关键词，显示行号和位置
      printf("在第 %d 行找到关键词 \"%s\"，位置为：%ld\n", line_number, keyword, (pos - line) + 1);
    }
  }
}

int main()
{
  char filename[100];
  char keyword[MAX_KEYWORD_LENGTH];

  // 获取文件名和关键词
  printf("请输入文件名：");
  scanf("%s", filename);

  printf("请输入要查找的关键词：");
  scanf("%s", keyword);

  // 打开文件
  FILE *file = fopen(filename, "r");

  // 检查文件是否成功打开
  if (file == NULL)
  {
    printf("无法打开文件 %s\n", filename);
    return 1;
  }

  // 调用函数查找关键词并显示位置
  findKeyword(file, keyword);

  // 关闭文件
  fclose(file);

  return 0;
}
