#include <stdio.h>
#include <string.h>

// 定义字符画的字母表
const char *alphabet[26] = {
    "   A   ", "  B B  ", " B   B ", " BBBBB ", " B   B ", " B   B ", "       ", "       ", "       ", "       ",
    "       ", " CCCC  ", " C   C ", " C     ", " C   C ", "  CCCC ", "       ", "       ", "       ", "       ",
    "       ", " DDD   ", " D   D ", " D   D ", " D   D ", " DDD   ", "       ", "       ", "       ", "       ",
    "       ", "  EEE  ", " E     ", " EEE   ", " E     ", "  EEE  ", "       ", "       ", "       ", "       ",
    "       ", " FFFF  ", " F     ", " FFF   ", " F     ", " F     ", "       ", "       ", "       ", "       ",
    "       ", " GGGG  ", " G     ", " G  GG ", " G   G ", "  GG  ", "       ", "       ", "       ", "       ",
    "       ", "   H  ", "  H   ", "  HHH  ", "  H   ", "  H   ", "       ", "       ", "       ", "       ",
    "       ", "  I   ", "  I   ", "  I   ", "  I   ", "  I   ", "       ", "       ", "       ", "       ",
    "       ", "   J  ", "   J  ", "   J  ", "   J  ", " J    ", "       ", "       ", "       ", "       ",
    "       ", " K   K ", " K  K  ", " KK    ", " K  K  ", " K   K ", "       ", "       ", "       ", "       ",
    "       ", " L     ", " L     ", " L     ", " L     ", " LLLL  ", "       ", "       ", "       ", "       ",
    "       ", " M   M ", " MM MM ", " M M M ", " M   M ", " M   M ", "       ", "       ", "       ", "       ",
    "       ", " N   N ", " NN  N ", " N N N ", " N  NN ", " N   N ", "       ", "       ", "       ", "       ",
    "       ", "  OOO  ", " O   O ", " O   O ", " O   O ", "  OOO  ", "       ", "       ", "       ", "       ",
    "       ", "  PPP  ", " P   P ", " P   P ", " PPP   ", " P     ", "       ", "       ", "       ", "       ",
    "       ", "  QQQ  ", " Q   Q ", " Q   Q ", " Q  Q  ", "  QQQ  ", "       ", "       ", "       ", "       ",
    "       ", "  RRR  ", " R   R ", " R   R ", " RR    ", " R  R  ", "       ", "       ", "       ", "       ",
    "       ", "  SSS  ", " S     ", "  SSS  ", "     S ", "  SSS  ", "       ", "       ", "       ", "       ",
    "       ", "   T  ", "   T  ", "   T  ", "   T  ", "   T  ", "       ", "       ", "       ", "       ",
    "       ", "  U   ", "  U   ", "  U   ", "  U   ", "  UUU ", "       ", "       ", "       ", "       ",
    "       ", " V   V ", " V   V ", " V   V ", "  V V  ", "   V   ", "       ", "       ", "       ", "       ",
    "       ", " W   W ", " W W W ", " W W W ", " W W W ", "  W W  ", "       ", "       ", "       ", "       ",
    "       ", " X   X ", "  X X  ", "   X   ", "  X X  ", " X   X ", "       ", "       ", "       ", "       ",
    "       ", " Y   Y ", "  Y Y  ", "   Y   ", "   Y   ", "   Y   ", "       ", "       ", "       ", "       ",
    "       ", "  ZZZ ", "    Z ", "   Z  ", "  Z   ", "  ZZZ ", "       ", "       ", "       ", "       "};

// 函数声明
void convertToArt(char *input);

int main()
{
  char input[100];

  // 获取用户输入的文本
  printf("请输入要转换为字符画的文本（最多100个字符）：\n");
  fgets(input, sizeof(input), stdin);

  // 调用函数将文本转换为字符画
  convertToArt(input);

  return 0;
}

// 将文本转换为字符画
void convertToArt(char *input)
{
  printf("转换结果：\n");

  // 遍历输入文本的每个字符
  for (int i = 0; i < strlen(input); i++)
  {
    char c = input[i];
    if (c >= 'A' && c <= 'Z')
    {
      // 如果是大写字母，查找对应的字符画并打印
      int index = c - 'A';
      printf("%s\n", alphabet[index]);
    }
    else if (c >= 'a' && c <= 'z')
    {
      // 如果是小写字母，转换为大写后查找对应的字符画并打印
      int index = c - 'a';
      printf("%s\n", alphabet[index]);
    }
    else if (c == ' ')
    {
      // 如果是空格，打印空行
      printf("\n");
    }
    else
    {
      // 对于其他字符，打印一个空行
      printf("\n");
    }
  }
}
