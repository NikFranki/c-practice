#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);
int getlinex(char line[], int lim);

/* rudimentary calculator */
int main()
{
  double sum, atof(char[]);
  char line[MAXLINE];
  sum = 0;
  while (getlinex(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
  double val, power;
  int i, sign;
  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}

int getlinex(char line[], int lim)
{
  int i = 0;
  char c;

  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
  {
    line[i++] = c;
  }
  if (c == '\n')
  {
    line[i++] = c;
  }
  line[i] = '\0';

  return i;
}