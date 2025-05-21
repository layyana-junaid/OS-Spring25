#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

FILE *temp_file = NULL;
char *temp_filename = NULL;

void cleanup(int sig) {
    if (temp_file != NULL) {
        fclose(temp_file);
        temp_file = NULL;
    }
    
    if (temp_filename != NULL) {
        remove(temp_filename);
        printf("Cleanup complete: Temporary file '%s' deleted.\n", temp_filename);
        free(temp_filename);
        temp_filename = NULL;
    }
    
    exit(0);
}

int main() {
    // Set up signal handler
    signal(SIGINT, cleanup);
    
    // Create temporary file
    temp_filename = strdup("/tmp/tempfile_XXXXXX");
    int fd = mkstemp(temp_filename);
    if (fd == -1) {
        perror("Failed to create temporary file");
        return 1;
    }
    
    temp_file = fdopen(fd, "w");
    if (temp_file == NULL) {
        perror("Failed to open temporary file");
        close(fd);
        return 1;
    }
    
    printf("Created temporary file: %s\n", temp_filename);
    printf("Press Ctrl+C to stop and clean up...\n");
    
    int counter = 0;
    while (1) {
        fprintf(temp_file, "Data entry %d\n", counter++);
        fflush(temp_file);  // Ensure data is written immediately
        sleep(1);
    }
    
    return 0;
}
