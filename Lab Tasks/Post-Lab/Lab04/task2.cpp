#include <iostream>
#include <unistd.h>

int main()
{
  pid_t pid = fork();

 if(pid == 0) 
 {
  //child proces
   for(int i = 0; i < 100; i++)
  {
    std::cout << "I am a child process" << std::endl;
   } 
 }
 else 
 {
    for(int i = 0; i < 100; i++)
   {
    std::cout << "I am a parent process" << std::endl;
   }
  }

return 0;

}

