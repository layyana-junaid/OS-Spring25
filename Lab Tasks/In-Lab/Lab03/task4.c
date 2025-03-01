#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_or_directory>\n", argv[0]);
        return 1;
    }

    struct stat info;
    if (stat(argv[1], &info) == 0) {
        if (S_ISREG(info.st_mode)) {
            printf("%s is a regular file.\n", argv[1]);
        } else if (S_ISDIR(info.st_mode)) {
            printf("%s is a directory.\n", argv[1]);
        } else {
            printf("%s is neither a regular file nor a directory.\n", argv[1]);
        }
    } else {
        printf("Error: %s does not exist.\n", argv[1]);
    }

    return 0;
}
