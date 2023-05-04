#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <pwd.h>

char* username;

void secret() {
    printf("Congratulations, %s! You have discovered the secret message.\n", username);
}

void greet(char *name) {
    char buf[12];
    strcpy(buf, name);
    printf("Hello, %s!\n", buf);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    struct passwd* userInfo = getpwuid(getuid());
    username = userInfo->pw_name;
    greet(argv[1]);
    return 0;
}
