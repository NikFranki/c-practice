#include <stdio.h>
#include <assert.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

static int isleap(int year)
{
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void monthday(int y, int d, int *pm, int *pd)
{
  int i, leap = isleap(y);

  if (d <= 0)
  {
    *pm = 0;
    *pd = 0;
    return;
  }

  for (i = 1; d > daytab[leap][i]; i++)
  {
    if (i == 12)
    {
      *pm = 0;
      *pd = 0;
      return;
    }
    d -= daytab[leap][i];
  }

  *pm = i;
  *pd = d;
}

int dayofyear(int y, int m, int d)
{
  int i, leap = isleap(y);

  if (m < 1 || m > 12 || d < 1 || d > *(*(daytab + leap) + m))
  {
    return 0;
  }

  for (i = 1; i < m; i++)
  {
    d += *(*(daytab + leap) + i);
  }

  return d;
}

int main()
{
  int m;
  int d;
  monthday(0, 367, &m, &d);
  assert(m == 0 && d == 0);
  monthday(0, 60, &m, &d);
  assert(m == 2 && d == 29);
  printf("the day is number %d\n", dayofyear(2023, 9, 9));
  return 0;
}