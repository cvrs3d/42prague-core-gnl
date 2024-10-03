#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
#include <stdio.h>   // For printf()
#include <stdlib.h>  // For free()
#include "../get_next_line.h"  // Include your header file

void test_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    char *line;

    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    printf("<<<<<<<<<<TESTING FILE: %s>>>>>>>>>>\n", filename);
    printf("<<<<<<<<<<BUFFER_SIZE = %d>>>>>>>>>>>>\n", BUFFER_SIZE);
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Print the line read by get_next_line
        free(line);  // Don't forget to free the line after use
    }
    
    // After finishing reading the file
    free(line); // In case get_next_line returned NULL
    close(fd);
}

int main(void) {
    // Test a normal file with multiple lines
    test_file("testfile.txt");
    
    // Test an empty file
    test_file("emptyfile.txt");
    
    // Test a file with a single line
    test_file("singleline.txt");
    
    // Test a file with multiple empty lines
    test_file("multiple_empty_lines.txt");

    // Test a file with only one long line
    test_file("long_line.txt");

    // Test a file with no newline at the end
    test_file("no_newline_at_end.txt");

    // Test a file with varying line lengths
    test_file("varying_lengths.txt");

    // Test an invalid file descriptor
    printf("<<<<<<<<<TESTING INVALID FD>>>>>>>>>>>>\n");
    char *line = get_next_line(-1);
    printf("Output: %s | Expected: NULL\n", line ? line : "NULL");
    free(line);

    return 0;
}

