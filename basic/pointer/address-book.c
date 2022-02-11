#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct AddressBook
{
  char name[40];
  char telnum[30];
  struct AddressBook *next;
};
‰
void getInput(struct AddressBook *addressBook);
void addAddressBook(struct AddressBook **addressBookLibrary);
void printAddressBookLibray(struct AddressBook *addressBookLibrary);
struct AddressBook *searchAddressBook(struct AddressBook *addressBookLibrary, char *target);
void printAddressBook(struct AddressBook *addressBook);

void getInput(struct AddressBook *addressBook)
{
  printf("请输入姓名: , 电话号码: \n");
  scanf("%s %s", addressBook->name, addressBook->telnum);
}

void addAddressBook(struct AddressBook **addressBookLibrary)
{
  struct AddressBook *addressBook;
  static struct AddressBook *tail = NULL;
  addressBook = (struct AddressBook *)malloc(sizeof(struct AddressBook));

  if (addressBook == NULL)
  {
    printf("分配内存失败\n");
    exit(-1);
  }

  getInput(addressBook);

  if (*addressBookLibrary != NULL)
  {
    tail->next = addressBook;
    addressBook->next = NULL;
  }
  else
  {
    *addressBookLibrary = addressBook;
    addressBook->next = NULL;
  }
  tail = addressBook;
}

void printAddressBookLibray(struct AddressBook *addressBookLibrary)
{
  struct AddressBook *addressBook;
  int count = 1;

  addressBook = addressBookLibrary;
  while (addressBook != NULL)
  {
    printf("AddressBook: %d, 姓名: %s, 电话号码: %s\n", count, addressBook->name, addressBook->telnum);
    count++;
    addressBook = addressBook->next;
  }
}

struct AddressBook *searchAddressBook(struct AddressBook *addressBookLibrary, char *target)
{
  struct AddressBook *addressBook;

  addressBook = addressBookLibrary;
  while (addressBook != NULL)
  {
    if (!strcmp(addressBook->name, target) || !strcmp(addressBook->telnum, target))
    {
      break;
    }
    addressBook = addressBook->next;
  }

  return addressBook;
}

void printAddressBook(struct AddressBook *addressBook)
{
  printf("姓名： %s, 电话号码：%s\n", addressBook->name, addressBook->telnum);
}

int main(void)
{
  char ch;
  struct AddressBook *addressBookLibrary = NULL;
  struct AddressBook *addressBook;
  char input[128];

  while (1)
  {
    printf("是否开始录入通讯录(Y/N)\n");
    do
    {
      ch = getchar();
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'Y')
    {
      printf("开始录入吧\n");
      addAddressBook(&addressBookLibrary);
    }
    else
    {
      break;
    }
  }

  printf("是否打印通讯录(Y/N)\n");

  while (1)
  {
    do
    {
      ch = getchar();
    } while (ch != 'Y' && ch != 'N');

    if (ch == 'Y')
    {
      printf("开始打印吧\n");
      printAddressBookLibray(addressBookLibrary);
    }

    printf("输入姓名或电话号码\n");
    scanf("%s", input);
    addressBook = searchAddressBook(addressBookLibrary, input);
    if (addressBook == NULL)
    {
      printf("很抱歉，没有找到!\n");
    }
    else
    {
      do
      {
        printf("已经找到符合条件的联系人!\n");
        printAddressBook(addressBook);
        break;
      } while (searchAddressBook(addressBookLibrary, input) != NULL);
    }

    break;
  }

  return 0;
}