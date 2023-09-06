/**
 * @file rock.c
 * @brief write a game called clip rock paper
 * @version 0.1
 * @date 2023-09-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  char computerRandomResults[] = "crp";

  // r: rock c: clip p: paper
  while ((c = getchar()) != EOF)
  {

    int rand_num = (rand() % (3 - 0)) + 0;
    char computerInput = computerRandomResults[rand_num];
    if (c == computerInput)
    {
      printf("peace!\n");
      c = getchar();
    }
    else if (c == 'p' && computerInput == 'r')
    {
      printf("you win!\n");
      c = getchar();
    }
    else if (c == 'r' && computerInput == 'c')
    {
      printf("you win!\n");
      c = getchar();
    }
    else if (c == 'c' && computerInput == 'p')
    {
      printf("you win!\n");
      c = getchar();
    }
    else
    {
      printf("you lose!\n");
      c = getchar();
    }
  }

  return 0;
}