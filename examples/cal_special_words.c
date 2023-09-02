#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char const whitespace[] = "\n\r\f\t\v";

void cal_words()
{
  char buffer[101];
  int count;

  count = 0;

  while (gets(buffer))
  {
    char *word;

    // 从缓冲区里面提取单词，直到缓冲区不再有单词
    for (word = strtok(buffer, whitespace); word != NULL; word = strtok(NULL, whitespace))
    {
      if (strcmp(word, "the") == 0)
      {
        count += 1;
      }
    }
  }

  printf("result is %d\n", count);
}

int main()
{
  cal_words();
  return 0;
}