#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// 回调函数，用于处理HTTP响应
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userptr)
{
  size_t total_size = size * nmemb;
  FILE *output = (FILE *)userptr;
  if (output)
  {
    fwrite(contents, 1, total_size, output);
  }
  return total_size;
}

int main()
{
  CURL *curl;
  CURLcode res;

  // 设置要爬取的网页URL
  const char *url = "https://www.runoob.com";

  // 初始化libcurl
  curl = curl_easy_init();
  if (!curl)
  {
    fprintf(stderr, "libcurl 初始化失败\n");
    return 1;
  }

  // 打开文件以存储爬取的数据
  FILE *output_file = fopen("output.html", "w");
  if (!output_file)
  {
    fprintf(stderr, "无法创建输出文件\n");
    curl_easy_cleanup(curl);
    return 1;
  }

  // 设置libcurl选项
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, output_file);

  // 执行HTTP请求
  res = curl_easy_perform(curl);

  // 检查HTTP请求是否成功
  if (res != CURLE_OK)
  {
    fprintf(stderr, "HTTP请求失败: %s\n", curl_easy_strerror(res));
  }
  else
  {
    printf("网页爬取成功，数据已存储到output.html\n");
  }

  // 清理资源
  curl_easy_cleanup(curl);
  fclose(output_file);

  return 0;
}
