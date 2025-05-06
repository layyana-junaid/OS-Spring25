#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught SIGINT signal using sigaction!\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Program running with sigaction. Press Ctrl+C...\n");
    
    while(1) {
        sleep(1);
    }
    
    return 0;
}
