#include <stdio.h>
#include <mysql.h>

int main(void)
{
  MYSQL *conn;

  char* server = "localhost";
  char* user = "root";
  char* password = "12345678";
  char* database = "student";
  char* query = "update class set name='dada' where code='2'";

  int t, r;

  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
  {
    printf("Error connecting to database: %s\n", mysql_error(conn));
    return -1;
  }
  else
  {
    printf("Connected success...\n");
  }

  t = mysql_query(conn, query);
  if (t)
  {
    printf("Error making query: %s\n", mysql_error(conn));
  }
  else
  {
    printf("update success\n");
  }

  mysql_close(conn);

  return 0;
}