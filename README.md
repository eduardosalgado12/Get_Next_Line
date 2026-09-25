*This project has been created as part of the 42 curriculum by edsalgad.*

## Description
The **get_next_line** project is a fundamental challenge at 42 that involves creating a function in C capable of reading a line from a file descriptor. The main goal is to understand how memory allocation works in the heap, how to manage buffers efficiently, and how to use static variables to preserve data between successive function calls. This function is essential for future projects where parsing files line-by-line is required.

## Instructions

### Compilation
To compile the project, you should include the source files and define the `BUFFER_SIZE`. For example:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c
```

### Execution
After compilation, run the resulting executable. Ensure you have a file to read or redirect input:
```bash
./a.out < filename.txt
```
## Algorithm Explanation
The algorithm follows a **read-and-stash** strategy using a static variable to maintain state between calls.

- **Logic:** 
    1. It reads from the file descriptor in chunks of `BUFFER_SIZE` until a newline character (`\n`) or EOF is found.
    2. The data is appended to a static "leftover" string.
    3. Once a newline is found, the function extracts the portion of the string up to the `\n` to return as the current line.
    4. The remaining content (after the `\n`) is saved back into the static variable for the next call.
- **Justification:** This approach is chosen because the `read()` system call does not know where a line ends. By using a static variable, we ensure that any data read beyond the first newline is not lost and remains accessible for subsequent calls, which is the only way to achieve line-by-line reading without skipping content.

### Resources

*   **Static Variables:** Used to preserve data between function calls. This allows `get_next_line` to "remember" what was left in the buffer from the previous read.
*   **Memory Management:** The project requires careful use of `malloc` and `free` to prevent memory leaks, especially when concatenating buffers or trimming strings.
*   **File Descriptors:** Deep dive into how the system reads files and the behavior of the `read()` function.

### AI Usage
*   **Tasks:** Debugging memory allocation logic and assisting in the structuring and translation of the documentation.
*   **Parts of the project:** AI was used to verify the edge cases of the `ft_strjoin` function and to help draft the technical justifications in this README.

## Mandatory Part

The function must return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL`. The function should work as expected both when reading a file and when reading from the standard input.

## Bonus Part

The bonus version of this project includes:
*   Managing multiple file descriptors at the same time. For example, you can call `get_next_line` on FD 3, then FD 4, then FD 5, and finally FD 3 again without losing the reading thread of any of them.
*   Using only one static variable.
