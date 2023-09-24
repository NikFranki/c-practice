#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 迷宫地图的大小
#define ROWS 10
#define COLS 10

// 定义迷宫地图
int maze[ROWS][COLS] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

// 玩家的当前位置
int playerRow = 0;
int playerCol = 0;

// 函数声明
void displayMaze();
bool isValidMove(int newRow, int newCol);
bool isExit(int row, int col);

int main()
{
  printf("欢迎来到迷宫游戏!\n");

  while (1)
  {
    displayMaze();

    if (isExit(playerRow, playerCol))
    {
      printf("恭喜你找到了出口！游戏结束。\n");
      break;
    }

    char move;
    printf("请输入移动命令 (w/a/s/d，退出请输入q)：");
    scanf(" %c", &move);

    int newRow = playerRow;
    int newCol = playerCol;

    switch (move)
    {
    case 'w':
      newRow--;
      break;
    case 'a':
      newCol--;
      break;
    case 's':
      newRow++;
      break;
    case 'd':
      newCol++;
      break;
    case 'q':
      printf("退出游戏。\n");
      exit(0);
    default:
      printf("无效的命令，请重新输入。\n");
      continue;
    }

    if (isValidMove(newRow, newCol))
    {
      playerRow = newRow;
      playerCol = newCol;
    }
    else
    {
      printf("无法移动到该位置，请重新输入。\n");
    }
  }

  return 0;
}

// 显示迷宫地图
void displayMaze()
{
  printf("\n当前迷宫地图：\n");

  for (int row = 0; row < ROWS; row++)
  {
    for (int col = 0; col < COLS; col++)
    {
      if (row == playerRow && col == playerCol)
      {
        printf("P ");
      }
      else if (maze[row][col] == 0)
      {
        printf(". ");
      }
      else
      {
        printf("# ");
      }
    }
    printf("\n");
  }
}

// 验证移动是否有效
bool isValidMove(int newRow, int newCol)
{
  if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 0)
  {
    return true;
  }
  return false;
}

// 检查是否到达出口
bool isExit(int row, int col)
{
  return (row == ROWS - 1 && col == COLS - 1);
}
