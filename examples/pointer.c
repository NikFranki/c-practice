#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t strlen(char const *string)
{
  int length = 0;
  while (*string++ != '\0')
  {
    length += 1;
  }

  return length;
}

#define TRUE 1
#define FALSE 0

int find_char(char **strings, char value)
{
  char *string;

  while ((string = *strings++) != NULL)
  {
    while (*string++ == value)
    {
      return TRUE;
    }
  }
  return FALSE;
}

void reverse_string(char *str)
{
  char *last_char;

  // 将 last_char 设置为指向字符串的最后一个字符
  for (last_char = str; *last_char != '\0'; last_char++)
    ;

  last_char--;

  while (str < last_char)
  {
    char tmp;

    tmp = *str;
    *str++ = *last_char;
    *last_char-- = tmp;
  }
}

void reverse_string1(char *str)
{
  // 这里的实现跟第一个实现的方式如出一辙，只不过，这里取最后的地址是通过 strlen 函数库的形式去获取长度，第一个实现则通过 for 循环去取
  char *start = str;
  char *end = str + strlen(str) - 1;

  while (start < end)
  {
    char tmp;

    tmp = *start;
    *start++ = *end;
    *end-- = tmp;
  }
}

int main()
{
  // int a = 1;
  // *&a = 10; // 把值 25 赋值给变量a

  // int b = -1;
  // float c = 3.14;
  // int *d = &a;
  // float *e = &c;

  // printf("a: %d\n", a);
  // printf("b: %d\n", b);
  // printf("c: %f\n", c);
  // printf("d: %d\n", *d);
  // printf("d: %f\n", *e);

  // 指针的指针
  // int a = 12;
  // int *b = &a;  // 指向整形的指针
  // int **c = &b; // 指向整形的指针的指针

  // printf("str length: %zu\n", strlen("hello world"));

  char input[100];
  printf("Enter a string: ");
  scanf("%s", input);

  reverse_string1(input);

  printf("Reversed string: %s\n", input);

  return 0;
}
