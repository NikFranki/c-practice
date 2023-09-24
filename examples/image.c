#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("用法: %s <图像文件名>\n", argv[0]);
    return -1;
  }

  // 加载图像
  Mat image = imread(argv[1], IMREAD_COLOR);

  if (!image.data)
  {
    printf("无法加载图像: %s\n", argv[1]);
    return -1;
  }

  // 显示原始图像
  namedWindow("原始图像", WINDOW_AUTOSIZE);
  imshow("原始图像", image);

  // 图像处理示例：将图像调整为灰度
  Mat grayImage;
  cvtColor(image, grayImage, COLOR_BGR2GRAY);

  // 显示处理后的图像
  namedWindow("灰度图像", WINDOW_AUTOSIZE);
  imshow("灰度图像", grayImage);

  // 保存处理后的图像
  imwrite("processed_image.jpg", grayImage);

  // 等待用户按下任意键退出
  waitKey(0);
  return 0;
}
