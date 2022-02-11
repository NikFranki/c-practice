#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <errno.h>

// int main(void)
// {
//   int arr[3] = {1, 2, 3};

//   int *p = arr;
//   printf("sizeof(arr)=%lu\n", sizeof(arr));
//   printf("sizeof(p)=%lu\n", sizeof(p));

//   return 0;
// }

// void change(int a)
// {
//   a++;
// }

// int main()
// {
//   int age = 13;
//   change(age);

//   printf("age = %d", age);

//   return 0;
// }

// void change(int *pa)
// {
//   (*pa)++;
// }

// int main(void)
// {
//   int age = 12;
//   change(&age);

//   printf("age = %d\n", age);

//   return 0;
// }

// void swap_bad(int a, int b);
// void swap_ok(int *pa, int *pb);

// int main()
// {
//   int a = 5;
//   int b = 3;
//   printf("old a: %d, old b: %d\n", a, b);
//   swap_bad(a, b);
//   printf("new a: %d, new b: %d\n", a, b);
//   swap_ok(&a, &b);
//   printf("new a: %d, new b: %d\n", a, b);
// }

// void swap_bad(int a, int b)
// {
//   int t;
//   t = a;
//   a = b;
//   b = t;
// }

// void swap_ok(int *pa, int *pb)
// {
//   int t;
//   t = *pa;
//   *pa = *pb;
//   *pb = t;
// }

// typedef struct
// {
//   char name[31];\
//   int age;
//   float score;
// }Student;

// int main()
// {
//   Student stu = {"franki", 25, 99};
//   show(&stu);
//   return 0;
// }

// void show(const Student *ps)
// {
//   printf("name: %s, age: %d, score: %.2f", ps->name, ps->age, ps->score);
// }

// int main()
// {
//   int array[2][3] = {{0, 1, 2}, {3, 4, 5}};
//   int (*p)[3] = array;

//   printf("**(p+1): %d\n", **(p+1));
//   printf("**(array+1): %d\n", **(array+1));
//   printf("array[1][0]: %d\n", array[1][0]);
//   printf("*(*(p+1)+2): %d\n", *(*(p+1)+2));
//   printf("*(*(array+1)+2): %d\n", *(*(array+1)+2));
//   printf("array[1][2]: %d\n", array[1][2]);

//   return 0;
// }

// int main()
// {
//   int num = 520;
//   int *p = &num;
//   int **pp = &p;

//   printf("num: %d\n", num);
//   printf("p: %d\n", *p);
//   printf("**p: %d\n", **pp);
//   printf("&p: %p, pp: %p\n", &p, pp);
//   printf("&num: %p, p: %p, *pp: %p\n", &num, p, *pp);

//   return 0;
// }

// int main()
// {
//   // 避免重复分配内存，只需一次修改
//   char *cBooks[] = {
//     "C程序设计语言",
//     "C专家编程",
//     "C和指针",
//     "C陷阱和缺陷",
//     "C prime plus",
//     "带你学C带你飞",
//   };
//   char **byFishc;
//   char **loves[5];

//   byFishc = &cBooks[5];
//   loves[0] = &cBooks[0];
//   loves[1] = &cBooks[1];
//   loves[2] = &cBooks[2];
//   loves[3] = &cBooks[3];
//   loves[4] = &cBooks[4];

//   printf("by fishc: %s\n", *byFishc);

//   for (int i=0; i<5; i++) {
//     printf("%s\n", *loves[i]);
//   }

//   return 0;
// }

// int main()
// {
//   int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int *p = array;

//   for (int i=0; i<10; i++) {
//     printf("%d\n", *(p+i));
//   }

//   return 0;
// }

// int main()
// {
//   int array[3][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12},
//   };

//   for (int i=0; i<3; i++) {
//     for (int j=0; j<4; j++) {
//       printf("%d ", *(*(array+i)+j));
//     }
//     printf("\n");
//   }

//   return 0;
// }

// int main()
// {
//   int array[3][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
//   };
//   int (*p)[4] = array;

//   for (int i=0; i<3; i++) {
//     for (int j=0; j<4; j++) {
//       printf("%2d ", *(*(p+i)+j));
//     }
//     printf("\n");
//   }

//   return 0;
// }

// 数组指针
// int main()
// {
//   int array[][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
//   };
//   int (*p)[3][4] = &array;

//   for (int i=0; i<3; i++) {
//     for (int j=0; j<4; j++) {
//       printf("%2d ", *(*(*p+i)+j));
//     }
//     printf("\n");
//   }

//   return 0;
// }

// 常量和指针
// int main()
// {
//   int num = 520;
//   const int cnum = 880;
//   const int * const p = &num;
//   const int * const *pp = &p;

//   printf("pp: %p, &p: %p\n", pp, &p);
//   printf("*pp: %p, p: %p, &num: %p\n", *pp, p, &num);
//   printf("**pp: %d, *p: %d, num: %d\n", **pp, *p, num);

//   return 0;
// }

// 函数
// int sum(int);
// int sum(int n)
// {
//   int result=0, i=0;

//   while (i++ < n) {
//     result += i;
//   }

//   return result;
// }

// int max(int, int);
// int max(int x, int y)
// {
//   return x > y ? x : y;
// }

// int main()
// {
//   int n;
//   printf("请输入一个数: \n");
//   scanf("%d", &n);
//   printf("累加的结果是: %d\n", sum(n));

//   int x, y;
//   printf("请输入两个数x, y\n");
//   scanf("%d%d", &x, &y);
//   printf("它们中较大的值是: %d\n", max(x, y));

//   return 0;
// }

// 形参和实参
// void swap(int *x, int *y);

// void swap(int *x, int *y)
// {
//   int temp;

//   printf("in swap交换前: %d, %d\n", *x, *y);

//   temp = *x;
//   *x = *y;
//   *y = temp;

//   printf("in swap交换前: %d, %d\n", *x, *y);
// }

// int main()
// {
//   int x = 3, y=5;
//   printf("in main交换前: %d, %d\n", x, y);
//   swap(&x, &y);
//   printf("in main交换前: %d, %d\n", x, y);

//   return 0;
// }

// int sum(int n, ...)
// {
//   int i, sum = 0;
//   va_list vap;
  
//   va_start(vap, n);
//   for (int i=0; i<n; i++)
//   {
//     sum += va_arg(vap, int);
//   }
//   va_end(vap);

//   return sum;
// }

// // 不固定传参
// int main()
// {

//   printf("result = %d\n", sum(3, 1, 2, 3));

//   return 0;
// }

// 指针函数
// char *get_word(char);

// char *get_word(char c)
// {
//   if (c == 'A') {
//     return "Apple";
//   } else if (c == 'B') {
//     return "Balana";
//   } else if (c == 'C') {
//     return "Cat";
//   } else if (c == 'D') {
//     return "Dog";
//   }
//   return "None";
// }

// int main()
// {

//   char input;
//   printf("请输入一个字母: \n");
//   scanf("%c", &input);

//   printf("结果是: %s\n", get_word(input));

//   return 0;
// }

// char *getWord(char c);

// char *getWord(char c)
// {
//   char str1[] = 'Apple';
//   char str2[] = 'Balana';
//   char str3[] = 'Default';

//   switch (c)
//   {
//   case 'A':
//     return str1;
//   case 'B':
//     return str2;
//   default:
//     return str3; 
//   }
// }

// int main()
// {
//   char input;

//   printf("请输入一个字母: ");

//   scanf("%c", &input);

//   printf("%s\n", getWord(input));
// }

// int square(int x)
// {
//   return x * x;
// }

// int main()
// {
//   int a;

//   printf("请输入一个整数: \n");
//   scanf("%d", &a);

//   int (*fa)(int) = square;

//   printf("结果为: %d * %d = %d\n", a, a, fa(a));

//   return 0;
// }

// 函数指针
// int add(int, int);
// int sub(int, int);
// int calc(int (*fp)(int, int), int, int);

// int add(int num1, int num2)
// {
//   return num1 + num2;
// }

// int sub(int num1, int num2)
// {
//   return num1 - num2;
// }

// int calc(int (*fp)(int, int), int num1, int num2)
// {
//   return (*fp)(num1, num2);
// }

// int main()
// {
//   int x, y;
//   printf("输入两个整数: \n");
//   scanf("%d%d", &x, &y);
//   // int (*fpa)(int, int) = add;
//   // int (*fpb)(int, int) = sub;
//   // 函数作为参数传递
//   printf("两个数相加为: %d + %d = %d\n", x, y, calc(add, x, y));
//   printf("两个数相减为: %d - %d = %d\n", x, y, calc(sub, x, y));

//   return 0;
// }

// 函数指针作为返回值
// int add(int, int);
// int sub(int, int);
// int calc(int (*fa)(int, int),int, int);
// int (*select(char op))(int, int);

// int add(int num1, int num2)
// {
//   return num1 + num2;
// }

// int sub(int num1, int num2)
// {
//   return num1 - num2;
// }

// int calc(int (*fa)(int, int), int num1, int num2)
// {
//   return (*fa)(num1, num2);
// }

// int (*select(char op))(int num1, int num2)
// {
//   switch (op)
//   {
//   case '+':
//     return add;
//   default:
//     return sub;
//   }
// }

// int main()
// {
//   int num1, num2;
//   char op;
//   int (*fp)(int, int);

//   printf("请输入一个式子（如1+3）：");
//   scanf("%d%c%d", &num1, &op, &num2);

//   fp = select(op);
//   printf("%d %c %d = %d\n", num1, op, num2, calc(fp, num1, num2));

//   return 0;
// }

// 局部变量和全局变量

// 全局变量
// void a();
// void b();
// void c();

// int count;

// void a()
// {
//   count++;
// }

// void b()
// {
//   count++;
// }

// void c()
// {
//   count++;
// }
// void func();

// int a, b = 520;

// void func()
// {
//   int b = 100;

//   a = 880;
//   b = 10;
//   printf("in func: a = %d, b = %d\n", a, b);
// }

// void func();

// void func()
// {
//   extern int count;
//   count++;
// }

// int count;

// int main()
// {
  // int i = 10;

  // printf("before i = %d\n", i);

  // // 局部变量
  // for (int i=0; i<10; i++) {
  //   printf("%d\n", i);
  // }

  // printf("after i = %d\n", i);

  // a();
  // b();
  // c();
  // b();
  // printf("count: %d\n", count);

  // printf("before in main: a = %d, b = %d\n", a, b);
  // func();
  // printf("after in main: a = %d, b = %d\n", a, b);

//   func();
//   printf("count: %d\n", count);
//   return 0;
// }

// 作用域
// 代码块作用域
// int main(void)
// {
//   int i = 1;
//   {
//     int i = 10;
//     {
//       int i = 100;
//     }
//   }
//   return 0;
// }

// 文件作用域
// void func(void);

// int main(void)
// {
//   extern int count;
//   func();
//   count++;
//   printf("%d\n", count);
//   return 0;
// }

// int count;

// void func(void)
// {
//   count++;
//   printf("%d\n", count);
// }

// 原型作用域

// 函数作用域

// 链接属性（external internal）
// 跨文件访问变量

// 生存期(静态存储期 自动存储期)
// auto 自动变量 register 寄存器变量

// 递归
// 汉诺塔
// void hanoi(int n, char x, char y, char z);

// void hanoi(int n, char x, char y, char z)
// {
//   if (n == 1) {
//     printf("%c --> %c\n", x, z);
//   } else {
//     hanoi(n-1, x, z, y);
//     printf("%c --> %c\n", x, z);
//     hanoi(n-1, y, x, z);
//   }
// }

// int main(void)
// {
//   int n;

//   printf("请输入汉诺塔的层数: \n");
//   scanf("%d", &n);
//   hanoi(n, 'X', 'Y', 'Z');

//   return 0;
// }

// 快速排序
// void quick_sort(int array[], int left, int right)
// {
//   int i = left, j = right, temp;
//   int pivot = array[(left + right) / 2];

//   while (i <= j) {
//     // 从左往右找到大于或等于基准值的值
//     while (array[i] < pivot) {
//       i++;
//     }
//     // 从右往左找到小于或等于基准值的值
//     while (array[j] > pivot) {
//       j--;
//     }
//     // 如果i小于或等于j，则交换两者
//     if (i <= j) {
//       temp = array[i];
//       array[i] = array[j];
//       array[j] = temp;
//       i++;
//       j--;
//     }
//   }
//   if (left < j) {
//     quick_sort(array, left, j);
//   }
//   if (i < right) {
//     quick_sort(array, i, right);
//   }
// }

// int main(void)
// {

//   int array[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
//   int length = sizeof(array) / sizeof(array[0]);
//   quick_sort(array, 0, length-1);
//   printf("排序后的数组: ");
//   for (int i=0; i<length; i++) {
//     printf("%d ", array[i]);
//   }
//   putchar('\n');
//   return 0;
// }

// 动态分配空间
// int main(void)
// {
//   int ptr;
//   ptr = (int*) malloc(int);
//   printf("请输入一个整数: ");
//   scanf("%d", ptr);
  
//   return 0;
// }

// int main(void)
// {
//   char a = 0, b = 0;
//   int *p = (int *)&b;

//   *p = 258;

//   printf("%d %d", a, b);
//   putchar('\n');

//   return 0;
// }

// stack heap
// int main(void)
// {
//   int *ptr1 = NULL;
//   int *ptr2 = NULL;

//   // stack 地址由高到低
//   printf("stack: %p -> %p\n", &ptr1, &ptr2);

//   ptr1 = (int *)malloc(sizeof(int));
//   ptr2 = (int *)malloc(sizeof(int));

//   // heap 地址由低到高
//   printf("heap: %p -> %p\n", ptr1, ptr2);

//   return 0;
// }

// struct Book {
//   char name[128];
//   char author[46];
//   struct Book *next;
// };

// void getInput(struct Book *book);
// void addBook(struct Book **library);
// struct Book *searchBook(struct Book *library, char *target);
// void printBook(struct Book *book);
// void printLibrary(struct Book *library);
// void releaseLibrary(struct Book **library);

// void getInput(struct Book *book)
// {
//   printf("请输入书名: ");
//   scanf("%s", book->name);
//   printf("请输入作者: ");
//   scanf("%s", book->author);
// }

// void addBook(struct Book **library)
// {
//   // struct Book *book, *temp;
//   struct Book *book;
//   static struct Book *tail;
//   book = (struct Book *)malloc(sizeof(struct Book));
//   if (book == NULL) {
//     printf("内存分配失败\n");
//     exit(1);
//   }

//   getInput(book);

//   // 头插法
//   // if (*library != NULL) {
//   //   temp = *library;
//   //   *library = book;
//   //   book->next = temp;
//   // } else {
//   //   *library = book;
//   //   book->next = NULL;
//   // }
  
//   // 尾插法(效率低，遍历找到最后一个节点即是尾结点)
//   // if (*library != NULL) {
//   //   temp = *library;
//   //   while (temp->next != NULL) {
//   //     temp = temp->next;
//   //   }
//   //   temp->next = book;
//   // } else {
//   //   *library = book;
//   //   book->next = NULL;
//   // }

//   // 尾插法2 (分配一个指向尾部的指针)
//   if (*library != NULL) {
//     tail->next = book;
//     book->next = NULL;
//   } else {
//     *library = book;
//     book->next = NULL;
//   }
//   tail = book;
// }

// struct Book *searchBook(struct Book *library, char *target)
// {
//   struct Book *book;

//   book = library;
//   while (book != NULL) {
//     if (!strcmp(book->name, target) || !strcmp(book->author, target)) {
//       break;
//     }
//     book = book->next;
//   }

//   return book;
// }

// void printBook(struct Book *book)
// {
//   printf("书名： %s", book->name);
//   printf("作者： %s", book->author);
// }

// void printLibrary(struct Book *library)
// {
//   struct Book *book;
//   int count = 1;

//   book = library;
//   while (book != NULL)
//   {
//     printf("Book %d ", count);
//     printf("书名: %s ", book->name);
//     printf("作者: %s ", book->author);
//     book = book->next;
//     count++;
//     printf("\n");
//   }
// }

// void releaseLibrary(struct Book **library)
// {
//   struct Book *temp;

//   while (library != NULL)
//   {
//     temp = *library;
//     *library = (*library)->next;
//     free(temp);
//   }
// }

// // 单链表
// int main(void)
// {

//   struct Book *library = NULL;
//   struct Book *book;
//   int ch;
//   char input[128];

//   while (1)
//   {
//     printf("请问是否需要录入书籍信息(Y/N): ");
//     do
//     {
//       ch = getchar();
//     } while(ch != 'Y' && ch != 'N');
//     if (ch == 'Y')
//     {
//       addBook(&library);
//     }
//     else
//     {
//       break;
//     }
//   }

//   printf("请问是否需要打印图书信息(Y/N): ");

//   do
//   {
//     ch = getchar();
//   } while (ch != 'Y' && ch != 'N');

//   if (ch == 'Y')
//   {
//     printLibrary(library);
//   }

//   printf("请输入书名或作者\n");
//   scanf("%s", input);
//   book = searchBook(library, input);
//   if (book == NULL) {
//     printf("很抱歉，没有找到!\n");
//   } else {
//     do {
//       printf("已经找到符合条件的图书!\n");
//       printBook(book);
//     } while(searchBook(book->next, input) != NULL);
//   }
  
//   releaseLibrary(&library);

//   return 0;
// }

// struct Node {
//   int value;
//   struct Node *next;
// };

// void insertNode(struct Node **head, int value);
// void deleteNode(struct Node **head, int value);
// void printNode(struct Node *head);

// void insertNode(struct Node **head, int value)
// {
//   struct Node *previous;
//   struct Node *current;
//   struct Node *new;

//   current = *head;
//   previous = NULL;

//   while (current != NULL && current->value < value)
//   {
//     previous = current;
//     current = current->next;
//   }

//   new = (struct Node *)malloc(sizeof(struct Node));
//   if (new == NULL)
//   {
//     printf("分配内存失败");
//     exit(1);
//   }

//   new->value = value;
//   new->next = current;

//   if (previous == NULL) 
//   {
//     *head = new;
//   }
//   else
//   {
//     previous->next = new;
//   }
// }

// void deleteNode(struct Node **head, int value)
// {
//   struct Node *previous;
//   struct Node *current;

//   previous = NULL;
//   current = *head;

//   while (current != NULL && current->value != value)
//   {
//     previous = current;
//     current = current->next;
//   }

//   if (current == NULL)
//   {
//     printf("没有找到要删除的节点");
//     return;
//   }
//   else
//   {
//     if (previous == NULL)
//     {
//       *head = current->next;
//     }
//     else
//     {
//       previous->next = current->next;
//     }
//     free(current);
//   }
// }

// void printNode(struct Node *head)
// {
//   struct Node *current;
  
//   current = head;
//   while (current != NULL)
//   {
//     printf("%d ", current->value);
//     current = current->next;
//   }
// }

// int main(void)
// {
//   struct Node *head = NULL;
//   int input;

//   printf("测试插入数据\n");
//   while (1)
//   {
//     printf("请输入一个整数(输入-1表示结束):");
//     scanf("%d", &input);
//     if (input == -1) {
//       break;
//     }
//     insertNode(&head, input);
//     printNode(head);
//   }

//   printf("测试删除数据\n");
//   while (1)
//   {
//     printf("请输入一个要删除的整数(输入-1表示结束):\n");
//     scanf("%d", &input);
//     if (input == -1) {
//       break;
//     }
//     deleteNode(&head, input);
//     printNode(head);
//   }

//   return 0;
// }

// 定义别名
// typedef int integer;
// typedef int *PTRINT;
// typedef int integer, *PTRINT;

// int main(void)
// {
//   integer a;
//   int b;
//   PTRINT c, d;

//   c = &a;
//   d = c;
//   printf("a: %p\n", c);
//   printf("c: %p\n", c);
//   printf("d: %p\n", c);

//   a = 20;
//   b = a;

//   printf("a = %d\n", a);
//   printf("b = %d\n", b);
//   printf("size of a = %lu\n", sizeof(a));
//   return 0;
// }

// typedef struct Date
// {
//   int year;
//   int month;
//   int day;
// } DATE;

// int main(void)
// {
//   DATE *date;

//   date = (DATE *)malloc(sizeof(DATE));
//   if (date == NULL)
//   {
//     printf("分配失败");
//     exit(1);
//   }

//   date->year = 2021;
//   date->month = 12;
//   date->day = 27;

//   printf("%d-%d-%d\n", date->year, date->month, date->day);

//   return 0;
// }

// union Test
// {
//   int i;
//   double pi;
//   char str[6];
// };

// 共用体
// int main(void)
// {
//   union Test test;

//   test.i = 520;
//   test.pi = 3.14;
//   strcpy(test.str, "lll");

//   printf("addr of test.i: %p\n", &test.i);
//   printf("addr of test.pi: %p\n", &test.pi);
//   printf("addr of test.str: %p\n", &test.str);

//   printf("test.i: %d\n", test.i);
//   printf("test.pi: %.2f\n", test.pi);
//   printf("test.str: %s\n", test.str);

//   return 0;
// }

// 枚举
// int main(void)
// {
//   enum Week {sun, mon, tue, wed, thu, fri, sat};
//   enum Week today;
//   struct tm *p;
//   time_t t;

//   time(&t);
//   p = localtime(&t);

//   today = p->tm_wday;

//   switch(today)
//   {
//     case mon:
//     case tue:
//     case wed:
//     case thu:
//     case fri:
//       printf("工作 T_T！\n");
//       break;
//     case sat:
//     case sun:
//       printf("放假！^_^\n");
//       break;
//     default:
//       printf("Error!\n");
//   }

//   return 0;
// }

// int main(void)
// {
//   enum Color {red = 10, green, blue};
//   enum Color rgb;

//   for (rgb = red; rgb <= blue; rgb++) {
//     printf("rgb = %d\n", rgb);
//   }

//   return 0;
// }

// 位移操作
// int main(void)
// {
//   int value = 1;

//   while (value < 1024)
//   {
//     value <<= 1; // value = value << 1;
//     printf("value = %d\n", value);
//   }

//   printf("==========================================\n\n");

//   value = 1024;
//   while (value > 0)
//   {
//     value >>= 1;
//     printf("value = %d\n", value);
//   }

//   return 0;
// }


// 打开/关闭文件
// int main(void)
// {
//   FILE *fp;
//   int ch;

//   if ((fp = fopen("hello.txt", "r")) == NULL)
//   {
//     printf("打开文件失败!\n");
//     exit(EXIT_FAILURE);
//   }

//   while((ch = getc(fp)) != EOF)
//   {
//     putchar(ch);
//   }

//   fclose(fp);

//   return 0;
// }

// int main(void)
// {
//   FILE *fp;

//   if ((fp = fopen("hello.txt", "w")) == NULL)
//   {
//     printf("文件打开失败");
//     exit(EXIT_FAILURE);
//   }

//   printf("%ld\n", ftell(fp));
//   fputc('F', fp);
//   printf("%ld\n", ftell(fp));
//   fputs("ishC", fp);
//   printf("%ld\n", ftell(fp));

//   fclose(fp);

//   return 0;
// }

// #define N 4

// struct Stu
// {
//   char name[24];
//   int num;
//   float score;
// }stu[N], sb;

// int main(void)
// {
//   FILE *fp;
//   int i;

//   if ((fp = fopen("score.txt", "wb")) == NULL)
//   {
//     printf("文件打开失败");
//     exit(EXIT_FAILURE);
//   }

//   printf("请开始录入成绩（格式：姓名 学号 分数）\n");
//   for (i = 0; i < N; i++)
//   {
//     scanf("%s %d %f", stu[i].name, &stu[i].num, &stu[i].score);
//   }

//   fwrite(stu, sizeof(struct Stu), N, fp);
//   fclose(fp);

//   if ((fp = fopen("score.txt", "rb")) == NULL)
//   {
//     printf("文件打开失败");
//     exit(EXIT_FAILURE);
//   }

//   fseek(fp, sizeof(struct Stu), SEEK_SET);
//   fread(&sb, sizeof(struct Stu), 1, fp);
//   printf("%s(%d)的成绩是：%.2f\n", sb.name, sb.num, sb.score);
//   fclose(fp);

//   return 0;
// }

// int main(void)
// {
//   FILE *fp;

//   if ((fp = fopen("sds.txt", "r")) == NULL)
//   {
//     perror("文件打开失败\n");
//     printf("文件打开失败, 原因是: %s\n", strerror(errno));
//     printf("标准输出\n");
//     fputs("文件打开失败 \n", stderr);
//     exit(EXIT_FAILURE);
//   }

//   fclose(fp);

//   return 0;
// }

// #define N 2

// struct Stu
// {
//   char name[40];
//   int num;
//   float score;
// }stu[N], sb;

// int main(void)
// {
//   // 错误处理
//   FILE *fp;

//   if ((fp = fopen("dw.txt", "wb")) == NULL)
//   {
//     printf("文件打开失败，原因竟然是: < %s >\n", strerror(errno));
//     exit(EXIT_FAILURE);
//   }

//   printf("请开始录入成绩: 格式（姓名 学号 分数）\n");
//   for (int i = 0; i < N; i++)
//   {
//     scanf("%s %d %f", stu[i].name, &stu[i].num, &stu[i].score);
//   }

//   fwrite(stu, sizeof(struct Stu), N, fp);
//   fclose(fp);

//   if ((fp = fopen("dw.txt", "rb")) == NULL)
//   {
//     printf("文件打开失败");
//     exit(EXIT_FAILURE);
//   }

//   fseek(fp, sizeof(struct Stu), SEEK_SET);
//   fread(&sb, sizeof(struct Stu), 1, fp);
//   printf("姓名： %s， 学号： %d， 分数： %f\n", sb.name, sb.num, sb.score);
//   fclose(fp);

//   return 0;
// }

float average(int n_values, ...)
{
  va_list var_arg;
  int count;
  float sum = 0;

  va_start(var_arg, n_values);

  for (count = 0; count < n_values; count += 1)
  {
    sum += va_arg(var_arg, int);
  }

  va_end(var_arg);

  return sum / n_values;
}

// 可变参数
int main(void)
{
  printf("%.2f\n", average(1, 2, 3, 4, 5));
  return 0;
}