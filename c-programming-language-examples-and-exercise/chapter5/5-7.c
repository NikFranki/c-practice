#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

#ifndef _ALLOC_C_
#define _ALLOC_C_
char *alloc(int n);
#endif

/* sort input lines */
int main()
{
  int nlines; /* number of input lines read */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    printf("sum of lines: %d\n", nlines);
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }

  return 0;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
  {
    allocp += n;
    return allocp - n;
  }
  else
  {
    return 0;
  }
}

#define MAXLEN 1000 /* max length of any input line */
char *alloc(int);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines = 0;
  char *p, line[MAXLEN];
  while (gets(line))
    len = strlen(line);
    if (nlines >= maxlines || !(p = alloc(len + 1)))
      return -1;
    else
    {
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
  {
    printf("%s\n", *lineptr++);
  }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);
  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}