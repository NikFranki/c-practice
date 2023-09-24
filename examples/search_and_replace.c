#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 查找并替换字符串中的指定子字符串
char *findAndReplace(const char *input, const char *find, const char *replace)
{
  char *result = NULL;
  char *insertPoint = NULL;
  size_t replaceLen = strlen(replace);
  size_t findLen = strlen(find);
  size_t inputLen = strlen(input);
  size_t capacity = 0;

  // 查找并计算替换后的字符串的长度
  const char *cursor = input;
  for (size_t count = 0; (cursor = strstr(cursor, find)); ++count)
  {
    cursor += findLen;
    capacity += (cursor - input) + replaceLen;
    input = cursor;
  }

  // 为结果分配内存
  result = (char *)malloc(capacity + inputLen + 1);
  if (!result)
  {
    return NULL;
  }

  // 复制和替换文本
  cursor = input;
  insertPoint = result;
  while (1)
  {
    const char *next = strstr(cursor, find);
    if (next)
    {
      size_t len = next - cursor;
      memcpy(insertPoint, cursor, len);
      insertPoint += len;
      memcpy(insertPoint, replace, replaceLen);
      insertPoint += replaceLen;
      cursor = next + findLen;
    }
    else
    {
      strcpy(insertPoint, cursor);
      break;
    }
  }

  return result;
}

int main()
{
  char input[1000];
  char find[100];
  char replace[100];

  printf("欢迎使用文本处理工具!\n");

  printf("请输入文本：\n");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0'; // 移除换行符

  printf("请输入要查找的字符串：");
  fgets(find, sizeof(find), stdin);
  find[strcspn(find, "\n")] = '\0'; // 移除换行符

  printf("请输入要替换成的字符串：");
  fgets(replace, sizeof(replace), stdin);
  replace[strcspn(replace, "\n")] = '\0'; // 移除换行符

  char *result = findAndReplace(input, find, replace);

  if (result)
  {
    printf("处理后的文本：\n%s\n", result);
    free(result); // 释放内存
  }
  else
  {
    printf("内存分配失败。\n");
  }

  return 0;
}
