/* Exercise 3-4
 * In a two's complement number representation,
 * our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to -(2^(wordsize-1)).
 * Explain why not.
 * Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 */

#include <stdio.h>
#include <string.h>

int getwordssize();
void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  char s[1000];
  int n = -256;

  itoa(n, s);
  printf("%d to string is %s\n", n, s);

  int n1 = 1 << (getwordssize() - 1);
  itoa(n1, s);
  printf("%d to string is %s\n", n, s);

  return 0;
}

int getwordssize()
{
  int i, j;

  j = i = 1;
  while (i <<= 1)
  {
    j++;
  }

  return j;
}

void itoa(int n, char s[])
{
  // 写函数一定要记得先写核心，细节后面慢慢填充

  int i = 0;
  int sign = n % 10;
  s[i++] = (sign < 0 ? -sign : sign) + '0'; // 至少执行一次

  n /= 10;
  if (n < 0)
  {
    sign = n;
    n = -n;
  }

  while (n > 0)
  {
    s[i++] = n % 10 + '0';
    n /= 10;
  }

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int i, j;
  char c;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
