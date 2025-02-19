#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() 
{
int input_file = open("input.txt", O_RDONLY);

if(input_file ==  -1)
{
std::cerr <<"Error opening input file!"<< strerror(errno) << std::endl;
return 1;
}

int output_file = open("output.txt",O_WRONLY|O_CREAT|O_TRUNC, 0644);
if(output_file == -1)
{
std::cerr << "Error opening output file!" << strerror(errno) << std::endl;
close(input_file);

return 1;
}

char buffer[BUFFER_SIZE];
ssize_t bytes_read;

while((bytes_read = read(input_file, buffer, sizeof(buffer))) > 0)
{
write(output_file, buffer, bytes_read);
}

close(input_file);
close(output_file);
std::cout << "File copied successfully!" << std::endl;
return 0;
}

