#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
void encrypt(char *text, int key);
void decrypt(char *text, int key);

int main()
{
  char text[1000];
  int key;
  char choice;

  printf("欢迎使用短文本加密工具!\n");

  while (1)
  {
    printf("\n请选择操作：\n");
    printf("1. 加密文本\n");
    printf("2. 解密文本\n");
    printf("3. 退出\n");
    printf("你的选择：");

    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
      // 加密文本
      printf("\n请输入要加密的文本：\n");
      scanf(" %[^\n]", text);
      printf("请输入加密密钥（0-25）：\n");
      scanf("%d", &key);
      encrypt(text, key);
      printf("\n加密后的文本：%s\n", text);
      break;

    case '2':
      // 解密文本
      printf("\n请输入要解密的文本：\n");
      scanf(" %[^\n]", text);
      printf("请输入解密密钥（0-25）：\n");
      scanf("%d", &key);
      decrypt(text, key);
      printf("\n解密后的文本：%s\n", text);
      break;

    case '3':
      // 退出
      printf("\n再见!\n");
      exit(0);

    default:
      printf("\n无效的选择。\n");
      break;
    }
  }

  return 0;
}

// 加密文本
void encrypt(char *text, int key)
{
  for (int i = 0; text[i] != '\0'; i++)
  {
    char c = text[i];

    if (c >= 'A' && c <= 'Z')
    {
      // 大写字母
      c = (c - 'A' + key) % 26 + 'A';
      text[i] = c;
    }
    else if (c >= 'a' && c <= 'z')
    {
      // 小写字母
      c = (c - 'a' + key) % 26 + 'a';
      text[i] = c;
    }
  }
}

// 解密文本
void decrypt(char *text, int key)
{
  // 解密与加密相同
  encrypt(text, 26 - key);
}
