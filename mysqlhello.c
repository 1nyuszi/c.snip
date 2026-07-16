#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

void finish_with_error(MYSQL *con);
void ping_db(MYSQL *con);
void print_last_pings(MYSQL *con);

int main() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    unsigned int ssl_mode = SSL_MODE_DISABLED;
    mysql_options(con, MYSQL_OPT_SSL_MODE, &ssl_mode);

    if (mysql_real_connect(con, "localhost", "nyuszi", "nyuszi", "mydatabase", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    ping_db(con);
    print_last_pings(con);

    mysql_close(con);
    exit(0);
}

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void ping_db(MYSQL *con) {
    if (mysql_query(con, "INSERT INTO pings (id) VALUES (NULL)")) {
        finish_with_error(con);
    }
}

void print_last_pings(MYSQL *con) {
    if (mysql_query(con, "SELECT `time` FROM pings ORDER BY id DESC LIMIT 10")) {
        finish_with_error(con);
    }
    
    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}
