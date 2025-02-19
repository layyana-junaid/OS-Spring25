#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }
    
    if (pid == 0) {
       
        std::cout << "Child process: Listing current directory contents:" << std::endl;
        if (system("ls") == -1) {
            std::cerr << "Error listing directory." << std::endl;
        }
    } else {
     
        std::cout << "Parent process: Waiting for child to finish..." << std::endl;
        wait(NULL);  
        std::cout << "Parent process: Child terminated." << std::endl;
    }

    return 0;
}
