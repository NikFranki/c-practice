#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体定义：表示图书信息
struct Book
{
  int id;
  char title[100];
  char author[100];
  struct Book *next;
};

// 全局变量：链表头指针
struct Book *head = NULL;

// 函数声明
void addBook();
void viewBooks();
void deleteBook();

int main()
{
  char choice;

  printf("欢迎使用小型图书管理系统!\n");

  while (1)
  {
    printf("\n请选择操作：\n");
    printf("1. 添加图书\n");
    printf("2. 查看图书\n");
    printf("3. 删除图书\n");
    printf("4. 退出\n");
    printf("你的选择：");

    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
      // 添加图书
      addBook();
      break;

    case '2':
      // 查看图书
      viewBooks();
      break;

    case '3':
      // 删除图书
      deleteBook();
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

// 添加图书
void addBook()
{
  struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
  if (newBook == NULL)
  {
    printf("\n内存分配失败。\n");
    return;
  }

  printf("\n请输入图书信息：\n");
  printf("图书编号：");
  scanf("%d", &newBook->id);
  printf("图书标题：");
  scanf(" %[^\n]", newBook->title);
  printf("作者：");
  scanf(" %[^\n]", newBook->author);

  newBook->next = head;
  head = newBook;

  printf("\n图书已添加。\n");
}

// 查看图书
void viewBooks()
{
  struct Book *current = head;

  if (current == NULL)
  {
    printf("\n图书库为空。\n");
    return;
  }

  printf("\n图书列表：\n");
  while (current != NULL)
  {
    printf("编号：%d\n", current->id);
    printf("标题：%s\n", current->title);
    printf("作者：%s\n", current->author);
    printf("\n");
    current = current->next;
  }
}

// 删除图书
void deleteBook()
{
  int id;
  struct Book *current = head;
  struct Book *prev = NULL;

  printf("\n请输入要删除的图书编号：");
  scanf("%d", &id);

  while (current != NULL && current->id != id)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    printf("\n未找到指定编号的图书。\n");
    return;
  }

  if (prev == NULL)
  {
    head = current->next;
  }
  else
  {
    prev->next = current->next;
  }

  free(current);
  printf("\n图书已删除。\n");
}
