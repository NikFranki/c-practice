#include <stdio.h>
#include <time.h>

// 函数声明
void printCalendar(int year, int month);

int main()
{
  int year, month;

  // 获取用户输入的年份和月份
  printf("请输入年份（例如：2023）：");
  scanf("%d", &year);

  printf("请输入月份（1-12）：");
  scanf("%d", &month);

  // 调用函数输出日历
  printCalendar(year, month);

  return 0;
}

// 输出指定年份和月份的日历
void printCalendar(int year, int month)
{
  struct tm firstDay = {0};       // 创建一个日期结构体并初始化为0
  firstDay.tm_year = year - 1900; // 年份要减去1900
  firstDay.tm_mon = month - 1;    // 月份要减去1
  firstDay.tm_mday = 1;           // 第一天是1号

  // 使用mktime函数将日期结构体转换为时间戳
  time_t firstDayTimestamp = mktime(&firstDay);

  // 获取第一天是星期几
  int firstDayOfWeek = localtime(&firstDayTimestamp)->tm_wday;

  // 获取该月的总天数
  int daysInMonth = 31; // 默认为31天
  if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    daysInMonth = 30;
  }
  else if (month == 2)
  {
    // 计算闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
      daysInMonth = 29;
    }
    else
    {
      daysInMonth = 28;
    }
  }

  // 打印日历标题
  printf("日历：%d 年 %d 月\n", year, month);

  // 打印星期标题
  printf("日 一 二 三 四 五 六\n");

  // 打印空格，直到第一天
  for (int i = 0; i < firstDayOfWeek; i++)
  {
    printf("   ");
  }

  // 打印日期
  for (int day = 1; day <= daysInMonth; day++)
  {
    printf("%2d ", day);

    // 如果是周六，换行
    if ((firstDayOfWeek + day) % 7 == 0)
    {
      printf("\n");
    }
  }

  printf("\n");
}
