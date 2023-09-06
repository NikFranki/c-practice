/* Exercise 3-2
 * Write a function escape(s,t) that
 * converts characters like newline and tab into visible escape sequences like \n and \t
 * as it copies the string t to s. Use a switch.
 * Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 */

#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
  char s[] = "abc\tdef\nghi";
  char t[1000];

  escape(s, t);
  printf("%s\n", t);

  return 0;
}

void escape(char s[], char t[])
{
  int i, j;
  char c;

  j = i = 0;
  while ((c = s[i]) != '\0')
  {
    switch (c)
    {
    case '\n':
      t[j++] = '\\';
      t[j] = 'n';
      break;

    case '\t':
      t[j++] = '\\';
      t[j] = 't';
      break;

    default:
      t[j] = s[i];
      break;
    }
    i++;
    j++;
  }
}