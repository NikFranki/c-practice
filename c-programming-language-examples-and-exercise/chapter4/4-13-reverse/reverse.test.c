#include <assert.h>
#include <string.h>
#include <stdio.h>

// #include "./reverse.h"

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


int main(int argc, char *argv[])
{
  char s1[4] = {'a', 'b', 'c', '\0'};

  reverse(s1);
  assert(!strcmp("ca", s1));

  // char s2[1] = {'\0'};
  // reverse(s2);
  // assert(!strcmp("", s2));

  return 0;
}