/**
 * @file 15.c
 * @author your name (you@domain.com)
 * @brief 利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()
{
  int score;
  char grade;

  printf("please input a score\n");
  scanf("%d", &score);

  grade = score >= 90 ? 'A' : (score >= 60 ? 'B' : 'C');
  printf("your grade is %c\n", grade);

  return 0;
}