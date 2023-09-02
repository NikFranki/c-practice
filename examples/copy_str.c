#include <stdio.h>
#include <stdlib.h>

void copy_str(char dst[], char src[], int n)
{
  int dst_index, src_index;

  src_index = 0;

  for (dst_index = 0; dst_index < n; dst_index++) {
    dst[dst_index] = src[src_index];

    if (src[src_index] != 0) {
      src_index++;
    }
  }
}

int main()
{
  char a[100];
  char b[100];

  printf("Enter the first string: ");
  scanf("%s", a);
  printf("Enter the second string: ");
  scanf("%s", b);

  copy_str(a, b, 5);
  printf("Current a: %s", a);

  return EXIT_SUCCESS;
}