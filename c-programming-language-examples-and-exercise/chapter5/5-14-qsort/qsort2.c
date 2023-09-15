#include <string.h>
#include <stdio.h>

#include "cmp.h"
#include "swap.h"

void qsort2(char *arr[], int start, int end, int (*cmp)(void *, void *), int reverse)
{
  if (start >= end)
    return;
  swap(arr, start, (start + end) / 2);

  int i, last = start;
  for (i = start + 1; i <= end; i++)
  {
    if (reverse ? cmp(arr[start], arr[i]) < 0 : cmp(arr[start], arr[i]) > 0)
    {
      swap(arr, ++last, i);
    }
  }

  swap(arr, start, last);
  qsort2(arr, start, last - 1, cmp, reverse);
  qsort2(arr, last + 1, end, cmp, reverse);
}