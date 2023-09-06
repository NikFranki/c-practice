/*
 * Exercise 3-1
 * Write a binary search
 */

#include <stdio.h>

int binarySearch(int v[], int n, int value);

int main()
{
  int nums[] = {1, 2, 4, 5, 8};

  int index = binarySearch(nums, 5, 2);
  printf("found it: %d\n", index);

  return 0;
}

int binarySearch(int v[], int n, int value)
{
  int low = 0;
  int high = n - 1;
  int mid;

  while (low <= high)
  {
    int middle = (high + low) / 2;

    if (v[middle] < value)
    {
      low = middle + 1;
    }
    else if (v[middle] > value)
    {
      high = middle + 1;
    }
    else
    {
      return middle;
    }
  }

  return -1;
}