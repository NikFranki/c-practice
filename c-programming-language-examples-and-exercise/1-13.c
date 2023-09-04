/*
 * Exercise 1-13.
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>
#include <ctype.h>

void updatecounts();
int getpeak();
void painth();
void paintv();

int main()
{
  int len = 10;
  int counts[len];
  int i;
  for (i = 0; i < len; counts[i++] = 0)
    ;

  int isIn = 0;
  int wordlen = 0;
  char c;

  while ((c = getchar()) != EOF)
  {
    if (isIn)
    {
      if (isspace(c)) // 这里是空格，就开始更新当前单词的数目，并为开始下一个单词的统计做准备
      {
        updatecounts(counts, len, wordlen);
        isIn = 0;
        wordlen = 0;
      }
      else // 一直没有空格，一直统计字数
      {
        wordlen++;
      }
    }
    else
    { // 当不是空格的开始统计单词数目
      if (!isspace(c))
      {
        isIn = 1;
        wordlen = 1;
      }
    }
  }

  if (wordlen > 0)
  {
    updatecounts(counts, len, wordlen);
  }

  painth(counts, len);

  paintv(counts, len);

  return 0;
}

void updatecounts(int counts[], int len, int wordlen)
{
  wordlen = wordlen < len ? wordlen : len;
  counts[wordlen - 1]++;
}

/**
 * @brief 获取数组里面最大的数目
 * 
 * @param counts 
 * @param len 
 * @return int 
 */
int getpeak(int counts[], int len)
{
  int peak = 0;
  int i;
  for (i = 0; i < len; i++)
  {
    peak = peak > counts[i] ? peak : counts[i];
  }
  return peak;
}

void painth(int counts[], int len)
{
  printf("\nHorizontal histogram: \n\n");
  int peak = getpeak(counts, len);

  int i;
  for (i = 0; i < 10; i++)
  {
    int barlen = counts[i] * 20 / peak + 1;
    char bar[barlen];
    int j;
    for (j = 0; j < barlen - 1; j++)
    {
      bar[j] = '+';
    }
    bar[j] = '\0';

    char *format = "  %2d: %s %d\n";
    if (i == len - 1)
    {
      format = "  >=%2d: %s %d\n";
    }
    printf(format, i + 1, bar, counts[i]);
  }
}

void paintv(int counts[], int len)
{
  printf("\nVertical histogram: \n\n");
  int peak = getpeak(counts, len);
  int i, j, h = 20;

  int bars[len];
  for (i = 0; i < len; i++)
  {
    bars[i] = counts[i] * h / peak;
  }

  // 绘制横坐标上面的对应的指标
  for (i = 0; i <= h; i++)
  {
    for (j = 0; j < len; j++)
    {
      if (h - i == bars[j])
      {
        printf("%-5d", counts[j]);
      }
      else if (h - i < bars[j])
      {
        printf("%-5c", '+');
      }
      else
      {
        printf("%-5c", ' ');
      }
    }
    printf("\n");
  }

  for (i = 0; i < len; i++)
  {
    printf("=====");
  }
  printf("\n");

  // 绘制横坐标
  for (i = 0; i < len; i++)
  {
    char *format = "%-5d";
    if (i == len - 1)
    {
      format = ">=%-5d";
    }
    printf(format, i + 1);
  }
  printf("\n");
}
