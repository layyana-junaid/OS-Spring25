#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

void backup_directory(const char *source, const char *backup) {
    struct stat st;
    DIR *dir = opendir(source);
    struct dirent *entry;

    if (!dir) {
        printf("Error: Directory %s does not exist.\n", source);
        return;
    }

    mkdir(backup, 0777);

    int file_count = 0, dir_count = 0;
    while ((entry = readdir(dir)) != NULL) {
        char src_path[512], dest_path[512];
        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", backup, entry->d_name);

        if (stat(src_path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                char command[1024];
                snprintf(command, sizeof(command), "cp %s %s", src_path, dest_path);
                system(command);
                file_count++;
            } else if (S_ISDIR(st.st_mode) && entry->d_name[0] != '.') {
                mkdir(dest_path, 0777);
                backup_directory(src_path, dest_path);
                dir_count++;
            }
        }
    }
    closedir(dir);

    printf("Backup completed!\n");
    printf("Total files backed up: %d\n", file_count);
    printf("Total directories backed up: %d\n", dir_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char backup_folder[512];
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(backup_folder, sizeof(backup_folder), "backup_%Y%m%d_%H%M%S", tm_info);

    backup_directory(argv[1], backup_folder);

    return 0;
}
