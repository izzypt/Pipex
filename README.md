# Pipex
The goal of this repo is to reproduce the behavior of the pipes in a bash shell using C. 

Not as parte of the Pipex project, but to integrate it within the Minishell.

Pipex focuses on three main concepts: pipelines, child processes and execution of commands.

https://reactive.so/42-a-comprehensive-guide-to-pipex


## WhiteListed Functions:

![image](https://github.com/izzypt/Pipex/assets/73948790/cb6cf7c8-4368-4fc1-a6b1-e9a7867ab4b2)
![image](https://github.com/izzypt/Pipex/assets/73948790/1f9fad82-c68f-4c98-a646-7fa7c23a5d14)
![image](https://github.com/izzypt/Pipex/assets/73948790/e9486474-3b6b-48fc-af33-60948c08c72a)
![image](https://github.com/izzypt/Pipex/assets/73948790/920e358f-64a0-42f1-a47d-01cf0115100a)
![image](https://github.com/izzypt/Pipex/assets/73948790/d1b100e3-28a3-429a-9a4a-61de949fd8fe)

The possible return values of the `access()` function are defined as preprocessor macros in the `<unistd.h>` header file. Here are the commonly used return values:

- **0**: This value indicates that the file or directory is accessible in the specified mode. It means the permissions allow the requested operation.

- **-1**: This value indicates that an error occurred while checking the accessibility of the file or directory. The specific error can be determined by checking the value of the `errno` variable. Common reasons for an error include the file or directory not existing, insufficient permissions to perform the check, or other system-specific issues.

The `access()` function accepts two arguments: the file path as a string and the desired mode as an integer. The mode argument specifies the type of access you want to check, such as readability, writability, or executability. Modes are represented by predefined constants, which are also declared in `<unistd.h>`. Here are some common mode constants:

- `R_OK`: Checks if the file or directory is readable.
- `W_OK`: Checks if the file or directory is writable.
- `X_OK`: Checks if the file or directory is executable.
- `F_OK`: Checks if the file or directory exists.

![image](https://github.com/izzypt/Pipex/assets/73948790/066cf522-0732-41e5-8049-f9ef786a20df)
![image](https://github.com/izzypt/Pipex/assets/73948790/fe6cd378-d193-414d-8225-f02c7bba4aad)
![image](https://github.com/izzypt/Pipex/assets/73948790/a453ec07-732a-4243-b21e-0c2861a0c04a)



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
