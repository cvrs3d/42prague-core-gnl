# Get Next Line

![Get Next Line](https://img.shields.io/badge/GetNextLine-C%20Project-blue)

## Description

The `get_next_line` function reads a specified amount of data (default `BUFFER_SIZE` of 42 bytes) from the file passed via file descriptor. It seeks for the newline character (`'\n'`) in the content it reads or EOF and then returns the line terminated with `'\n'`. Please note that the returned line include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

All returned strings are null-terminated, making them classic C-strings. The buffer is static, allowing it to persist through all program routine until the very last return.

## Bonus Description

The bonus functionality retains the same behavior but supports multiple file descriptors. To achieve this, the function utilizes linked lists, where each node stores a pointer to the buffer and the file descriptor.
For example the proper functionality of reading from 2 files, while changing file descriptors per call, whill appear like this.
Memory for each file descriptor is being freed when read syscall returns 0, allowing to avoid memory leaks.

```C
~ ./gnl_bonus_test file1.txt file2.txt    
Line: (file1):Hello, from file1;
Line: (file2):Hello from file2
Line: (file1):My buffer is persistent
Line: (file2):My reading stream is still there
Line: (file1):One more line
```

## How to Install

It has its own tests. To run them you will need to clone the repo first.
```cmd
git clone <this repo url> <any name of the new directory>
```
After you clone it move to the testing/ directory.
```cmd
cd  testing/
```
From there type make in order for simple version to compile.
```cmd
make
```
Simply run executable.
```cmd
./<by default: gnl_test>
```
For bonus part just run this.
```cmd
make bonus
```
To run the test pass 1 or more files into the program args, otherwise it will test for STDIN_FILENO.
```cmd
./<by default gnl_bonus_test> <file1.txt> <file2.txt> ...
```
