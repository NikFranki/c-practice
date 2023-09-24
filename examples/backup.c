#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 备份源文件夹路径和目标文件夹路径
#define SOURCE_DIR "/path/to/source"
#define TARGET_DIR "/path/to/backup"

// 函数声明
void backupFiles();

int main()
{
  printf("欢迎使用定期备份程序!\n");

  while (1)
  {
    // 获取当前时间
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    // 每天的备份时间（假设是每天的凌晨2点）
    if (tm_info->tm_hour == 2 && tm_info->tm_min == 0)
    {
      backupFiles();
    }

    // 每隔一分钟检查一次
    sleep(60);
  }

  return 0;
}

// 备份文件夹内容
void backupFiles()
{
  char command[200];

  // 创建备份目标文件夹（如果不存在）
  mkdir(TARGET_DIR, 0755);

  // 使用rsync命令进行备份
  snprintf(command, sizeof(command), "rsync -av %s/ %s", SOURCE_DIR, TARGET_DIR);

  int result = system(command);

  if (result == 0)
  {
    printf("备份成功。\n");
  }
  else
  {
    printf("备份时出错。\n");
  }
}
