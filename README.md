# Get Next Line

![Get Next Line](https://img.shields.io/badge/GetNextLine-C%20Project-blue)

## Description

The `get_next_line` function reads a specified amount of data (default `BUFFER_SIZE` of 42 bytes) from the file pointed to by a file descriptor. It seeks for the newline character (`'\n'`) in the content it reads or EOF and then returns the line terminated with `'\n'`. If that was the last line of the file, the newline character is returned only if it was present at the end.

All returned strings are null-terminated, making them classic C-strings. The buffer is static, allowing it to persist through all program routines until the very last return.

## Bonus Description

The bonus functionality retains the same behavior but supports multiple file descriptors. To achieve this, the function utilizes linked lists, where each node stores a pointer to the buffer and the file descriptor.

## How to Install

Simply clone this repository and build it using the provided Makefile:

```bash
git clone <repository-url>
cd <repository-directory>
make
