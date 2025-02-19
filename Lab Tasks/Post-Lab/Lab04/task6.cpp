#include <iostream>
#include <unistd.h>
#include <signal.h>

void handle_alarm(int sig) {
    std::cout << "Alarm received, terminating program." << std::endl;
    exit(0);  
}

int main() {
    signal(SIGALRM, handle_alarm);
    alarm(5);

    for (int i = 1; i <= 5; ++i) {
        std::cout << "Message " << i << std::endl;
        sleep(1);  
    }

    pause();  

    return 0;

