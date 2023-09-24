#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define CHUNK_SIZE 16384 // 压缩块的大小

int compressFile(const char *sourceFileName, const char *destFileName)
{
  FILE *sourceFile = fopen(sourceFileName, "rb");
  if (!sourceFile)
  {
    printf("无法打开源文件。\n");
    return 1;
  }

  FILE *destFile = fopen(destFileName, "wb");
  if (!destFile)
  {
    printf("无法创建目标文件。\n");
    fclose(sourceFile);
    return 1;
  }

  z_stream stream;
  memset(&stream, 0, sizeof(stream));

  if (deflateInit(&stream, Z_BEST_COMPRESSION) != Z_OK)
  {
    printf("初始化压缩流失败。\n");
    fclose(sourceFile);
    fclose(destFile);
    return 1;
  }

  unsigned char in[CHUNK_SIZE];
  unsigned char out[CHUNK_SIZE];

  stream.next_out = out;
  stream.avail_out = sizeof(out);

  do
  {
    stream.next_in = in;
    stream.avail_in = fread(in, 1, sizeof(in), sourceFile);
    if (ferror(sourceFile))
    {
      printf("读取源文件时出错。\n");
      deflateEnd(&stream);
      fclose(sourceFile);
      fclose(destFile);
      return 1;
    }

    int flush = feof(sourceFile) ? Z_FINISH : Z_NO_FLUSH;
    if (deflate(&stream, flush) == Z_STREAM_ERROR)
    {
      printf("压缩时出错。\n");
      deflateEnd(&stream);
      fclose(sourceFile);
      fclose(destFile);
      return 1;
    }

    fwrite(out, 1, sizeof(out) - stream.avail_out, destFile);
  } while (stream.avail_out == 0);

  deflateEnd(&stream);
  fclose(sourceFile);
  fclose(destFile);

  printf("文件压缩成功。\n");
  return 0;
}

int decompressFile(const char *sourceFileName, const char *destFileName)
{
  FILE *sourceFile = fopen(sourceFileName, "rb");
  if (!sourceFile)
  {
    printf("无法打开源文件。\n");
    return 1;
  }

  FILE *destFile = fopen(destFileName, "wb");
  if (!destFile)
  {
    printf("无法创建目标文件。\n");
    fclose(sourceFile);
    return 1;
  }

  z_stream stream;
  memset(&stream, 0, sizeof(stream));

  if (inflateInit(&stream) != Z_OK)
  {
    printf("初始化解压缩流失败。\n");
    fclose(sourceFile);
    fclose(destFile);
    return 1;
  }

  unsigned char in[CHUNK_SIZE];
  unsigned char out[CHUNK_SIZE];

  stream.next_out = out;
  stream.avail_out = sizeof(out);

  do
  {
    stream.next_in = in;
    stream.avail_in = fread(in, 1, sizeof(in), sourceFile);
    if (ferror(sourceFile))
    {
      printf("读取源文件时出错。\n");
      inflateEnd(&stream);
      fclose(sourceFile);
      fclose(destFile);
      return 1;
    }

    if (stream.avail_in == 0)
    {
      break;
    }

    int ret = inflate(&stream, Z_NO_FLUSH);
    if (ret == Z_NEED_DICT || ret == Z_DATA_ERROR || ret == Z_MEM_ERROR)
    {
      printf("解压缩时出错。\n");
      inflateEnd(&stream);
      fclose(sourceFile);
      fclose(destFile);
      return 1;
    }

    fwrite(out, 1, sizeof(out) - stream.avail_out, destFile);
  } while (stream.avail_out == 0);

  inflateEnd(&stream);
  fclose(sourceFile);
  fclose(destFile);

  printf("文件解压成功。\n");
  return 0;
}

int main()
{
  int choice;
  char sourceFileName[100];
  char destFileName[100];

  printf("欢迎使用文件压缩器/解压缩器!\n");

  printf("请选择操作:\n");
  printf("1. 压缩文件\n");
  printf("2. 解压文件\n");
  scanf("%d", &choice);

  printf("请输入源文件名: ");
  scanf("%s", sourceFileName);

  printf("请输入目标文件名: ");
  scanf("%s", destFileName);

  if (choice == 1)
  {
    if (compressFile(sourceFileName, destFileName) == 0)
    {
      printf("压缩完成。\n");
    }
    else
    {
      printf("压缩失败。\n");
    }
  }
  else if (choice == 2)
  {
    if (decompressFile(sourceFileName, destFileName) == 0)
    {
      printf("解压完成。\n");
    }
    else
    {
      printf("解压失败。\n");
    }
  }
  else
  {
    printf("无效的选择。\n");
  }

  return 0;
}
