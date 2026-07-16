#include <stdio.h>
#include <string.h>

char *environ_lookup(char *key_name, char *envp[]);

int main(int argc, char *argv[], char * envp[]) {
    printf("APPDATA: %s\n", environ_lookup("APPDATA=", envp));
    printf("COMPUTERNAME: %s\n", environ_lookup("COMPUTERNAME=", envp));
    printf("PROCESSOR_ARCHITECTURE: %s\n", environ_lookup("PROCESSOR_ARCHITECTURE=", envp));
    printf("Path: %s\n", environ_lookup("Path=", envp));
    printf("MYSQL_HOST: %s\n", environ_lookup("MYSQL_HOST=", envp));
    printf("MYSQL_PORT: %s\n", environ_lookup("MYSQL_PORT=", envp));
    printf("MYSQL_DEFAULT_DATABASE: %s\n", environ_lookup("MYSQL_DEFAULT_DATABASE=", envp));
    printf("MYSQL_DEFAULT_USER: %s\n", environ_lookup("MYSQL_DEFAULT_USER=", envp));
    printf("MYSQL_DEFAULT_PASSWORD: %s\n", environ_lookup("MYSQL_DEFAULT_PASSWORD=", envp));
    printf("ROZI: %s\n", environ_lookup("ROZI=", envp));
    return 0;
}

char *environ_lookup(char *key_name, char *envp[]) {
    for(int i=0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], key_name, strlen(key_name)) == 0) {
            return envp[i] + strlen(key_name);
        }
    }
    return NULL;
}