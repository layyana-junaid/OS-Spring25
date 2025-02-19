#include <iostream>
#include <unistd.h>
#include <sys/types.h>


int main()
{

std::cout << "Current Process ID (PID):  " << getpid() << std::endl;
std::cout << "Parent Process ID (PPID): " << getpid() << std::endl;
std::cout << "User ID (UID): " << getuid() << std::endl;

return 0;
}
