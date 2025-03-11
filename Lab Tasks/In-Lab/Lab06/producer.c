#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>
#include<string.h>

#define FIFO_FILE "myfifo"

int main() {

int fd;
char message[] = "Producer here!";

//create a fifo file 
mkfifo(FIFO_FILE, 0666);

//open fifo for writing 
fd = open(FIFO_FILE, O_WRONLY);
write(fd, message, strlen(message) + 1);
close(fd);

return 0;

}
