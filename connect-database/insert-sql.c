#include <stdio.h>
#include <mysql.h>
// #include "/usr/local/mysql-8.0.28-macos11-x86_64/include/mysql.h"
#include <string.h>

int main(int argc, char* argv[])
{
  MYSQL *conn;
  MYSQL *res;
  MYSQL_ROW row;

  char* server = "localhost";
  char* user = "root";
  char* password = "12345678";
  char* database = "student";
  char query[200];
  int t, r;
  FILE *fp;

  if (argc != 3)
  {
    printf("error args\n");
    return -1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    perror("fopen");
    return -1;
  }

  char name[30];
  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
  {
    printf("Error connecting to database%s\n", mysql_error(conn));
  }
  else
  {
    printf("Connected...\n");
  }

  char people[20];
  strcpy(people, argv[2]);
  while (memset(name, 0, sizeof(name)), fgets(name, sizeof(name), fp) != NULL)
  {
    name[strlen(name)-1] = '\0';
    memset(query, 0, sizeof(query));
    sprintf(query,"%s%s%s%s%s","insert into class(code,name) values('",name,"','",people,"')");
    puts(query);
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query: %s\n", mysql_error(conn));
      break;
    }
    else
    {
      printf("insert success\n");
    }
  }

  fclose(fp);

  mysql_close(conn);

  return 0;
}