#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "a");
    if (file == NULL) {
        printf("Error: File %s does not exist.\n", argv[1]);
        return 1;
    }

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char date_time[30];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(file, "%s\n", date_time);
    fclose(file);
    
    printf("Date and time appended to %s\n", argv[1]);
    return 0;
}
