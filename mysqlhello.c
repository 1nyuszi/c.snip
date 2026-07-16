#include <stdio.h>
#include <mysql.h>

int main() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "nyuszi", "nyuszi", NULL, 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    exit(0);
}