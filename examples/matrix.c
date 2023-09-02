#include <stdio.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
  register int *m1p;
  register int *m2p;
  register int k;
  int row;
  int column;

  for (row = 0; row < x; row += 1)
  {
    for (column = 0; column < z; column += 1)
    {
      m1p = m1 + row * y;
      m2p = m2 + column;
      *r = 0;

      for (k = 0; k < y; k += 1)
      {
        *r += *m1p * *m2p;
        m1p += 1;
        m2p += z;
      }

      r++;
    }
  }
}

int main()
{
  return 0;
}