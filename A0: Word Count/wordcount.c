#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        if (argc > 2) {
            printf("Expected one argument, found %d: %s <filename>\n", (argc - 1), argv[0]);
            return -1;
        } else {
            printf("Usage: %s <filename>\n", argv[0]);
            return -1;
        }
    }

    int fd = open(argv[1], 0);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return -1;
    }

    int total, words, lines;
    total = words = lines = 0;

    char prevCharacter;
    char character;
    int bytes;
    while((bytes = read(fd, &character, sizeof(character))) > 0) {
        total++;

        if (character == '\n') {
            lines++;
        }

        if (isspace(character) && (total > 1)) {
            if (isprint(prevCharacter) && (!isspace(prevCharacter))) {
                words++;
            }
        }

        prevCharacter = character;
    }

    if (bytes == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        return -1;
    }

    if (total == 0) {
        lines = 0;
        total = 0;
        words = 0;
    } else {
        if (isprint(prevCharacter)) {
            lines++;
            if (!isspace(prevCharacter)) {
                words++;
            }
        }
    }

    printf("%d %d %d %s\n", lines, words, total, argv[1]);

    if (fd != -1 && close(fd) == -1) {
        printf("Error closing file: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}