#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {

int fd;
char buffer[100];

fd = open(FIFO_FILE, O_RDONLY);
read(fd, buffer, sizeof(buffer));
close(fd);

printf("Consumer Recieved: %s\n", buffer);

return 0;

}
