#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void proc_exit() {
    int status;
    pid_t pid;
    
    while ((pid = wait3(&status, WNOHANG, NULL)) > 0) {
        printf("Child %d terminated\n", pid);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);
    
    if (fork() == 0) {
        printf("Child %d started\n", getpid());
        sleep(2);
        exit(0);
    }
    
    printf("Parent %d running\n", getpid());
    sleep(5);
    
    return 0;
}
