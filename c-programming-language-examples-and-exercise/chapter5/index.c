#include <stdio.h>

// int strlens(char *s);
// void strcpyy(char *t, char *s);
int strcmpp(char *str1, char *str2);

int main()
{
  // printf("%d ", strlens("hello, world"));
  // char s[] = "hello, world";
  // char t[1000];
  // strcpyy(t, s);
  // printf("%s\n", t);

  char s[] = "hello, worl";
  char t[] = "hello, world";
  printf("%d\n", strcmpp(s, t));
  return 0;
}

// int strlens(char *s)
// {
//   int n;
//   for (n = 0; *s != '\0'; s++)
//   {
//     n++;
//   }
//   return n;
// }

// int strlens(char *s)
// {
//   char *p = s;

//   while (*p != '\0')
//   {
//     p++;
//   }

//   return p - s;
// }

// void strcpyy(char *t, char *s)
// {
//   while ((*t++ = *s++) != '\0')
//     ;
// }
// void strcpyy(char *t, char *s)
// {
//   while ((*t++ = *s++))
//     ;
// }

int strcmpp(char *str1, char *str2)
{
  for (; *str1 == *str2; str1++, str2++)
    if (*str1 == '\0')
    {
      return 0;
    }
  return *str1 - *str2;
}