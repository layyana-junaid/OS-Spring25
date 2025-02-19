#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
 pid_t pid = fork();

 if (pid == 0) 
 {
 execlp("ls", "ls", "-l", NULL);
 perror("execlp failed");

 return 1;
 }

 else 
 {
 wait(NULL);
 std::cout << "Parent process finished waiting." << std::cout;
 }

 return 0;

}
