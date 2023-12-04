#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>


void createDirectory(const char *directoryName)
{
    if (mkdir(directoryName, 0777) == 0)
    {
        printf("Directory '%s' created successfully.\n", directoryName);
    }
    else
    {
        printf("Failed to create directory '%s'. It may already exist or there might be a permission issue.\n", directoryName);
    }
}


void listDirectories(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) != NULL)
    {
        printf("Directories in '%s':\n", path);
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 &&
                strcmp(entry->d_name, "..") != 0)
            {
                printf("%s\n", entry->d_name);
                char subpath[256];
                snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
                listDirectories(subpath);
            }
        }
        closedir(dir);
    }
    else
    {
        printf("Error opening directory '%s'.\n", path);
    }
}

void deleteDirectory(const char *directoryName)
{
    if (rmdir(directoryName) == 0)
    {
        printf("Directory '%s' deleted successfully.\n", directoryName);
    }
    else
    {
        printf("Failed to delete directory '%s'.\n", directoryName);
    }
}

int main() { 
    int choice; 
    char dirName[100]; 
    char path[200]; 
 
    while (1) { 
        printf("\n1. Create Directory\n"); 
        printf("2. List Directories\n"); 
        printf("3. Delete Directory\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter directory path to create: "); 
                scanf("%s", dirName); 
                createDirectory(dirName); 
                break; 
            case 2: 
                printf("Enter directory path to list: "); 
                scanf("%s", path);
                listDirectories(path); 
                break; 
            case 3: 
                printf("Enter directory name to delete: "); 
                scanf("%s", dirName); 
                deleteDirectory(dirName); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } 
 
    return 0; 
} 