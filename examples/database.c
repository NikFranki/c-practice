#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义数据库文件名
#define DATABASE_FILE "database.txt"

// 结构体定义：表示数据记录
struct Record
{
  char name[100];
  int age;
  char city[100];
};

// 函数声明
void addRecord();
void viewRecords();
void searchRecords();

int main()
{
  char choice;

  printf("欢迎使用简单文件数据库!\n");

  while (1)
  {
    printf("\n请选择操作：\n");
    printf("1. 添加记录\n");
    printf("2. 查看所有记录\n");
    printf("3. 检索记录\n");
    printf("4. 退出\n");
    printf("你的选择：");

    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
      // 添加记录
      addRecord();
      break;

    case '2':
      // 查看所有记录
      viewRecords();
      break;

    case '3':
      // 检索记录
      searchRecords();
      break;

    case '4':
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

// 添加记录
void addRecord()
{
  struct Record newRecord;

  printf("\n请输入记录信息：\n");
  printf("姓名：");
  scanf(" %[^\n]", newRecord.name);
  printf("年龄：");
  scanf("%d", &newRecord.age);
  printf("城市：");
  scanf(" %[^\n]", newRecord.city);

  // 打开数据库文件以追加方式写入
  FILE *file = fopen(DATABASE_FILE, "a");
  if (file == NULL)
  {
    printf("\n无法打开数据库文件。\n");
    return;
  }

  // 将记录写入文件
  fprintf(file, "%s,%d,%s\n", newRecord.name, newRecord.age, newRecord.city);

  fclose(file);

  printf("\n记录已添加。\n");
}

// 查看所有记录
void viewRecords()
{
  FILE *file = fopen(DATABASE_FILE, "r");
  if (file == NULL)
  {
    printf("\n无法打开数据库文件。\n");
    return;
  }

  printf("\n所有记录：\n");

  char line[256];
  while (fgets(line, sizeof(line), file))
  {
    printf("%s", line);
  }

  fclose(file);
}

// 检索记录
void searchRecords()
{
  char searchField[100];
  char searchTerm[100];

  printf("\n请输入要检索的字段（例如：姓名、年龄、城市）：");
  scanf(" %[^\n]", searchField);
  printf("请输入要检索的值：");
  scanf(" %[^\n]", searchTerm);

  FILE *file = fopen(DATABASE_FILE, "r");
  if (file == NULL)
  {
    printf("\n无法打开数据库文件。\n");
    return;
  }

  printf("\n检索结果：\n");

  char line[256];
  while (fgets(line, sizeof(line), file))
  {
    char *field = strtok(line, ",");
    if (strcmp(searchField, "姓名") == 0 && strcmp(field, searchTerm) == 0)
    {
      printf("%s", line);
    }
    else if (strcmp(searchField, "年龄") == 0)
    {
      int age = atoi(field);
      int searchAge = atoi(searchTerm);
      if (age == searchAge)
      {
        printf("%s", line);
      }
    }
    else if (strcmp(searchField, "城市") == 0 && strcmp(field, searchTerm) == 0)
    {
      printf("%s", line);
    }
  }

  fclose(file);
}
