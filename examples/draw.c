#include <stdio.h>
#include <stdlib.h>

// 定义绘图区域大小
#define WIDTH 40
#define HEIGHT 20

// 定义绘图命令
#define CMD_QUIT 'q'
#define CMD_LINE 'l'
#define CMD_RECTANGLE 'r'
#define CMD_CLEAR 'c'

// 定义绘图区域
char canvas[HEIGHT][WIDTH];

// 函数声明
void initializeCanvas();
void displayCanvas();
void drawLine(int x1, int y1, int x2, int y2, char brush);
void drawRectangle(int x1, int y1, int x2, int y2, char brush);
void clearCanvas();

int main()
{
  char cmd;
  int x1, y1, x2, y2;
  char brush;

  initializeCanvas();
  displayCanvas();

  printf("欢迎使用命令行画图工具!\n");
  printf("命令格式：\n");
  printf("  q - 退出\n");
  printf("  l x1 y1 x2 y2 c - 画线\n");
  printf("  r x1 y1 x2 y2 c - 画矩形\n");
  printf("  c - 清空画布\n");

  while (1)
  {
    printf("请输入命令：");
    scanf(" %c", &cmd);

    if (cmd == CMD_QUIT)
    {
      printf("退出命令行画图工具。\n");
      break;
    }

    switch (cmd)
    {
    case CMD_LINE:
      scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &brush);
      drawLine(x1, y1, x2, y2, brush);
      break;

    case CMD_RECTANGLE:
      scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &brush);
      drawRectangle(x1, y1, x2, y2, brush);
      break;

    case CMD_CLEAR:
      clearCanvas();
      break;

    default:
      printf("无效的命令，请重新输入。\n");
      break;
    }

    displayCanvas();
  }

  return 0;
}

// 初始化绘图区域
void initializeCanvas()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      canvas[i][j] = ' ';
    }
  }
}

// 显示绘图区域
void displayCanvas()
{
  system("clear"); // 清空终端

  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf("%c", canvas[i][j]);
    }
    printf("\n");
  }
}

// 画线
void drawLine(int x1, int y1, int x2, int y2, char brush)
{
  for (int x = x1; x <= x2; x++)
  {
    for (int y = y1; y <= y2; y++)
    {
      if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
      {
        canvas[y][x] = brush;
      }
    }
  }
}

// 画矩形
void drawRectangle(int x1, int y1, int x2, int y2, char brush)
{
  drawLine(x1, y1, x2, y1, brush);
  drawLine(x1, y2, x2, y2, brush);
  drawLine(x1, y1, x1, y2, brush);
  drawLine(x2, y1, x2, y2, brush);
}

// 清空绘图区域
void clearCanvas()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      canvas[i][j] = ' ';
    }
  }
}
