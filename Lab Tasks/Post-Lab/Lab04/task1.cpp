#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{   
   pid_t child1, child2;
   
  child1 = fork(); // first child process
  if (child1 == 0) { 
  std::cout << "Child 1 PID: " << getpid() << std::endl;
  return 0;
}
 
 child2 = fork(); // second child process
 if(child2 == 0) {
 std::cout << "Child 2 PPID: " << getppid() << std::endl;
 return 0;
}

//parent waits for both the children to terminate
wait(NULL);
wait(NULL);

std::cout << "Parent Process Ending" << std::endl;
return 0;
}
