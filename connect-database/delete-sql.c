#include <stdio.h>
#include <mysql.h>

int main(void)
{
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char* server = "localhost";
  char* user = "root";
  char* password = "12345678";
  char* database = "student";
  char* query = "delete from class where name = 'franki'";

  int t, r;

  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
  {
    printf("Error connecting to database: %s\n", mysql_error(conn));
  }
  else
  {
    printf("Connected...\n");
  }

  t = mysql_query(conn, query);
  if (t)
  {
    printf("Error making query: %s\n", mysql_error(conn));
  }
  else
  {
    printf("delete success\n");
  }

  mysql_close(conn);

  return 0;
}