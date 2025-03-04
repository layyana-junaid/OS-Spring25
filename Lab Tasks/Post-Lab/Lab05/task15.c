#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    fd = open("input.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

  bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        close(fd);
        return 1;
    } else if (pid == 0) {
        const char *new_content = "Processed by child process\n";
        write(fd, new_content, sizeof(new_content));
        close(fd);

        execlp("cat", "cat", "input.txt", NULL);

        perror("execlp failed");
        return 1;
    } else {
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    close(fd);
    return 0;
}
