#include <stdio.h>

static void _reverse(char *s, int *idx, int *p)
{
  char c = s[(*idx)++];
  if (c != '\0')
  {
    _reverse(s, idx, p);
    s[(*p)++] = c;
  }
}

void reverse(char *s)
{
  int idx = 0;
  int p = 0;
  _reverse(s, &idx, &p);
}
