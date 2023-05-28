# Pipex
The goal of this repo is to reproduce the behavior of the pipes in a bash shell using C.

Pipex focuses on three main concepts: pipelines, child processes and execution of commands.

https://reactive.so/42-a-comprehensive-guide-to-pipex


Pipe() function :

In C programming, the `pipe()` function is used to create a communication channel (a pipe) between two related processes. 

It allows one process to send data to another process, typically in a parent-child relationship or between sibling processes.

The `pipe()` function creates a pair of file descriptors, represented as integers, where one descriptor is for the read end of the pipe and the other descriptor is for the write end of the pipe. The read end is used for reading data from the pipe, while the write end is used for writing data into the pipe.

Here's the prototype of the `pipe()` function:

```c
#include <unistd.h>

int pipe(int pipefd[2]);
```

The `pipe()` function takes a single argument: 
- An integer array `pipefd` of size 2. 
- `pipefd[0]` will refer to the read end of the pipe
- `pipefd[1]` will refer to the write end of the pipe.

To use `pipe()`, you typically fork a new process, and the parent and child processes can then communicate through the pipe by reading from and writing to the file descriptors returned by `pipe()`.

Here's an example usage of `pipe()`:

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buffer[20];
    pipe(pipefd);

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the write end of the pipe in the child
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);  // Close the read end of the pipe in the child
    } else {
        // Parent process
        close(pipefd[0]);  // Close the read end of the pipe in the parent
        write(pipefd[1], "Hello, child!", 13);
        close(pipefd[1]);  // Close the write end of the pipe in the parent
    }

    return 0;
}
```

In this example, the parent process writes the string "Hello, child!" to the pipe, and the child process reads it and prints it. The `close()` calls are used to close the unused ends of the pipe in each process to avoid resource leaks.

Note that error handling for `pipe()` and other system calls is omitted in this example for simplicity. In a real-world program, you should check the return values of system calls for possible errors.


============================================================================================

exclp function():

In C programming, the `execlp()` function is used to replace the current process with a new process specified by the given command. It allows you to execute a program by providing its name along with a list of arguments, similar to using the command-line interface.

The `execlp()` function is part of the `exec` family of functions in C, which are used for process execution. 
The `execlp()` function is specifically used when you want to specify the program to be executed by its name, and you want to search for the program in the directories listed in the `PATH` environment variable.

Here's the prototype of the `execlp()` function:

```c
#include <unistd.h>

int execlp(const char *file, const char *arg0, ... /* (char *) NULL */);
```

The `file` argument specifies the name of the program to be executed. The `arg0` and subsequent arguments represent the command-line arguments passed to the program. The list of arguments should be terminated with a `(char *) NULL`.

When `execlp()` is called, the current process is replaced by the new process. If the execution is successful, the code after the `execlp()` function call is not executed.

Here's an example usage of `execlp()` to execute the `ls` command:

```c
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-l", NULL);
    
    // Code after execlp() is not executed if the execution is successful
    
    return 0;
}
```

In this example, the `execlp()` function is used to execute the `ls` command with the `-l` option. The first argument `"ls"` specifies the program name, followed by the command-line arguments `"ls"` and `"-l"`. The `NULL` terminator indicates the end of the argument list.

After the `execlp()` function call, the current process is replaced by the `ls` command, which lists the files and directories in the current directory in long format.

It's important to note that if `execlp()` returns, it means there was an error in executing the specified program. In such cases, you can check the return value of `execlp()` for an error indication. The function returns -1 on error, and `errno` is set to indicate the specific error condition.

================================================================

execve() executes the program referred to by pathname.  This
       causes the program that is currently being run by the calling
       process to be replaced with a new program, with newly initialized
       stack, heap, and (initialized and uninitialized) data segments.

       pathname must be either a binary executable

================================================================

The `fork()` function in C is used to create a new process by duplicating the existing process. 

When `fork()` is called, it creates a new process that is an exact copy of the calling process, including the code, data, and stack.


1. The `fork()` function is called by a parent process, and it returns a value: 
  - If the value is 0, it means that the current process is the newly created child process. 
  - If the value is positive, it represents the process ID (PID) of the child process, and the current process is the parent process.
  - If the value is negative, it means that an error occurred during the creation of the new process. 

2. After the `fork()` call, two separate processes are running in parallel: 
  - The parent process and the child process. 
  - The child process is an exact copy of the parent process, and both processes continue execution from the point immediately after the `fork()` call.

3. The child process receives a copy of the parent process's memory, including variables, file descriptors, and other resources. However, the child process has its own unique process ID (PID).

4. Since the child process is a copy of the parent process, any changes made in one process do not affect the other process. Each process has its own execution flow and can perform different tasks.

5. The `fork()` function allows for the creation of complex processes and process hierarchies. For example, a parent process can create multiple child processes using multiple `fork()` calls, resulting in a tree-like structure.

6. It's important to note that the order of execution between the parent and child processes is not predetermined. The operating system scheduler determines the order in which processes are executed.

Overall, `fork()` is a powerful function in C that allows for process creation and parallel execution, enabling concurrent programming and multitasking.
