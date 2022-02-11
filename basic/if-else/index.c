#include <stdio.h>

int main() {
  int s;
  printf("please input your score: \n");
  scanf("%d", &s);
  if (s >= 90) {
    printf("you get a A\n");
  } else if (s >= 80 && s < 90) {
    printf("you get a B\n");
  } else if (s >= 70 && s < 80) {
    printf("you get a C\n");
  } else if (s >= 60 && s < 70) {
    printf("you get a D\n");
  } else {
    printf("you get a E\n");
  }
  return 0;
}