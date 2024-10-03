#include <fcntl.h>  // For open()
#include <unistd.h>  // For close()
#include <stdio.h>  // For printf()
#include "get_next_line.h"  // Include your header file

int main(void)
{
    int fd;
    char *line;

    // Open a file for reading
    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return (1);
    }

    // Reading multiple lines from the file using get_next_line
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Print the line read by get_next_line
        free(line);  // Don't forget to free the line after use
    }

    // Close the file
    close(fd);
    return (0);
}

